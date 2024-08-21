// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KJH_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKJH_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	FString UserId;

public:
	void SetUserInfo(FString userId);

};
