#pragma once

#include "GameFramework/Pawn.h"
#include "InputActionValue.h"

#include "MoonPlayerPawn.generated.h"

class UArrowComponent;
class UCapsuleComponent;
class UFloatingPawnMovement;
class USphereComponent;
class UStaticMeshComponent;
class UInputAction;
class UInputMappingContext;

UCLASS()
class MOONATTACKS_API AMoonCharacter : public APawn
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* MoonCharacterContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* PauseAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ShootAction = nullptr;

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
