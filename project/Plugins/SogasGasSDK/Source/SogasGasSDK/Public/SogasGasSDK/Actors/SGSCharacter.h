#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "SogasGasSDK/Components/SGSAbilitySystemComponent.h"

#include "SGSCharacter.generated.h"

UCLASS()
class SOGASGASSDK_API ASGSCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASGSCharacter();

	//~ Begin IAbilitySystemInterface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface

	//~ Begin AActor
	void PossessedBy(AController* InNewController) override;
	//~ End AActor

private:
	UAbilitySystemComponent* AbilitySystemComponent = nullptr;
};
