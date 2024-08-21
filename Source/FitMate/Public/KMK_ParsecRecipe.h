// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KMK_ParsecRecipe.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKMK_ParsecRecipe : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static TMap<int, FString>  RecipeJsonParsec(const FString& json);
};
