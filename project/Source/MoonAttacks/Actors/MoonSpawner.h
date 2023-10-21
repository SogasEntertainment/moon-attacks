#pragma once

#include "GameFramework/Actor.h"
#include "MoonSpawner.generated.h"

class UBoxComponent;
class UMoonActorPoolComponent;

UCLASS()
class MOONATTACKS_API AMoonSpawner : public AActor
{
	GENERATED_BODY()

public:
	AMoonSpawner();

	UFUNCTION(BlueprintCallable)
	void Spawn(int InNumberToSpawn = 1);

	//~ Begin UObject interface
	void BeginPlay() override;
	//~ End UObject interface

private:
	UPROPERTY(EditDefaultsOnly, Category = "Spawner")
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(VisibleAnywhere, Category = "BoxComponent")
	TObjectPtr<UBoxComponent> BoxComponent;
};
