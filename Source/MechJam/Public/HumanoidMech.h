// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCommunication.h"
#include "HumanoidMech.generated.h"

UCLASS()
class MECHJAM_API AHumanoidMech : public ACharacter, public IGameCommunication
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHumanoidMech();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION() void MoveFB(float Val);
	UFUNCTION() void MoveRL(float Val);

};
