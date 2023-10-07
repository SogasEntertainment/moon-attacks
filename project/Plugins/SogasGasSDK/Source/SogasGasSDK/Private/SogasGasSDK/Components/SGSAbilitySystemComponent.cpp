#include "SogasGasSDK/Components/SGSAbilitySystemComponent.h"
#include "SogasGasSDK/Abilities/SGSAttributeSet.h"

void USGSAbilitySystemComponent::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);

	GrantDefaultAbilitiesAndAttributes();
}

void USGSAbilitySystemComponent::GrantDefaultAbilitiesAndAttributes()
{
	for (auto AttributeSetInstance : AddedAttributes)
	{
		GetSpawnedAttributes_Mutable().Remove(AttributeSetInstance);
	}

	for (auto AbilityHandle : DefaultAbililtiesHandles)
	{
		SetRemoveAbilityOnEnd(AbilityHandle);
	}

	AddedAttributes.Empty(DefaultAttributes.Num());
	DefaultAbililtiesHandles.Empty(DefaultAbilities.Num());

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

		for (const auto& Attribute : DefaultAttributes)
		{
			if (Attribute.AttributeSetType)
			{
				auto NewAttributeSet = NewObject<USGSAttributeSet>(GetOwner(), Attribute.AttributeSetType);

				if (Attribute.InitializationData)
				{
					NewAttributeSet->InitFromMetaDataTable(Attribute.InitializationData);
				}

				AddedAttributes.Add(NewAttributeSet);
				AddAttributeSetSubobject(NewAttributeSet);
			}
		}
	}
}
