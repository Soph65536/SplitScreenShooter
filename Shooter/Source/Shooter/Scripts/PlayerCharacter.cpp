// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/PlayerCharacter.h"
#include "Shooter/Scripts/Bullet.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

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

void APlayerCharacter::Shoot() {
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = this;

	ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>(BulletBP, GetActorLocation(), GetControlRotation(), spawnParams);//!!!!!!!!change actor location to the camera/spring arm locations
	Cast<UStaticMeshComponent>(NewBullet->GetRootComponent())->AddForce(GetActorForwardVector() * shootForce); //get root component of bullet, cast it to mesh then add force to it
}