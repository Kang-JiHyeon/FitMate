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
	FString UserId;
	FString UserName;

public:
	UKJH_GameInstance();
	virtual void OnStart() override;
	void SetUserInfo(FString userId, FString userName);
	UPROPERTY()
	class USoundBase* bgm = nullptr;
};
