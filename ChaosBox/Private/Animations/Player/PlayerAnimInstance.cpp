#include "Animations/Player/PlayerAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include <Player/PlayerCharacter.h>
#include <Weapons/WeaponBase/WeaponBase.h>

UPlayerAnimInstance::UPlayerAnimInstance() : CurrentWeaponName(EWeaponName::EWN_NONE), PlayerSpeed(0.F)
{}

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	PlayerRef = Cast<APlayerCharacter>(TryGetPawnOwner());
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
	Super::NativeUpdateAnimation(DeltaTimeX);

	if (!IsValid(PlayerRef))
		PlayerRef = Cast<APlayerCharacter>(TryGetPawnOwner());

	else if (IsValid(PlayerRef))
		PlayerSpeed = PlayerRef->GetVelocity().Size();
}
