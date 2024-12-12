// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Shooter/Scripts/Bullet.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SHOOTER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	const float centerHeightOffset = 45;

	const float maxHealth = 100;
	const float moveSpeed = 1;
	const float jumpHeight = 1;
	const float shootForce = 40000;

	const FVector CameraBaseLocation = FVector(0, 0, 0);
	const FVector CameraAimLocation = FVector(250, 0, 0);

public:
	// Sets default values for this character's properties
	APlayerCharacter();


	//bullet reference
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABullet> BulletBP;

	//spring arm component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm;

	//camera component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* CameraComp;


	//player damage function
	void PlayerTakeDamage();

	//animation assets
	UPROPERTY(EditAnywhere)
		UAnimationAsset* DeathAnim;

	USkeletalMeshComponent* PlayerSMC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CustomAnim")
		float horizontal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CustomAnim")
		float vertical;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//input functions
	void MoveHorizontal(float value);
	void MoveVertical(float value);

	void LookHorizontal(float value);
	void LookVertical(float value);

	void Jump();

	void StartAiming();
	void StopAiming();
	void Shoot();

	//game ending
	void EndGame();

	//player health
	float health;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
