// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter/Scripts/Pickup.h"
#include "Shooter/Scripts/PlayerCharacter.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create mesh and set as root component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	RootComponent = PickupMesh;

	//mesh collision
	PickupMesh->SetGenerateOverlapEvents(true);
	PickupMesh->CanCharacterStepUpOn = ECB_No;
	PickupMesh->SetCollisionProfileName(TEXT("PawnOverlap"));

	//set pos and rotate so it can be spinny cool looking
	PickupMesh->SetRelativeRotation(FRotator(25, 0, 0));

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

	PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnOverlapStart); //call onoverlapstart when mesh begins overlapping with something
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PickupMesh->AddLocalRotation(FRotator(0, 1, 0)); //add spinny

}

void APickup::OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

	//heal if it is overlapped by a player
	if (PlayerCharacter != nullptr) {
		PlayerCharacter->PlayerPickup(WhichPickup);
	}
	//destroy after overlapping with an object
	Destroy();
}