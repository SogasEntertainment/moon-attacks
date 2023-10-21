#include "MoonSpawner.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

AMoonSpawner::AMoonSpawner()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
}

void AMoonSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AMoonSpawner::Spawn(int InNumberToSpawn /* = 1*/)
{
	if (auto World = GetWorld())
	{
		for (int Index = 0; Index < InNumberToSpawn; ++Index)
		{
			if (auto Actor = World->SpawnActor<AActor>(ActorToSpawn, GetActorTransform()))
			{
				const auto SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(BoxComponent->GetComponentLocation(), BoxComponent->GetScaledBoxExtent() / 2);
				Actor->SetActorLocation(SpawnLocation);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Actor not spawned."));
			}
		}
	}
}
