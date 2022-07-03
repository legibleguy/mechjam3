// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ViewMode : uint8
{
	SideScroll = 0 UMETA(DisplayName = "Side Scroll"),
	TopDown = 1  UMETA(DisplayName = "Top Down"),
	FirstPerson = 2     UMETA(DisplayName = "First Person"),
	ThirdPerson = 3	UMETA(DisplayName = "Third Person")
};

/**
 * 
 */
class WHATSWITHANDY_API UniversalGameData
{
public:
	UniversalGameData();
	~UniversalGameData();
};
