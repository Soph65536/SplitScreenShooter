// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/PlayerCharacter.h"

#include "Blueprint/UserWidget.h"
#include "Shooter/Scripts/Bullet.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//turn off autopossession so we can manually possess in the character BP
	AutoPossessPlayer = EAutoReceiveInput::Disabled;

	//set variables
	reloading = false;
	
	health = maxHealth;
	ammo = maxAmmo;
	wins = 0;

	isDeathing = false;

	//set movespeed
	GetCharacterMovement()->MaxWalkSpeed = moveSpeed;

	//set skeletal mesh component
	PlayerSMC = FindComponentByClass<USkeletalMeshComponent>();
	ownernoseeBPModify = false; //set owner no see to false

	//make spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	//set spring arm properties
	SpringArm->SetRelativeLocation(FVector(0, 0, centerHeightOffset));
	SpringArm->TargetArmLength = 350;
	SpringArm->TargetOffset = FVector(-30, 0, 0);
	SpringArm->bUsePawnControlRotation = true;

	//make camera as spring arm child
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);
	
	//set camera properties
	CameraComp->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//add hud
	if (HUDOverlay) {
		HUDOverlay->AddToViewport();
		HUDOverlay->SetVisibility(ESlateVisibility::Visible);
	}

	//add aiming overlay for when player aims
	if (AimingOverlay) {
		AimingOverlay->AddToViewport();
		AimingOverlay->SetVisibility(ESlateVisibility::Hidden);
	}

	//add reloading overlay for when player is reloading
	if (ReloadingOverlay) {
		ReloadingOverlay->AddToViewport();
		ReloadingOverlay->SetVisibility(ESlateVisibility::Hidden);
	}

	//add win screen overlay for when this player wins
	if (LoseScreenOverlay) {
		LoseScreenOverlay->AddToViewport();
		LoseScreenOverlay->SetVisibility(ESlateVisibility::Hidden);
	}

	//add controls ui for a set time
	if (ControlsOverlay) {
		ControlsOverlay->AddToViewport();
		ControlsOverlay->SetVisibility(ESlateVisibility::Visible);

		//create a timer that calls closecontrols after certain time
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &APlayerCharacter::CloseControls, UIControlsVisibleTime, false);
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerCharacter::PlayerTakeDamage(bool shotHead) {
	//isdeathing var prevents endgame from being called multiple times and stops attacking during death
	if (!isDeathing) {
		health -= shotHead ? headDamage : bodyDamage; //remove health
		if (DamageSound) { UGameplayStatics::PlaySoundAtLocation(this, DamageSound, GetActorLocation()); } //play sound

		//endgame if player has died
		if (health <= 0) {
			isDeathing = true;
			health = 0;
			EndGame();
		}
	}
}

void APlayerCharacter::PlayerPickup(int WhichPickup) {
	switch (WhichPickup) {
	case 0:
		PlayerHealPickup();
		break;
	case 1:
		PlayerAmmoPickup();
		break;
	default:
		break;
	}
}


// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("P0MovementHorizontal", this, &APlayerCharacter::MoveHorizontal);
	PlayerInputComponent->BindAxis("P0MovementVertical", this, &APlayerCharacter::MoveVertical);
	PlayerInputComponent->BindAxis("P0LookHorizontal", this, &APlayerCharacter::LookHorizontal);
	PlayerInputComponent->BindAxis("P0LookVertical", this, &APlayerCharacter::LookVertical);

	PlayerInputComponent->BindAction("P0Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAction("P0Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("P0Aim", IE_Pressed, this, &APlayerCharacter::StartAiming);
	PlayerInputComponent->BindAction("P0Aim", IE_Released, this, &APlayerCharacter::StopAiming);

	PlayerInputComponent->BindAction("P0Shoot", IE_Pressed, this, &APlayerCharacter::Shoot);
	PlayerInputComponent->BindAction("P0Melee", IE_Pressed, this, &APlayerCharacter::Melee);
}


