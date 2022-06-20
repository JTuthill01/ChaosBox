#include "Widgets/OpenWidget/OpenWidget.h"

UOpenWidget::UOpenWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

void UOpenWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/*SetDesiredSizeInViewport(FVector2D(400.F, 400.F));

	ScreenSize = FVector2D(GetScreenSize().X / 2, GetScreenSize().Y / 2);

	SetPositionInViewport(ScreenSize);*/
}

FVector2D UOpenWidget::GetScreenSize()
{
	FVector2D Result = FVector2D(0.F);

	if (GEngine && GEngine->GameViewport)
		GEngine->GameViewport->GetViewportSize(Result);

	return Result;
}
