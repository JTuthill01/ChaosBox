#include "Weapons/WeaponBase/WeaponBase.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include <Player/PlayerCharacter.h>
#include <Interfaces/Player/PlayerInterface.h>
#include <Kismet/KismetMathLibrary.h>
#include <Engine/DataTable.h>
#include <Structs/WeaponData/Str_WeaponStats.h>

// Sets default values
AWeaponBase::AWeaponBase() : SocketName(NAME_None), bCanFire(true), bCanReload(true), bIsReloading(false), EjectQuat(FQuat(0.F)), FireQuat(FQuat(0.F)), WeaponFireTimer(0.F)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetCastShadow(false);
	WeaponMesh->bReturnMaterialOnMove = true;

	SetRootComponent(WeaponMesh);
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(WeaponMesh))
		WeaponAnimInstance = WeaponMesh->GetAnimInstance();

	PlayerRef = IPlayerInterface::Execute_GetPlayerRef(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::BulletTrace(FHitResult& HitResult, FTransform& ProjectileTransform)
{
	if (!IsValid(PlayerRef))
		return;

	FVector Start{ PlayerRef->GetPlayerCamera()->GetComponentLocation() };
	FVector Rotation{ PlayerRef->GetPlayerCamera()->GetComponentRotation().Vector() };
	FVector End{ Start + Rotation * 10'000.F };
	FVector Scale = FVector(1.F);

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(UGameplayStatics::GetPlayerController(PlayerRef, 0));
	ActorsToIgnore.Add(this);

	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjects;
	TraceObjects.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
	TraceObjects.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));

	const bool bHasBeenHit = UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), Start, End, TraceObjects, true, ActorsToIgnore, EDrawDebugTrace::None, HitResult, true);

	FVector Translation = HitResult.Location;
	FVector SocketLocation = WeaponMesh->GetSocketLocation(FName("Fire_FX_Slot"));

	if (bHasBeenHit)
	{
		FRotator TempRotator = UKismetMathLibrary::FindLookAtRotation(SocketLocation, Translation);

		ProjectileTransform = UKismetMathLibrary::MakeTransform(Translation, TempRotator, Scale);
	}

	else
	{
		FRotator TempRotator = PlayerRef->GetController()->GetControlRotation();

		if (TempRotator == FRotator(0.F))
			return;

		else
			ProjectileTransform = UKismetMathLibrary::MakeTransform(SocketLocation, TempRotator, Scale);
	}
}

void AWeaponBase::SetWeaponStats(EWeaponName Name)
{
	FString WeaponDataTablePath(TEXT("DataTable'/Game/Blueprints/Weapons/DataTable/DT_WeaponStats.DT_WeaponStats'"));

	TObjectPtr<UDataTable> WeaponDataTableObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *WeaponDataTablePath));

	if (IsValid(WeaponDataTableObject))
	{
		TObjectPtr<FWeaponDataStats> WeaponRow = nullptr;

		switch (Name)
		{
		case EWeaponName::EWN_TT33:
			break;

		case EWeaponName::EWN_AK47:
			break;

		case EWeaponName::EWN_AmericanShotgun:
			break;

		case EWeaponName::EWN_BelgianAR:
			break;

		case EWeaponName::EWN_GermanSMG:
			break;

		case EWeaponName::EWN_HandCannon:
			break;

		case EWeaponName::EWN_SKS:
			break;

		case EWeaponName::EWN_XM82:
			break;

		case EWeaponName::EWN_Bulldog:
			break;

		case EWeaponName::EWN_L86:
			break;

		case EWeaponName::EWN_AK74:
			break;

		case EWeaponName::EWN_M4A1:
			break;

		case EWeaponName::EWN_NavySMG:
			break;

		case EWeaponName::EWN_ItalianShotgun:
			break;

		case EWeaponName::EWN_SVD:
			break;

		case EWeaponName::EWN_ShortStrokeAR:

			WeaponRow = WeaponDataTableObject->FindRow<FWeaponDataStats>(FName("ShortStrokeAR"), TEXT(""));

			break;

		default:
			break;
		}

		if (WeaponRow)
		{
			CurrentMagTotal = WeaponRow->CurrentMagTotal;

			MaxMagTotal = WeaponRow->MaxMagTotal;

			CurrentTotalAmmo = WeaponRow->CurrentTotalAmmo;

			MaxTotalAmmo = WeaponRow->MaxTotalAmmo;

			LowAmmo = WeaponRow->LowAmmo;

			CrosshairIndex = WeaponRow->CrosshairIndex;

			WeaponIndex = WeaponRow->WeaponIndex;

			DamageAmount = WeaponRow->DamageAmount;

			CriciticalHitChance = WeaponRow->CriciticalHitChance;

			DamageRadius = WeaponRow->DamageRadius;

			NameOfWeapon = WeaponRow->WeaponName;

			Icon = WeaponRow->Icon;
		}

		else
			return;
	}

	else
		return;
}

void AWeaponBase::StopFire()
{

}

void AWeaponBase::WeaponFire()
{
	
}

void AWeaponBase::WeaponReload()
{
}

