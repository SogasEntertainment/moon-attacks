#pragma once

#include "SogasGasSDK/Abilities/SGSAttributeSet.h"

#include "MoonBaseAttributeSet.generated.h"

UCLASS()
class MOONATTACKS_API UMoonBaseAttributeSet : public USGSAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMoonBaseAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMoonBaseAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UMoonBaseAttributeSet, Speed)

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FGameplayAttributeData MaxSpeed;
	ATTRIBUTE_ACCESSORS(UMoonBaseAttributeSet, MaxSpeed)

	bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
