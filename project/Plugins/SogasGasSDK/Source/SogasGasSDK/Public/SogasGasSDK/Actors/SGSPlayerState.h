#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "SogasGasSDK/Components/SGSAbilitySystemComponent.h"

#include "SGSPlayerState.generated.h"

UCLASS()
class SOGASGASSDK_API ASGSPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
    ASGSPlayerState();

    //~ Begin IAbilitySystemInterface
    UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    //~ Begin IAbilitySystemInterface

private:
    UPROPERTY()
    USGSAbilitySystemComponent* AbilitySystemComponent = nullptr;
};
