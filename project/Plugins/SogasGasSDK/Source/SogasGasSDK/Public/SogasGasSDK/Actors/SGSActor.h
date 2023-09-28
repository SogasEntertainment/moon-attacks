#pragma once

#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "SogasGasSDK/Components/SGSAbilitySystemComponent.h"

#include "SGSActor.generated.h"

UCLASS()
class SOGASGASSDK_API ASGSActor : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASGSActor();

	//~ Begin IAbilitySystemInterface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface

private:
	USGSAbilitySystemComponent* AbilitySystemComponent = nullptr;
};
