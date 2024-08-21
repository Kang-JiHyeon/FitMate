// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CSW_UtilsLib.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UCSW_UtilsLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable)
	static void OnClearHabit(int32 Num);

	UFUNCTION(BlueprintCallable)
	static int32 PlusPoint(int32 Num = 1);

	UFUNCTION(BlueprintCallable)
	static int32 MinusPoint(int32 Num);

	UFUNCTION(BlueprintCallable)
	static TArray<int32> GetClearHabits();

	UFUNCTION(BlueprintCallable)
	static int32 ReadPoint();
};
