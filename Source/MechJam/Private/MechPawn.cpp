// Fill out your copyright notice in the Description page of Project Settings.


#include "MechPawn.h"

// Sets default values
AMechPawn::AMechPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MechBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	MovementComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
}

// Called when the game starts or when spawned
void AMechPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if(UActorComponent* AsAC = FindComponentByClass(UMovingMechComponent::StaticClass())){
        MovingModuleRef = Cast<UMovingMechComponent>(AsAC);
    }
}

// Called every frame
void AMechPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMechPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(PlayerInputComponent){
		PlayerInputComponent->BindAxis("MoveFB", this, &AMechPawn::MoveFB);
		PlayerInputComponent->BindAxis("MoveRL", this, &AMechPawn::MoveRL);
		PlayerInputComponent->BindAxis("LookX", this, &AMechPawn::LookX);
		PlayerInputComponent->BindAxis("LookY", this, &AMechPawn::LookY);
	}

}

//Movement and camera input
void AMechPawn::MoveFB(float Val){
	if(MovingModuleRef)MovingModuleRef->MoveFB(Val);
}

void AMechPawn::MoveRL(float Val){
	if(MovingModuleRef)MovingModuleRef->MoveRL(Val);
}
void AMechPawn::LookX(float Val){
	
}

void AMechPawn::LookY(float Val){

}

