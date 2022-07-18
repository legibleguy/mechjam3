// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MJ3SaveGame.generated.h"

/**
 * Michael A. 7/10/22
 * Set up properties to be stored with the savegame
 */
UCLASS()
class MECHJAM_API UMJ3SaveGame : public USaveGame
{
	GENERATED_BODY()

	public:

    UPROPERTY(VisibleAnywhere, Category = Basic)
            FString PlayerName;

    UPROPERTY(VisibleAnywhere, Category = Basic)
            FString SaveSlotName;

    UPROPERTY(VisibleAnywhere, Category = Basic)
            uint32 UserIndex;
    
    UMJ3SaveGame();
	
};
