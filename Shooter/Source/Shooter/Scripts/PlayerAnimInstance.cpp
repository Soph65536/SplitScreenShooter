// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/PlayerAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
}

void UPlayerAnimInstance::CustomUpdateAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
}