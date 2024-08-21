// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_RegisterWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "KJH_HttpManager.h"
#include "KJH_GameModeBase.h"
#include "KJH_UserInfoWidget.h"


void UKJH_RegisterWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetHttpManager();


	// ��ư ���ε�
	ButtonSignUp->OnClicked.AddDynamic(this, &UKJH_RegisterWidget::OnClickSignUp);
	ButtonLogin->OnClicked.AddDynamic(this, &UKJH_RegisterWidget::OnChangedLogin);
}

void UKJH_RegisterWidget::OnClickSignUp()
{
	// ���
	if (HttpManager == nullptr)
	{
		SetHttpManager();
	}

	FString id = EditTextId->GetText().ToString();
	FString password = EditTextPassword->GetText().ToString();

	if (id.IsEmpty() || password.IsEmpty())
	{
		TextFailedMsg->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		TextFailedMsg->SetVisibility(ESlateVisibility::Hidden);
		HttpManager->ReqSignUp(id, password);
	}
}

void UKJH_RegisterWidget::OnChangedLogin()
{
	// �α������� ��ȯ
	UserInfoWidget->OnSwitchWidget(EUserInfoWidgetState::Login);
}

void UKJH_RegisterWidget::OnResponseSignUp(bool bSucceessed)
{
	if (bSucceessed)
	{
		OnChangedLogin();
	}
	else
	{
		TextFailedMsg->SetVisibility(ESlateVisibility::Visible);
	}
}

void UKJH_RegisterWidget::SetHttpManager()
{
	// HttpManager
	auto* gameModeBase = Cast<AKJH_GameModeBase>(GetWorld()->GetAuthGameMode());
	if (gameModeBase && gameModeBase->HttpManager)
	{
		HttpManager = gameModeBase->HttpManager;

		// ȸ������ ��������Ʈ ���ε�
		HttpManager->OnResponseRegister.AddUObject(this, &UKJH_RegisterWidget::OnResponseSignUp);
	}
}

void UKJH_RegisterWidget::SetUserInfoWidget(UKJH_UserInfoWidget* Widget)
{
	UserInfoWidget = Widget;
}


void UKJH_RegisterWidget::OnInitialize()
{
	FText emptyText = FText::FromString("");
	EditTextId->SetText(emptyText);
	EditTextPassword->SetText(emptyText);

	TextFailedMsg->SetVisibility(ESlateVisibility::Hidden);
}
