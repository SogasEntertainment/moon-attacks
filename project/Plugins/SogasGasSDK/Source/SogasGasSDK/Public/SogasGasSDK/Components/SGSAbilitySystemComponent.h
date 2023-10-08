#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "SGSAbilitySystemComponent.generated.h"

class UDataTable;
class USGSAttributeSet;

USTRUCT()
struct FSGSAttributeApplication
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<USGSAttributeSet> AttributeSetType;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UDataTable> InitializationData;
};

/*
 * Abstract AbilitySystemComponent that extends its functionality.
 * Allows to grant default abilities and attributes.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
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
	TArray<FSGSAttributeApplication> DefaultAttributes;

protected:
	void GrantDefaultAbilitiesAndAttributes();

	TArray<FGameplayAbilitySpecHandle> DefaultAbililtiesHandles;

	UPROPERTY(transient)
	TArray<USGSAttributeSet*> AddedAttributes;
};
