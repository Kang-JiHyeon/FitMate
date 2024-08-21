// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KJH_FileDialogLib.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKJH_FileDialogLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FString OpenFileDialog();
};
