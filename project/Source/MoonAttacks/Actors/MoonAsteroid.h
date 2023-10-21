#pragma once

#include "SogasGasSDK/Actors/SGSActor.h"

#include "MoonAsteroid.generated.h"

class UFloatingPawnMovement;
class UStaticMeshComponent;

UCLASS()
class MOONATTACKS_API AMoonAsteroid : public ASGSActor
{
	GENERATED_BODY()

public:
	AMoonAsteroid();

	void Tick(float DeltaTime) override;

	void BeginPlay() override;

	float GetSpeed() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Asteroid")
	float MinSpeed{ 0.0f };

	UPROPERTY(EditDefaultsOnly, Category = "Asteroid")
	float MaxSpeed{ 1.0f };

	float Speed{ 0.0 };

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
};
