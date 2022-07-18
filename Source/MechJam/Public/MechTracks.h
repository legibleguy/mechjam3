// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingMechComponent.h"
#include "MechTracks.generated.h"

/**
 * 
 */
UCLASS()
class MECHJAM_API UMechTracks : public UMovingMechComponent
{
	GENERATED_BODY()

	public:

	UMechTracks();

	virtual void TickComponent
	(
		float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction * ThisTickFunction
	) override;

	virtual	void MoveFB(float Val) override;
	virtual	void MoveRL(float Val) override;

	UPROPERTY(EditAnywhere)
		float TracksRotationSpeed;

	UPROPERTY()
		FRotator TargetRotFB;

	UPROPERTY()
		FRotator TargetRotRL;

	UPROPERTY()
		float CurrFB;

	UPROPERTY()
		float CurrRL;

	UPROPERTY()
		bool WantsToMoveFB;

	UPROPERTY()
		bool WantsToMoveRL;

	protected:

	virtual void BeginPlay() override;
	
};
