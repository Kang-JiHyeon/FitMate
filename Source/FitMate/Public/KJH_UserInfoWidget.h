// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KJH_UserInfoWidget.generated.h"

UENUM()
enum class EUserInfoWidgetState : int8
{
	Login,
	Register,
};


UCLASS()
class FITMATE_API UKJH_UserInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta=(BindWidget))
	class UKJH_LoginWidget* LoginWidget;

	UPROPERTY(meta=(BindWidget))
	class UKJH_RegisterWidget* RegisterWidget;

	UPROPERTY(meta=(BindWidget))
	class UWidgetSwitcher* WidgetSwitcher;

public:
	void OnSwitchWidget(EUserInfoWidgetState State);
	void OnClosedWidget();
};