void APlayerCharacter::MoveHorizontal(float value) {
	horizontal = value;

	FRotator YawRotation(0, GetControlRotation().Yaw, 0); //get yaw
	FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); //get leftright vector from yaw

	AddMovementInput(RightVector, value * moveSpeed, false);
}

void APlayerCharacter::MoveVertical(float value) {
	vertical = value;

	FRotator YawRotation(0, GetControlRotation().Yaw, 0); // get yaw
	FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); //get forwardback vector from yaw

	AddMovementInput(ForwardVector, value * moveSpeed, false);
}

void APlayerCharacter::LookHorizontal(float value) {
	AddControllerYawInput(value);
}

void APlayerCharacter::LookVertical(float value) {
	AddControllerPitchInput(-value);
}

void APlayerCharacter::Jump() {
	JumpMaxHoldTime = jumpHeight;
	ACharacter::Jump();

	if (JumpSound) { UGameplayStatics::PlaySoundAtLocation(this, JumpSound, GetActorLocation()); } //play sound
}

void APlayerCharacter::StartAiming() {
	ownernoseeBPModify = true; //prevent player seeing inside smc
	bFindCameraComponentWhenViewTarget = false; //change camera comp to built in first person

	if (AimingOverlay) { AimingOverlay->SetVisibility(ESlateVisibility::Visible); } // ui overlay

	if (StartAimSound) { UGameplayStatics::PlaySoundAtLocation(this, StartAimSound, GetActorLocation()); } //play sound
}

void APlayerCharacter::StopAiming() {
	ownernoseeBPModify = false;
	bFindCameraComponentWhenViewTarget = true;

	if (AimingOverlay) { AimingOverlay->SetVisibility(ESlateVisibility::Hidden); } // ui overlay

	if (StopAimSound) { UGameplayStatics::PlaySoundAtLocation(this, StopAimSound, GetActorLocation()); } //play sound
}

void APlayerCharacter::Shoot() {
	if (!reloading) {
		FVector BulletSpawnLocation = GetActorLocation() + FVector(0, 0, centerHeightOffset);
		FRotator BulletSpawnRotation = GetControlRotation() + FRotator(0, -90, 0); //add rotation so model faces right way
		FVector BulletForwardVector = FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X);

		FActorSpawnParameters spawnParams;
		spawnParams.Owner = this;
		spawnParams.Instigator = this;

		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>(BulletBP, FVector(0, 0, -100), BulletSpawnRotation, spawnParams); //spawn bullet in floor
		NewBullet->Player = this; //set the player var of the new bullet to this object
		NewBullet->SetActorLocation(BulletSpawnLocation); //set bullet's location after making sure the player var is set

		//if bullet exists
		if (NewBullet) {
			//get root component of bullet, cast it to mesh then add force to it
			Cast<UStaticMeshComponent>(NewBullet->GetRootComponent())->AddForce(BulletForwardVector * shootForce);

			if (ShootSound) { UGameplayStatics::PlaySoundAtLocation(this, ShootSound, GetActorLocation()); } //play sound

			ammo--;
		}

		//check if need to reload
		if (ammo <= 0) {
			if (ReloadingOverlay) { ReloadingOverlay->SetVisibility(ESlateVisibility::Visible); } // ui overlay

			if (ReloadSound) { UGameplayStatics::PlaySoundAtLocation(this, ReloadSound, GetActorLocation()); } //play sound

			//animate reloading
			if (PlayerSMC) {
				PlayerSMC->PlayAnimation(ReloadAnim, false);
				//reanimate with bp after playing animation
				FTimerHandle UnusedHandle;
				GetWorldTimerManager().SetTimer(UnusedHandle, this, &APlayerCharacter::ResetAnimationBP, 2, false);
			}
			
			reloading = true;
			//create a timer that calls reload after 2secs
			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APlayerCharacter::ReloadAmmo, 2, false);
		}
	}
}

