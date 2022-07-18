// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "GameCommunication.h"
#include "MechWheeled.generated.h"

/**
 * 
 */
UCLASS()
class MECHJAM_API AMechWheeled : public AWheeledVehiclePawn, public IGameCommunication
{
	GENERATED_BODY()

	public:

	AMechWheeled();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void MechMoveFB(float Val);
		virtual void MechMoveFB_Implementation(float Val) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void MechMoveRL(float Val);
		virtual void MechMoveRL_Implementation(float Val) override;
	
};
