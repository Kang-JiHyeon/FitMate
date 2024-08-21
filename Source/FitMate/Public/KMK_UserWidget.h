// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KMK_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKMK_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public :
	virtual void NativeConstruct() override;


	UPROPERTY(meta = (BindWidget))
	class UButton* SendButt;
	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButt;

	UPROPERTY(meta = (BindWidget))
    class UEditableText* indgredientEditText;

	UFUNCTION()
	void OnCommitButtonClicked();

	UFUNCTION()
	void OnClickExitButt();
	UPROPERTY()
	class UKMK_MakeWidgetComponent* playerWidget;
};
