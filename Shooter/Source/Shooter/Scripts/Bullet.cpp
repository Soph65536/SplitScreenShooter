// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/Bullet.h"
#include "Shooter/Scripts/PlayerCharacter.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create mesh and set as root component
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	RootComponent = BulletMesh;

	//mesh physics
	BulletMesh->SetSimulatePhysics(true);

	//mesh collision
	BulletMesh->SetGenerateOverlapEvents(true);
	BulletMesh->CanCharacterStepUpOn = ECB_No;
	BulletMesh->SetCollisionProfileName(TEXT("PawnOverlap"));

	//set lifespan
	InitialLifeSpan = 10;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	BulletMesh->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlapStart); //call onoverlapstart when mesh begins overlapping with something

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

	//check the overlap isnt with the player that shot this bullet
	if (PlayerCharacter != Player) {
		//take damage if it is hitting a player
		if (PlayerCharacter != nullptr) {
			bool hitHead = false; //bool for shothead parameter

			//check if overlapped component is head of player
			if (OtherComp->ComponentHasTag(TEXT("Head"))) { hitHead = true; }
			
			PlayerCharacter->PlayerTakeDamage(hitHead);
		}
		//destroy after overlapping with an object
		Destroy();
	}
}

