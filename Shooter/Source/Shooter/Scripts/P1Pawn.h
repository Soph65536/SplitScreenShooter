// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "P1Pawn.generated.h"

UCLASS()
class SHOOTER_API AP1Pawn : public APawn
{
	GENERATED_BODY()

	const float WalkSpeed = 200;
	const float RunSpeed = 300;

public:
	// Sets default values for this pawn's properties
	AP1Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool isRunning;
	float moveSpeed;

	void MoveHorizontal(float value);
	void MoveVertical(float value);

	void LookHorizontal(float value);
	void LookVertical(float value);

	void Running();
	void Walking();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
