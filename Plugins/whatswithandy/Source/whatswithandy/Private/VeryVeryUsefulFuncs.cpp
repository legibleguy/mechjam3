// Fill out your copyright notice in the Description page of Project Settings.


#include "VeryVeryUsefulFuncs.h"
#include "Kismet/KismetSystemLibrary.h"

AActor* UVeryVeryUsefulFuncs::GetClosestActor(const TArray<AActor*> Actors, const FVector ToPoint, int32& OutIndex)
{
	OutIndex = 0;
	if (Actors.Num() < 1) return NULL;
	AActor* Out = Actors[0];
	if (!Out) {
		UKismetSystemLibrary::PrintWarning("GetClosestActor(): First actor in the array is not valid!");
		return NULL;
	}
	float ShortestDist = (Out->GetActorLocation() - ToPoint).Size();

	for (int32 i = 1; i < Actors.Num(); i++)
	{
		float CurrDist = (Actors[i]->GetActorLocation() - ToPoint).Size();
		if (CurrDist < ShortestDist) {
			ShortestDist = CurrDist;
			Out = Actors[i];
			OutIndex = i;
		}
	}
	return Out;
}

FVector UVeryVeryUsefulFuncs::GetClosestPoint(const TArray<FVector> Points, const FVector ToPoint, int32& OutIndex)
{
	if (Points.Num() == 0) return FVector(0, 0, 0);
	float CurrentClosestDist = (Points[0] - ToPoint).Size();
	int32 CurrentClosestInd = 0;
	FVector CurrentClosest = Points[0];
	for (int32 i = 1; i < Points.Num(); i++) {
		float CurrDist = (Points[i] - ToPoint).Size();
		if (CurrDist < CurrentClosestDist) {
			CurrentClosestInd = i;
			CurrentClosestDist = CurrDist;
			CurrentClosest = Points[i];
			OutIndex = i;
		}
	}
	return CurrentClosest;
}
