#pragma once

#include "AbilitySystemInterface.h"
#include "GameFramework/Pawn.h"
#include "SogasGasSDK/Components/SGSAbilitySystemComponent.h"

#include "SGSPawn.generated.h"

UCLASS()
class SOGASGASSDK_API ASGSPawn : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASGSPawn();

	//~ Begin IAbilitySystemInterface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface

private:
	USGSAbilitySystemComponent* AbilitySystemComponent = nullptr;
};
