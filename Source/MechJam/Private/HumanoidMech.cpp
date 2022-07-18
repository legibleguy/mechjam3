// Fill out your copyright notice in the Description page of Project Settings.


#include "HumanoidMech.h"

// Sets default values
AHumanoidMech::AHumanoidMech()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHumanoidMech::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHumanoidMech::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHumanoidMech::SetupPlayerInputComponent(class UInputComponent* Input){
	if(Input){
		Input->BindAxis("MoveFB", this, &AHumanoidMech::MoveFB);
		Input->BindAxis("MoveRL", this, &AHumanoidMech::MoveRL);
	}
}

void AHumanoidMech::MoveFB(float Val){
	AddMovementInput(FRotator(0, GetControlRotation().Yaw, 0).Vector(), Val);
}

void AHumanoidMech::MoveRL(float Val){
	AddMovementInput(FRotator(0, GetControlRotation().Yaw + 90, 0).Vector(), Val);
}

