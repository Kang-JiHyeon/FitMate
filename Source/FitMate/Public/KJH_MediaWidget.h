// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KJH_MediaWidget.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKJH_MediaWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

public:
	
	UPROPERTY(EditDefaultsOnly)
	class UMediaPlayer* MyMediaPlayer;

	UPROPERTY(EditDefaultsOnly)
	class UMediaTexture* MyMediaTexture;

	UPROPERTY(meta=(BindWidget))
	class UImage* MediaRenderImage;

	UPROPERTY(BlueprintReadOnly)
	FString FilePath;

private:
	UPROPERTY()
	class AKJH_GameModeBase* MyGameMode;

	

private:

	UFUNCTION(BlueprintCallable)
	void OpenAndPlayVideo();

	UFUNCTION()
	void OnClickSend();

	UFUNCTION(BlueprintCallable)
	void OnInitialize();
};
