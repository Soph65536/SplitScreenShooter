// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/P1Pawn.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AP1Pawn::AP1Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player1;

	moveSpeed = WalkSpeed;

}

// Called when the game starts or when spawned
void AP1Pawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AP1Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AP1Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("P1MovementHorizontal", this, &AP1Pawn::MoveHorizontal);
	PlayerInputComponent->BindAxis("P1MovementVertical", this, &AP1Pawn::MoveVertical);
	PlayerInputComponent->BindAxis("P1LookHorizontal", this, &AP1Pawn::LookHorizontal);
	PlayerInputComponent->BindAxis("P1LookVertical", this, &AP1Pawn::LookVertical);

	PlayerInputComponent->BindAction("P0Run", IE_Pressed, this, &AP1Pawn::Running);
	PlayerInputComponent->BindAction("P0Run", IE_Released, this, &AP1Pawn::Walking);
}

void AP1Pawn::MoveHorizontal(float value) {
	FRotator YawRotation(0, GetControlRotation().Yaw, 0); //get yaw
	FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); //get leftright vector from yaw

	AddMovementInput(RightVector, value * moveSpeed, false);
}

void AP1Pawn::MoveVertical(float value) {
	FRotator YawRotation(0, GetControlRotation().Yaw, 0); // get yaw
	FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); //get forwardback vector from yaw

	AddMovementInput(ForwardVector, value * moveSpeed, false);
}

void AP1Pawn::LookHorizontal(float value) {
	AddControllerYawInput(value);
}

void AP1Pawn::LookVertical(float value) {
	AddControllerPitchInput(-value);
}

void AP1Pawn::Running() { moveSpeed = RunSpeed; }
void AP1Pawn::Walking() { moveSpeed = WalkSpeed; }


