// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/PlayerCharacter.h"
#include "Shooter/Scripts/Bullet.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//autoposses the right player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//set health
	health = maxHealth;

	//make spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	//set spring arm properties
	SpringArm->SetRelativeLocation(FVector(0, 0, centerHeightOffset));
	SpringArm->TargetArmLength = 350;
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

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerCharacter::PlayerTakeDamage() {
	health--; //remove health
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::SanitizeFloat(health));
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
	
}


void APlayerCharacter::MoveHorizontal(float value) {
	FRotator YawRotation(0, GetControlRotation().Yaw, 0); //get yaw
	FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); //get leftright vector from yaw

	AddMovementInput(RightVector, value * moveSpeed, false);
}

void APlayerCharacter::MoveVertical(float value) {
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
}

void APlayerCharacter::StartAiming() {
	//CameraComp->SetRelativeLocation(CameraAimLocation);
	bFindCameraComponentWhenViewTarget = false;
}

void APlayerCharacter::StopAiming() {
	//CameraComp->SetRelativeLocation(CameraBaseLocation);
	bFindCameraComponentWhenViewTarget = true;
}

void APlayerCharacter::Shoot() {
	FVector BulletSpawnLocation = GetActorLocation() + FVector(0, 0, centerHeightOffset);
	FRotator BulletSpawnRotation = GetControlRotation();
	FVector BulletForwardVector = FRotationMatrix(BulletSpawnRotation).GetUnitAxis(EAxis::X);

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = this;

	ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>(BulletBP, FVector(0, 0, -100), BulletSpawnRotation, spawnParams); //spawn bullet in floor
	NewBullet->Player = this; //set the player var of the new bullet to this object
	NewBullet->SetActorLocation(BulletSpawnLocation); //set bullet's location after making sure the player var is set

	//if bullet exists
	if (NewBullet != nullptr) {
	//get root component of bullet, cast it to mesh then add force to it
	Cast<UStaticMeshComponent>(NewBullet->GetRootComponent())->AddForce(BulletForwardVector * shootForce); 
	}
}