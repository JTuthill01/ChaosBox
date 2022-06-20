#include "Interactables/InteractableBase/InteractableBase.h"
#include <Interfaces/Player/PlayerInterface.h>
#include "Kismet/GameplayStatics.h"

// Sets default values
AInteractableBase::AInteractableBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetCastShadow(false);
	BaseMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BaseMesh->SetGenerateOverlapEvents(true);

	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerRef = IPlayerInterface::Execute_GetPlayerRef(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableBase::InteractWithObject_Implementation() {}

void AInteractableBase::InteractableFound_Implementation() {}

