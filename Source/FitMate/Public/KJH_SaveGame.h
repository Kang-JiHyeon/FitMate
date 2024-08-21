// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "KJH_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKJH_SaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	FString VideoPath;
};
