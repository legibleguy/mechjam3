// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VeryVeryUsefulFuncs.generated.h"

/**
 * 
 */
UCLASS()
class WHATSWITHANDY_API UVeryVeryUsefulFuncs : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
		static AActor* GetClosestActor(const TArray<AActor*> Actors, const FVector ToPoint, int32& OutIndex);

	UFUNCTION(BlueprintPure)
		static FVector GetClosestPoint(const TArray<FVector> Points, const FVector ToPoint, int32& OutIndex);
	
};
