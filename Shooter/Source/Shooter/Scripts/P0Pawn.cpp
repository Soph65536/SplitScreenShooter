// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/P0Pawn.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AP0Pawn::AP0Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AP0Pawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AP0Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AP0Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("P0MovementHorizontal", this, &AP0Pawn::MoveHorizontal);
	PlayerInputComponent->BindAxis("P0MovementVertical", this, &AP0Pawn::MoveVertical);
	PlayerInputComponent->BindAxis("P0LookHorizontal", this, &AP0Pawn::LookHorizontal);
	PlayerInputComponent->BindAxis("P0LookVertical", this, &AP0Pawn::LookVertical);

	PlayerInputComponent->BindAction("P0Jump", IE_Pressed, this, &AP0Pawn::Jump);
	PlayerInputComponent->BindAction("P0Shoot", IE_Pressed, this, &AP0Pawn::Shoot);
}


void AP0Pawn::MoveHorizontal(float value) {
	FRotator YawRotation(0, GetControlRotation().Yaw, 0); //get yaw
	FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); //get leftright vector from yaw

	AddMovementInput(RightVector, value * moveSpeed, false);
}

void AP0Pawn::MoveVertical(float value) {
	FRotator YawRotation(0, GetControlRotation().Yaw, 0); // get yaw
	FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); //get forwardback vector from yaw

	AddMovementInput(ForwardVector, value * moveSpeed, false);
}

void AP0Pawn::LookHorizontal(float value) {
	AddControllerYawInput(value);
}

void AP0Pawn::LookVertical(float value) {
	AddControllerPitchInput(-value);
}

void AP0Pawn::Jump() {

}

void AP0Pawn::Shoot() {

}