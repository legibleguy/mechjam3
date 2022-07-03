// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingMechComponent.h"

UMovingMechComponent::UMovingMechComponent(){

}

void UMovingMechComponent::BeginPlay(){
    if(UActorComponent* AsAC = GetOwner()->FindComponentByClass(UFloatingPawnMovement::StaticClass())){
        MovementCompRef = Cast<UFloatingPawnMovement>(AsAC);
        MovementCompRef->Acceleration = MechAcceleration;
        MovementCompRef->MaxSpeed = MechMaxSpeed;
    }
}

void UMovingMechComponent::MoveFB(float Val){
    MovementCompRef->AddInputVector(GetOwner()->GetActorForwardVector() * Val);
}

void UMovingMechComponent::MoveRL(float Val){
    MovementCompRef->AddInputVector(GetOwner()->GetActorRightVector() * Val);
}

void UMovingMechComponent::MoveUD(float Val){
    if(UpwardsMovementMode == EUpwardsMovementMode::UMM_Fly)
        MovementCompRef->AddInputVector(GetOwner()->GetActorUpVector() * Val);
}
