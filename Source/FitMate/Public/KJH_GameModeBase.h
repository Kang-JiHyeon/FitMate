// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "KJH_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API AKJH_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	class AKJH_HttpManager* HttpManager;

	UPROPERTY()
	class UKJH_SaveGame* MySaveGame;

    FString VideoPath;
	FString VideoPathKey = TEXT("VideoPath");
	int32 MyUserIndex = 0;

public:
	UFUNCTION(BlueprintCallable)
	void SaveVideoPath(FString Path);
};
