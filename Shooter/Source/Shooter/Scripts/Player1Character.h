// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Shooter/Scripts/PlayerCharacter.h"
#include "Player1Character.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API APlayer1Character : public APlayerCharacter
{
	GENERATED_BODY()

	const float centerHeightOffset = 45;

	const float maxHealth = 100;
	
public:
	// Sets default values for this character's properties
	APlayer1Character();

protected:

public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
