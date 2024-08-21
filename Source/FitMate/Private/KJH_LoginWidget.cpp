// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_LoginWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "KJH_HttpManager.h"
#include "KJH_GameModeBase.h"
#include "KJH_UserInfoWidget.h"


void UKJH_LoginWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// HttpManager
	auto* gameModeBase = Cast<AKJH_GameModeBase>(GetWorld()->GetAuthGameMode());
	if (gameModeBase && gameModeBase->HttpManager)
	{
		HttpManager = gameModeBase->HttpManager;
	}

	// Button ¹ÙÀÎµù
	ButtonSignIn->OnClicked.AddDynamic(this, &UKJH_LoginWidget::OnClickSignIn);
	ButtonRegister->OnClicked.AddDynamic(this, &UKJH_LoginWidget::OnClickRegister);

	HttpManager->OnResponseLogin.AddUObject(this, &UKJH_LoginWidget::OnResponseLogin);
}

void UKJH_LoginWidget::SetUserInfoWidget(UKJH_UserInfoWidget* Widget)
{
    UserInfoWidget = Widget;
}

void UKJH_LoginWidget::OnInitialize()
{
	FText emptyText = FText::FromString("");
	EditTextId->SetText(emptyText);
	EditTextPassword->SetText(emptyText);

	TextLoginFailed->SetVisibility(ESlateVisibility::Hidden);
}

void UKJH_LoginWidget::OnClickSignIn()
{
	if(HttpManager == nullptr)
		return;

	TextLoginFailed->SetVisibility(ESlateVisibility::Hidden);

	FString id = EditTextId->GetText().ToString();
	FString password = EditTextPassword->GetText().ToString();
	
	HttpManager->ReqLogin(id, password);
}

void UKJH_LoginWidget::OnClickRegister()
{
	UserInfoWidget->OnSwitchWidget(EUserInfoWidgetState::Register);
}

void UKJH_LoginWidget::OnResponseLogin(bool bSuccessed)
{
	if (bSuccessed)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnSuccessedLogin! Close Login Widget!"));
		UserInfoWidget->OnClosedWidget();
	}
	else
	{
		TextLoginFailed->SetVisibility(ESlateVisibility::Visible);
	}
}
