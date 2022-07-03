// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "UniversalGameData.h"
#include "PlayerIF.h"
#include "UniversalCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class WHATSWITHANDY_API AUniversalCameraManager : public APlayerCameraManager, public IPlayerIF
{
	GENERATED_BODY()

public:

	AUniversalCameraManager();

	UPROPERTY(BlueprintReadWrite)
		TEnumAsByte<ViewMode> CurrentViewMode;

	UFUNCTION(BlueprintCallable)
		void SetFocusActor(AActor* InFocusActor) {
		FocusActor = InFocusActor;
	}

	UFUNCTION(BlueprintCallable)
		void ClearFocusActor() {
		FocusActor = NULL;
	}

	UPROPERTY(BlueprintReadWrite)
		bool bUseCustomTargetVector = false;

	UPROPERTY(BlueprintReadWrite)
		FVector CustomTarget;

	UPROPERTY(EditDefaultsOnly, Category = "Third Person")
		float ThirdPersonDistance;

	UPROPERTY(EditDefaultsOnly, Category = "Third Person")
		float ThirdPersonLookAtOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Third Person")
		FVector ThirdPersonOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Top Down")
		float TopDownZoom;

	UPROPERTY(EditDefaultsOnly, Category = "Top Down")
		float TopDownAngleMin;

	UPROPERTY(EditDefaultsOnly, Category = "Top Down")
		float TopDownAngleMax;

	UPROPERTY(EditDefaultsOnly, Category = "Top Down")
		float TopDownDistanceMin;

	UPROPERTY(EditDefaultsOnly, Category = "Top Down")
		float TopDownDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category = "Top Down")
		FVector TopDownOffset;

	UFUNCTION(BlueprintCallable)
		FTransform GetThirdPersonCameraTransform();

	UFUNCTION(BlueprintCallable)
		FTransform GetTopDownCameraTransform();

	UFUNCTION(BlueprintPure)
		FTransform GetCurrentViewModeTr();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void SetCameraTopDownLookingDir(const FVector& NewLookingDir);

	virtual void SetCameraTopDownLookingDir_Implementation(const FVector& NewLookingDir) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void SetCameraFocusActor(AActor* InFocusActor);

	virtual void SetCameraFocusActor_Implementation(AActor* InFocusActor) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void RotateCameraZ(const float& Delta);

	virtual void RotateCameraZ_Implementation(const float& Delta) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void ClearCameraFocusActor();

	virtual void ClearCameraFocusActor_Implementation() override;

	UFUNCTION(BlueprintPure)
		FVector GetCurrTopDownLookDir() { return TopDownLookDir; }

	UFUNCTION(BlueprintPure)
		FVector GetCurrentTargetLocation();

private:

	UPROPERTY()
		AActor* FocusActor;

	UPROPERTY()
		FVector TopDownLookDir;
	
};
