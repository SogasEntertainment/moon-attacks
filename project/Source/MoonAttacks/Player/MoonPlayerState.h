#pragma once

#include "SogasGasSDK/Actors/SGSPlayerState.h"

#include "MoonPlayerState.generated.h"

class UMoonBaseAttributeSet;

UCLASS()
class MOONATTACKS_API AMoonPlayerState : public ASGSPlayerState
{
	GENERATED_BODY()

public:
	AMoonPlayerState();

	template <class T>
	const T* GetAttributeSet(TSubclassOf<T> InAttributeSetClass) const
	{
		if (auto AttributeSet = GetAbilitySystemComponent()->GetAttributeSet(InAttributeSetClass))
		{
			return Cast<T>(AttributeSet);
		}

		return nullptr;
	}

	UFUNCTION(BlueprintCallable)
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category = "MoonAttacks|Attributes")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "MoonAttacks|Attributes")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "MoonAttacks|Attributes")
	float GetSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "MoonAttacks|Attributes")
	float GetMaxSpeed() const;
};
