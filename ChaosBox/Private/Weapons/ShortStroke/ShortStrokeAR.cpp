#include "Weapons/ShortStroke/ShortStrokeAR.h"
#include "Kismet/GameplayStatics.h"

AShortStrokeAR::AShortStrokeAR() = default;

void AShortStrokeAR::WeaponFire()
{
	Super::WeaponFire();

	EjectTransform = WeaponMesh->GetSocketTransform("AmmoEject");

	EjectTransform.GetRotation() = EjectQuat;

	FireTransform = WeaponMesh->GetSocketTransform("Fire_FX_Slot");

	FireTransform.GetRotation() = FireQuat;

	if (IsValid(WeaponAnimInstance))
	{
		WeaponFireTimer = WeaponAnimInstance->Montage_Play(WeaponFireMontage);

		GetWorldTimerManager().SetTimer(WeaponFireTimerHandle, this, &AShortStrokeAR::ResetCanFire, WeaponFireTimer, false);
	}
}

void AShortStrokeAR::WeaponReload()
{
}

void AShortStrokeAR::ResetIsReloading()
{
}

void AShortStrokeAR::ResetCanFire()
{
	bCanFire = !bCanFire;

	GetWorldTimerManager().ClearTimer(WeaponFireTimerHandle);
}
