#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Weapons/WeaponEnums/WeaponEnums.h>
#include "WeaponBase.generated.h"

UCLASS()
class AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	//Getters
	FORCEINLINE TObjectPtr<USkeletalMeshComponent> GetWeaponMesh() const { return WeaponMesh; }
	FORCEINLINE FName GetSocketName() const { return SocketName; }
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	virtual void StopFire();

	UFUNCTION(BlueprintCallable)
	virtual void WeaponFire();

	UFUNCTION(BlueprintCallable)
	virtual void WeaponReload();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	UPROPERTY()
	TObjectPtr<class APlayerCharacter> PlayerRef;

	UPROPERTY()
	TObjectPtr<UAnimInstance> WeaponAnimInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = WeaponMesh)
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Animation)
	TObjectPtr<UAnimMontage> WeaponFireMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponDataTable)
	TObjectPtr<class UDataTable> WeaponTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Enums)
	EWeaponName WeaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponSocketName)
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponData)
	bool bCanFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponData)
	bool bCanReload;

protected:
	FQuat EjectQuat;
	FTransform EjectTransform;

	FQuat FireQuat;
	FTransform FireTransform;

private:
	void BulletTrace(FHitResult& HitResult, FTransform& ProjectileTransform);
};
