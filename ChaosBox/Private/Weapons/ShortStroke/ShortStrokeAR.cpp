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

}

void AShortStrokeAR::WeaponReload()
{
}

void AShortStrokeAR::ResetIsReloading()
{
}

void AShortStrokeAR::ResetCanFire()
{
}
