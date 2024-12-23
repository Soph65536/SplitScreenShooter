// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
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

	const float UIControlsVisibleTime = 20;

	const float centerHeightOffset = 45;

	const float maxAmmo = 30;
	const float maxHealth = 200;
	const float bodyDamage = 10;
	const float headDamage = 50;
	const float healAmount = 15;

	const float moveSpeed = 1000;
	const float jumpHeight = 0.5;
	const float shootForce = 40000;

	const FVector CameraBaseLocation = FVector(0, 0, 0);
	const FVector CameraAimLocation = FVector(250, 0, 0);

public:
	// Sets default values for this character's properties
	APlayerCharacter();


	//bullet reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ABullet> BulletBP;

	//spring arm component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm;

	//camera component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* CameraComp;

	//sounds
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* JumpSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* StartAimSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* StopAimSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* ShootSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* ReloadSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* DamageSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* HealSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* WinSound;


	//input functions
	void MoveHorizontal(float value);
	void MoveVertical(float value);

	void LookHorizontal(float value);
	void LookVertical(float value);

	void Jump();

	void StartAiming();
	void StopAiming();

	void Shoot();
	void Melee();


	//player damage and heal function
	void PlayerTakeDamage(bool shotHead);
	void PlayerHeal();


	//animation assets
	UPROPERTY(EditAnywhere)
		UAnimationAsset* MeleeAnim;
	UPROPERTY(EditAnywhere)
		UAnimationAsset* ReloadAnim;
	UPROPERTY(EditAnywhere)
		UAnimationAsset* DeathAnim;

	USkeletalMeshComponent* PlayerSMC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables C++")
		float horizontal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables C++")
		float vertical;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables C++")
		bool ownernoseeBPModify;


	//UI assets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI C++")
		UUserWidget* ControlsOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI C++")
		UUserWidget* LoseScreenOverlay; //when health 0 (lose) the other player wins

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI C++")
		UUserWidget* HUDOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI C++")
		UUserWidget* AimingOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI C++")
		UUserWidget* ReloadingOverlay;

	//ui bp variables
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI C++")
		float health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI C++")
		int ammo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//ammo stuff
	bool reloading;
	void ReloadAmmo();
	//close controls UI
	void CloseControls();
	//reset animation to blueprint after playing animation asset
	void ResetAnimationBP();
	//game ending
	void EndGame();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
