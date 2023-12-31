#pragma once

#include "GameFramework/Pawn.h"
#include "InputActionValue.h"

#include "MoonPlayerPawn.generated.h"

class UArrowComponent;
class UCapsuleComponent;
class UFloatingPawnMovement;
class UMoonBaseAttributeSet;
class USphereComponent;
class UStaticMeshComponent;
class UInputAction;
class UInputMappingContext;

UCLASS()
class MOONATTACKS_API AMoonPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	AMoonPlayerPawn();

protected:
	void BeginPlay() override;

	/* Input callback functions */
	void Move(const FInputActionValue& InActionValue);
	void Pause(const FInputActionValue& InActionValue);
	void Shoot(const FInputActionValue& InActionValue);

	//~ Begin APawn interface
	void PossessedBy(AController* NewController) override;
	//~ End APawn interface

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* MoonCharacterContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* PauseAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ShootAction = nullptr;

	UPROPERTY()
	const UMoonBaseAttributeSet* BaseAttributeSet = nullptr;

private:
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> CollisionComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UFloatingPawnMovement> MovementComponent;

#if WITH_EDITORONLY_DATA
	/** Component shown in the editor only to indicate character facing */
	UPROPERTY()
	TObjectPtr<UArrowComponent> ArrowComponent;
#endif
};
