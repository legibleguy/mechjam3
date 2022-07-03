// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MovingMechComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "MechPawn.generated.h"

UCLASS()
class MECHJAM_API AMechPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMechPawn();

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* MechBaseMesh;

	UPROPERTY(EditDefaultsOnly)
		UFloatingPawnMovement* MovementComp;

	

	UFUNCTION() void MoveFB(float Val);
	UFUNCTION() void MoveRL(float Val);

	UFUNCTION() void LookX(float Val);
	UFUNCTION() void LookY(float Val);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
		UMovingMechComponent* MovingModuleRef;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
