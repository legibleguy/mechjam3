// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerIF.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlayerIF : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WHATSWITHANDY_API IPlayerIF
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void SetCameraFocusActor(AActor* NewFocusActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		FVector GetCameraFocusLocation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		float GetCameraZoom();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void SetCameraUseCustomTargetPoint(bool bUse);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void SetCameraCustomTargetPoint(FVector NewCustomPoint);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void RotateCameraZ(const float& Delta);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void ClearCameraFocusActor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void SetCameraTopDownLookingDir(const FVector& NewLookingDir);
};
