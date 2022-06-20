#pragma once

#include "Engine/DataTable.h"
#include "Str_WeaponStats.generated.h"

USTRUCT(BlueprintType)
struct FWeaponDataStats : public FTableRowBase
{
   GENERATED_BODY()

    public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 CurrentMagTotal;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 MaxMagTotal;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 CurrentTotalAmmo;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 MaxTotalAmmo;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 LowAmmo;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 DamageAmount;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    int32 CrosshairIndex;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float CriciticalHitChance;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float DamageRadius;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FName WeaponName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<class UTexture2D> Icon;
};