void APlayerCharacter::Melee() {
	//sweep linetrace params
	TArray<FHitResult> HitResults;
	FVector StartLocation = GetActorLocation() + FVector(0, 0, centerHeightOffset);
	FVector EndLocation = FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X) * 200 + StartLocation; //forward vector *200 + startlocation
	ECollisionChannel ECC = ECollisionChannel::ECC_PhysicsBody;
	
	//sweep linetrace shape
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Box;
	CollisionShape.SetBox(FVector3f(100, 10, 100));

	//list of names of players hit, starting with this 
	//to make sure doesnt attack self
	//and doesnt attack same character twice
	TArray<FString> HitCharacters;
	HitCharacters.Add(this->GetName());

	if (GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat(), ECC, CollisionShape)) {
		for (auto It = HitResults.CreateIterator(); It; It++) {
			APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>((*It).GetActor());

			if (PlayerCharacter != nullptr) { //check for player character
				if (!HitCharacters.Contains(PlayerCharacter->GetName())) { //check if hit before or self
					HitCharacters.Add(PlayerCharacter->GetName()); //add to characters hit
					PlayerCharacter->PlayerTakeDamage(false);
				}
			}
		}
	}

	//animate melee attack
	if (PlayerSMC) { 
		PlayerSMC->PlayAnimation(MeleeAnim, false); 
		//reanimate with bp after playing animation
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &APlayerCharacter::ResetAnimationBP, 1.5f, false);
	}
}


void APlayerCharacter::ReloadAmmo() {
	if (ReloadingOverlay) { ReloadingOverlay->SetVisibility(ESlateVisibility::Hidden); } // ui overlay

	reloading = false;
	ammo = maxAmmo;
}

void APlayerCharacter::CloseControls() {
	ControlsOverlay->SetVisibility(ESlateVisibility::Hidden);
}

void APlayerCharacter::ResetAnimationBP() {
	if (PlayerSMC) { PlayerSMC->SetAnimationMode(EAnimationMode::AnimationBlueprint); }
}

void APlayerCharacter::PlayerHealPickup() {
	//add health and cap at maxHealth
	health += healAmount;
	if (health > maxHealth) { health = maxHealth; }

	if (HealPickupSound) { UGameplayStatics::PlaySoundAtLocation(this, HealPickupSound, GetActorLocation()); } //play sound
}

void APlayerCharacter::PlayerAmmoPickup() {
	//add 20 ammo
	ammo += 20;

	if (AmmoPickupSound) { UGameplayStatics::PlaySoundAtLocation(this, AmmoPickupSound, GetActorLocation()); } //play sound
}

void APlayerCharacter::EndGame() {
	//show lose screen
	if (LoseScreenOverlay) {
		LoseScreenOverlay->SetVisibility(ESlateVisibility::Visible);
	}

	//add win to other player
	OtherPlayer->wins++;

	//play win sound
	if (WinSound) { UGameplayStatics::PlaySoundAtLocation(this, WinSound, GetActorLocation()); } //play sound

	//if skeletal mesh component exists, animate death
	if (PlayerSMC) {
		PlayerSMC->PlayAnimation(DeathAnim, false);
	}

	//if not last round then reset players after 2 seconds
	if (currentRound < 3) {
		currentRound++;
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &APlayerCharacter::ResetPlayers, 5, false);
	}
}

void APlayerCharacter::ResetPlayers() {
	//hide lose screen
	if (LoseScreenOverlay) {
		LoseScreenOverlay->SetVisibility(ESlateVisibility::Hidden);
	}

	//set positions
	SetActorLocation(PlayerStart);
	OtherPlayer->SetActorLocation(OtherPlayer->PlayerStart);

	//reset animation of this player since they just died animation
	ResetAnimationBP();

	//set variables
	reloading = false;
	OtherPlayer->reloading = false;

	health = maxHealth;
	OtherPlayer->health = maxHealth;
	ammo = maxAmmo;
	OtherPlayer->ammo = maxAmmo;

	//no longer isdeathing
	isDeathing = false;
}