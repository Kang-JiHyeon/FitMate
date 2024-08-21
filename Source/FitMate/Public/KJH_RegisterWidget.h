// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KJH_RegisterWidget.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKJH_RegisterWidget : public UUserWidget
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
	class UButton* ButtonSignUp;
	UPROPERTY(meta=(BindWidget))
	class UButton* ButtonLogin;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextFailedMsg;

	void SetUserInfoWidget(class UKJH_UserInfoWidget* Widget);

	void OnInitialize();
private:
	UFUNCTION()
	void OnClickSignUp();
	UFUNCTION()
	void OnChangedLogin();

	UFUNCTION()
	void OnResponseSignUp(bool bSucceessed);

	void SetHttpManager();

};
