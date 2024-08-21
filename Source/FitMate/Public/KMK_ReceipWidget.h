// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "KMK_ReceipWidget.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKMK_ReceipWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	class UEditableText* MenuText;

	UPROPERTY(meta = (BindWidget))
	class UMultiLineEditableText* IngredientText;

	UPROPERTY(meta = (BindWidget))
	class UMultiLineEditableText* ReceEdiableText;

    UPROPERTY(meta = (BindWidget))
    class UWebBrowser* youtubeBrowser;
};
