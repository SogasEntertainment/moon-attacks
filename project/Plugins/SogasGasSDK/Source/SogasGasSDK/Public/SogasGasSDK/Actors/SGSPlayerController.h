#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SGSPlayerController.generated.h"

UCLASS()
class SOGASGASSDK_API ASGSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void OnPossess(APawn* InPawn) override;
};
