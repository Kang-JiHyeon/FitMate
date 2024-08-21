// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_UserInfoWidget.h"
#include "KJH_GameModeBase.h"
#include "KJH_HttpManager.h"
#include "Components/WidgetSwitcher.h"
#include "KJH_RegisterWidget.h"
#include "KJH_LoginWidget.h"

void UKJH_UserInfoWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Mouse cursor
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);

	LoginWidget->SetUserInfoWidget(this);
	RegisterWidget->SetUserInfoWidget(this);
}

void UKJH_UserInfoWidget::OnSwitchWidget(EUserInfoWidgetState State)
{
	LoginWidget->OnInitialize();
	RegisterWidget->OnInitialize();

	WidgetSwitcher->SetActiveWidgetIndex((int8)State);
}

void UKJH_UserInfoWidget::OnClosedWidget()
{
	this->RemoveFromParent();
}
