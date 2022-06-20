#include "Interactables/SwingDoor/SwingDoor.h"
#include <Player/PlayerCharacter.h>
#include <Interfaces/Player/PlayerInterface.h>
#include <Widgets/OpenWidget/OpenWidget.h>
#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ASwingDoor::ASwingDoor() : bIsOpen(false), DoorRotation(FRotator(0.F)), RotateValue(0.F)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Frame"));
	DoorFrameMesh->SetCastShadow(false);
	DoorFrameMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	DoorMesh->SetupAttachment(DoorFrameMesh);
	DoorMesh->SetCastShadow(false);
	DoorMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	SetRootComponent(DoorFrameMesh);
}

// Called when the game starts or when spawned
void ASwingDoor::BeginPlay()
{
	Super::BeginPlay();

	PlayerRef = IPlayerInterface::Execute_GetPlayerRef(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void ASwingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorRotation = DoorMesh->GetRelativeRotation();

	if (bIsOpen)
		DoorMesh->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.F, RotateValue, 0.F)), 0.01F));

	else 
		DoorMesh->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.F, RotateValue, 0.F)), 0.01F));
}

void ASwingDoor::InteractWithObject_Implementation()
{
	OpenDoor();
}

void ASwingDoor::OpenDoor()
{
	if (PlayerRef && !bIsOpen)
	{
		bIsOpen = true;

		FVector PawnLocation = PlayerRef->GetActorLocation();
		FVector Direction = DoorMesh->GetRelativeLocation() - PawnLocation;

		Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, DoorMesh->GetRelativeRotation());

		if (Direction.X > 0.F)
			RotateValue = 90.F;

		else
			RotateValue = -90.F;
	}
}

void ASwingDoor::InteractableFound_Implementation()
{
	if (IsValid(PlayerRef))
	{
		if (!PlayerRef->GetDoorWidget()->IsInViewport())
			PlayerRef->GetDoorWidget()->AddToViewport();
	}
}

