// Fill out your copyright notice in the Description page of Project Settings.


#include "UniversalCameraManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "KIsmet/KismetSystemLibrary.h"

AUniversalCameraManager::AUniversalCameraManager()
{
	ThirdPersonDistance = 300.0;
	TopDownLookDir = FVector(1, 0, 0);
}

FTransform AUniversalCameraManager::GetThirdPersonCameraTransform()
{
	FTransform Out;
	AActor* Target = FocusActor != NULL ? FocusActor : GetOwningPlayerController()->GetPawn();
	if (Target) {
		const FVector ActorLoc = Target->GetActorLocation();
		const FVector ActorRight = Target->GetActorRightVector();
		const FRotator ControlRot = GetOwningPlayerController()->GetControlRotation();
		const float Angle = FMath::ClampAngle(ControlRot.Pitch, -45, 89);

		//Location
		FVector Loc = (FRotator(0, ControlRot.Yaw, 0).Vector() * -1.0) * ThirdPersonDistance;
		Loc = FMath::IsWithin(ControlRot.Yaw, 90, 270) ? 
			ActorLoc - Loc.RotateAngleAxis(Angle, ActorRight) :
		 	ActorLoc + Loc.RotateAngleAxis(Angle, ActorRight);
		Out.SetLocation(Loc);

		FRotator Rot = UKismetMathLibrary::FindLookAtRotation(Loc, ActorLoc + ThirdPersonLookAtOffset);
		Out.SetRotation(Rot.Quaternion());

	}
	return Out;
}

FTransform AUniversalCameraManager::GetTopDownCameraTransform()
{
	FTransform Out;
	AActor* Target = FocusActor != NULL ? FocusActor : GetOwningPlayerController()->GetPawn();
	if (!Target && !bUseCustomTargetVector) return Out;
	else {

		const FVector ActorLoc = bUseCustomTargetVector ? CustomTarget : Target->GetActorLocation();
		float Dist = FMath::Lerp(TopDownDistanceMin, TopDownDistanceMax, TopDownZoom);
		const float Angle = FMath::ClampAngle(TopDownDistanceMin, TopDownDistanceMax, TopDownZoom);

		FVector Loc = (TopDownLookDir * (-Dist)) + ActorLoc + TopDownOffset;
		Out.SetLocation(Loc);
		FRotator Rot = UKismetMathLibrary::FindLookAtRotation(Loc, ActorLoc);
		Out.SetRotation(Rot.Quaternion());

		return Out;
	}
}

FTransform AUniversalCameraManager::GetCurrentViewModeTr()
{
	switch (CurrentViewMode)
	{
	case ViewMode::ThirdPerson:
		return GetThirdPersonCameraTransform();
		break;
	case ViewMode::TopDown:
		return GetTopDownCameraTransform();
		break;
	default:
		return FTransform();
		break;
	}
}

void AUniversalCameraManager::SetCameraTopDownLookingDir_Implementation(const FVector& NewLookingDir)
{
	TopDownLookDir = NewLookingDir;
}

void AUniversalCameraManager::SetCameraFocusActor_Implementation(AActor* InFocusActor)
{
	FocusActor = InFocusActor;
}

void AUniversalCameraManager::RotateCameraZ_Implementation(const float& Delta)
{

}

void AUniversalCameraManager::ClearCameraFocusActor_Implementation()
{
	ClearFocusActor();
}

FVector AUniversalCameraManager::GetCurrentTargetLocation()
{
	return bUseCustomTargetVector ? CustomTarget : 
		(FocusActor ? FocusActor->GetActorLocation() : 
			GetOwningPlayerController()->GetPawn() ? GetOwningPlayerController()->GetPawn()->GetActorLocation() : 
			FVector(0,0,0));
}
