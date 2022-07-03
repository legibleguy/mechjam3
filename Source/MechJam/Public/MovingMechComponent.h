// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MechComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "MovingMechComponent.generated.h"

//this will specify how this component will move the mech when we're trying to go up
//by, for exmaple, pressing spacebar
UENUM()
enum EUpwardsMovementMode{
	UMM_None UMETA(DisplayName = "None"),
	UMM_Jump UMETA(DisplayName = "Jump"),
	UMM_Fly UMETA(DisplayName = "Fly"),
};

/**
 * 
 */
UCLASS()
class MECHJAM_API UMovingMechComponent : public UMechComponent
{
	GENERATED_BODY()

	public:

		UPROPERTY(EditDefaultsOnly)
			TEnumAsByte<EUpwardsMovementMode> UpwardsMovementMode;

		UMovingMechComponent();

		UPROPERTY(EditAnywhere)
			float MechMaxSpeed;
		
		UPROPERTY(EditAnywhere)
			float MechAcceleration;

		UFUNCTION()
			virtual	void MoveFB(float Val);

		UFUNCTION()
			virtual	void MoveRL(float Val);

		UFUNCTION()
			virtual	void MoveUD(float Val);

	protected:

		virtual void BeginPlay() override;

	private:
	UPROPERTY()
		UFloatingPawnMovement* MovementCompRef;
	
};
