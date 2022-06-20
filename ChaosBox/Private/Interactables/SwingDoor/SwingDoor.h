#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Interfaces/Interact/InteractInterface.h>
#include <Components/TimelineComponent.h>
#include "SwingDoor.generated.h"

UCLASS()
class ASwingDoor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwingDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void InteractWithObject_Implementation() override;

	virtual void InteractableFound_Implementation() override;

private:
	void OpenDoor();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DoorFrameMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DoorMesh;

private:
	UPROPERTY()
	class APlayerCharacter* PlayerRef;

	bool bIsOpen;

	FRotator DoorRotation;

	float RotateValue;
};
