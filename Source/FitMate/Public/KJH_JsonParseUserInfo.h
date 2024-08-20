// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KJH_JsonParseUserInfo.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKJH_JsonParseUserInfo : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FString JsonParse(const FString& json);
};
