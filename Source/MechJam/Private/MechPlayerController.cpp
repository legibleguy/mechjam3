// Fill out your copyright notice in the Description page of Project Settings.


#include "MechPlayerController.h"
#include "GameCommunication.h"
#include "Kismet/KismetSystemLibrary.h"

AMechPlayerController::AMechPlayerController(){

}

void AMechPlayerController::BeginPlay(){
    Super::BeginPlay();
}

// Called to bind functionality to input
void AMechPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if(InputComponent){
		// InputComponent->BindAxis("MoveFB", this, &AMechPlayerController::MoveFB);
		// InputComponent->BindAxis("MoveRL", this, &AMechPlayerController::MoveRL);
		// InputComponent->BindAxis("MoveUD", this, &AMechPlayerController::MoveUD);
		InputComponent->BindAxis("LookX", this, &AMechPlayerController::LookX);
		InputComponent->BindAxis("LookY", this, &AMechPlayerController::LookY);
	}

}

void AMechPlayerController::MoveFB(float Val){
    IGameCommunication::Execute_MechMoveFB(GetPawn(), Val);
}

void AMechPlayerController::MoveRL(float Val){
    IGameCommunication::Execute_MechMoveRL(GetPawn(), Val);
}

void AMechPlayerController::MoveUD(float Val){
    IGameCommunication::Execute_MechMoveUD(GetPawn(), Val);
}

void AMechPlayerController::LookX(float Val){
	AddYawInput(Val);
}

void AMechPlayerController::LookY(float Val){
    AddPitchInput(Val);
}

