#include "MoonAsteroid.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

AMoonAsteroid::AMoonAsteroid()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(TEXT("/Engine/EngineMeshes/Sphere"));

	check(Sphere.Succeeded());

	PrimaryActorTick.bCanEverTick = true;

	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetStaticMesh(Sphere.Object);
		StaticMeshComponent->bCastDynamicShadow = true;
		StaticMeshComponent->SetupAttachment(GetRootComponent());
	}
}

void AMoonAsteroid::BeginPlay()
{
	Super::BeginPlay();

	Speed = FMath::RandRange(MinSpeed, MaxSpeed);
}

void AMoonAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const auto FrontVector = GetActorForwardVector();
	SetActorLocation(GetActorLocation() - FrontVector * Speed);
}

float AMoonAsteroid::GetSpeed() const
{
	return Speed;
}
