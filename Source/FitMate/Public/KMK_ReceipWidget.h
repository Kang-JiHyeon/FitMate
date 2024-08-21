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
	class UTextBlock* MenuText;

	UPROPERTY(meta = (BindWidget))
	class UMultiLineEditableTextBox* IngredientText;

	UPROPERTY(meta = (BindWidget))
	class UMultiLineEditableTextBox* ReceEdiableText;

	UPROPERTY(meta = (BindWidget))
	class UWebBrowser* youtubeBrowser;

	UFUNCTION(BlueprintCallable)
	void PlayYoutube(FString& youtubeURL);

	// 메뉴, 재료, 레시피 작성
	void SetTextLog(TMap<FString, FString> logs);
};
