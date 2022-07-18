// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MechPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MECHJAM_API AMechPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:

	AMechPlayerController();

	UFUNCTION()
		void MoveFB(float Val);

	UFUNCTION()
		void MoveRL(float Val);

	UFUNCTION()
		void MoveUD(float Val);

	UFUNCTION() 
		void LookX(float Val);

	UFUNCTION() 
		void LookY(float Val);

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	protected:

	virtual void BeginPlay() override;

	
};
