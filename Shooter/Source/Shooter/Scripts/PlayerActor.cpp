// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/PlayerActor.h"

// Sets default values
APlayerActor::APlayerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerActor::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void APlayerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(PlayerPawn->GetActorLocation());
	FRotator PlayerYawRotation(0, PlayerPawn->GetControlRotation().Yaw, 0);
	SetActorRotation(PlayerYawRotation);

}

