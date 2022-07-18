// Fill out your copyright notice in the Description page of Project Settings.


#include "MechTracks.h"
#include "Kismet/KismetMathLibrary.h"
#include "VeryVeryUsefulFuncs.h"

UMechTracks::UMechTracks(){
    TracksRotationSpeed = 7.f;
}

void UMechTracks::MoveFB(float Val){
    CurrFB = Val;
}

void UMechTracks::MoveRL(float Val){
    CurrRL = Val;
}

void UMechTracks::BeginPlay(){
    Super::BeginPlay();
}

void UMechTracks::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction){
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if(MovementCompRef){
        FRotator ControlRot = MovementCompRef->GetPawnOwner()->GetControlRotation();
        if(CurrFB != 0.f || CurrRL != 0.f){
            FVector FBMovement = FVector(FRotator(0, ControlRot.Yaw, 0).Vector()) * CurrFB;
            FVector RLMovement = FVector(FRotator(0, ControlRot.Yaw, 0).Add(0,90,0).Vector()) * CurrRL;

            FRotator TargetRot = FRotator(0,
                UKismetMathLibrary::FindLookAtRotation(
                    MovementCompRef->GetPawnOwner()->GetActorLocation(),
                    MovementCompRef->GetPawnOwner()->GetActorLocation() + FBMovement + RLMovement
                ).Yaw,
                0
            );

            float Delta = (TargetRot - MovementCompRef->GetPawnOwner()->GetActorRotation()).Yaw;

            if(FMath::Abs(Delta) > 5.f){
                FRotator SmoothedRot = UKismetMathLibrary::RInterpTo(MovementCompRef->GetPawnOwner()->GetActorRotation(),
                TargetRot, DeltaTime, TracksRotationSpeed);

                MovementCompRef->GetPawnOwner()->SetActorRotation(SmoothedRot);
            }
            if(FMath::Abs(Delta) < 45.f){
                MovementCompRef->AddInputVector(MovementCompRef->GetPawnOwner()->GetActorForwardVector());
            }
            
        }
    }
}

