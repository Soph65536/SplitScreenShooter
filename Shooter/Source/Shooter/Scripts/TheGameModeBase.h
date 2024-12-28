// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TheGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API ATheGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		

public:
	UPROPERTY(BlueprintReadOnly)
		float RoundLengthSecs = 180;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RoundTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CurrentRound;
};
