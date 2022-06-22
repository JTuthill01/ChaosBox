#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include <Weapons/WeaponEnums/WeaponEnums.h>
#include "PlayerAnimInstance.generated.h"

UCLASS()
class UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPlayerAnimInstance();
	
public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaTimeX) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PlayerRef, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class APlayerCharacter> PlayerRef;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Variables, meta = (AllowPrivateAccess = "true"))
	EWeaponName CurrentWeaponName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Variables, meta = (AllowPrivateAccess = "true"))
	float PlayerSpeed;
};
