
#include "MoonPlayerPawn.h"
#include "Components/ArrowComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "InputAction.h"
#include "Kismet/GameplayStatics.h"
#include "MoonAttacks/Abilities/AttributeSets/MoonBaseAttributeSet.h"
#include "MoonPlayerState.h"

AMoonPlayerPawn::AMoonPlayerPawn()
{
	// Not necessary at the moment.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	CollisionComponent->InitSphereRadius(40.0f);
	CollisionComponent->SetShouldUpdatePhysicsVolume(true);
	CollisionComponent->SetCanEverAffectNavigation(false);
	SetRootComponent(CollisionComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/EngineMeshes/Cube"));

	check(Cube.Succeeded());

	if (MeshComponent)
	{
		MeshComponent->SetStaticMesh(Cube.Object);
		MeshComponent->bCastDynamicShadow = true;
		MeshComponent->SetupAttachment(GetRootComponent());
	}

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	MovementComponent->SetUpdatedComponent(CollisionComponent);

#if WITH_EDITORONLY_DATA
	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(150, 200, 255);
		ArrowComponent->bTreatAsASprite = true;
		ArrowComponent->SpriteInfo.Category = TEXT("MoonCharacter");
		ArrowComponent->SpriteInfo.DisplayName = NSLOCTEXT("MoonCharacterArrow", "Help", "Manuela");
		ArrowComponent->SetupAttachment(CollisionComponent);
		ArrowComponent->bIsScreenSizeScaled = true;
		ArrowComponent->SetSimulatePhysics(false);
	}
#endif // WITH_EDITORONLY_DATA

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void AMoonPlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	if (auto PlayerController = Cast<APlayerController>(GetController()))
	{
		if (auto EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			EnhancedInputSubsystem->AddMappingContext(MoonCharacterContext, 0);
		}
	}
}

void AMoonPlayerPawn::Move(const FInputActionValue& InActionValue)
{
	const auto value = InActionValue.Get<FVector2D>();

	const auto	   Rotation = GetController()->GetControlRotation();
	const FRotator YawRotator(0.f, Rotation.Yaw, 0.f);

	const auto ForwardVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardVector, value.Y * BaseAttributeSet->GetSpeed());

	const auto RightVector = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightVector, value.X * BaseAttributeSet->GetSpeed());
}

void AMoonPlayerPawn::Pause(const FInputActionValue& /*InActionValue*/)
{
	const auto World = GetWorld();
	UGameplayStatics::SetGamePaused(World, !UGameplayStatics::IsGamePaused(World));
}

void AMoonPlayerPawn::Shoot(const FInputActionValue& InActionValue)
{
	const auto value = InActionValue.Get<bool>();
	if (value)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), FString("Shooting"));
	}
}

void AMoonPlayerPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (auto PlayerStatePtr = GetPlayerState<AMoonPlayerState>())
	{
		BaseAttributeSet = PlayerStatePtr->GetAttributeSet<UMoonBaseAttributeSet>(UMoonBaseAttributeSet::StaticClass());
	}
}

void AMoonPlayerPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// CastChecked because if input component cast fails, we do not want to continue. So crash the game ...
	if (auto EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMoonPlayerPawn::Move);
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Triggered, this, &AMoonPlayerPawn::Pause);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &AMoonPlayerPawn::Shoot);
	}
}
