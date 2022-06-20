#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OpenWidget.generated.h"

UCLASS()
class UOpenWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UOpenWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

private:
	FVector2D GetScreenSize();

	FVector2D ScreenSize;
};
