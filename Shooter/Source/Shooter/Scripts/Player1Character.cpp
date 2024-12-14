// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/Player1Character.h"

// Sets default values
APlayer1Character::APlayer1Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//autoposses the right player
	AutoPossessPlayer = EAutoReceiveInput::Player1;

	//set health
	health = maxHealth;
}

// Called to bind functionality to input
void APlayer1Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("P1MovementHorizontal", this, &APlayerCharacter::MoveHorizontal);
	PlayerInputComponent->BindAxis("P1MovementVertical", this, &APlayerCharacter::MoveVertical);
	PlayerInputComponent->BindAxis("P1LookHorizontal", this, &APlayerCharacter::LookHorizontal);
	PlayerInputComponent->BindAxis("P1LookVertical", this, &APlayerCharacter::LookVertical);

	PlayerInputComponent->BindAction("P1Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAction("P1Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("P1Aim", IE_Pressed, this, &APlayerCharacter::StartAiming);
	PlayerInputComponent->BindAction("P1Aim", IE_Released, this, &APlayerCharacter::StopAiming);
	PlayerInputComponent->BindAction("P1Shoot", IE_Pressed, this, &APlayerCharacter::Shoot);

}