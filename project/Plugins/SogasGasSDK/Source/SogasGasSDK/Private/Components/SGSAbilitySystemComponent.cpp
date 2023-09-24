#include "Components/SGSAbilitySystemComponent.h"

void USGSAbilitySystemComponent::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);

	GrantDefaultAbilitiesAndAttributes();
}

void USGSAbilitySystemComponent::GrantDefaultAbilitiesAndAttributes()
{
	if (IsOwnerActorAuthoritative())
	{
		DefaultAbililtiesHandles.Reserve(DefaultAbilities.Num());
		for (const auto& Ability : DefaultAbilities)
		{
			if (auto AbilityClass = Ability.Get())
			{
				FGameplayAbilitySpec AbilitySpec(AbilityClass);
				DefaultAbililtiesHandles.Add(GiveAbility(AbilitySpec));
			}
		}
	}
}
