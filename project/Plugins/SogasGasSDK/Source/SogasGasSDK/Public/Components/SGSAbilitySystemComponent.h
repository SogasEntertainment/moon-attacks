#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "SGSAbilitySystemComponent.generated.h"

/*
 * Abstract AbilitySystemComponent that extends its functionality.
 * Allows to grant default abilities and attributes.
 */
UCLASS()
class SOGASGASSDK_API USGSAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	//~ Begin UAbilitySystemComponent
	void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;
	//~ End UAbilitySystemComponent

	// Default abilities and attributes to be granted.
	UPROPERTY(EditDefaultsOnly, Category = Ability)
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	UPROPERTY(EditDefaultsOnly, Category = Ability)
	TArray<TSubclassOf<UAttributeSet>> DefaultAttributes;

protected:
	void GrantDefaultAbilitiesAndAttributes();

	TArray<FGameplayAbilitySpecHandle> DefaultAbililtiesHandles;
};
