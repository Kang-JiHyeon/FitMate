// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KJH_LoginWidget.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKJH_LoginWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	
private:
	UPROPERTY()
	class AKJH_HttpManager* HttpManager;

	UPROPERTY()
	class UKJH_UserInfoWidget* UserInfoWidget;

public:

	UPROPERTY(meta=(BindWidget))
	class UEditableText* EditTextId;

	UPROPERTY(meta=(BindWidget))
	class UEditableText* EditTextPassword;
	
	UPROPERTY(meta=(BindWidget))
	class UButton* ButtonSignIn;

	UPROPERTY(meta=(BindWidget))
	class UButton* ButtonRegister;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextLoginFailed;

	void SetUserInfoWidget(class UKJH_UserInfoWidget* Widget);
	void OnInitialize();

private:
	UFUNCTION()
	void OnClickSignIn();
	UFUNCTION()
	void OnClickRegister();

	UFUNCTION()
	void OnResponseLogin(bool bResult);
};
