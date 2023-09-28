#pragma once

#include "CoreMinimal.h"

#include "Abilities/GameplayAbility.h"
#include "SGSGameplayAbility.generated.h"

/*
 * Base class for abilities.
 */
UCLASS()
class SOGASGASSDK_API USGSGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	USGSGameplayAbility();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
	bool bActivateAbilityOnGranted = false;
};
