// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_LoginWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "KJH_HttpManager.h"
#include "KJH_GameModeBase.h"


void UKJH_LoginWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonSignIn->OnClicked.AddDynamic(this, &UKJH_LoginWidget::OnClickSignIn);
	//ButtonRegister->OnClicked.AddDynamic(this, &UKJH_LoginWidget::OnClickRegister);

	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);

	auto* gameModeBase = Cast<AKJH_GameModeBase>(GetWorld()->GetAuthGameMode());
	if (gameModeBase && gameModeBase->HttpManager)
	{
		HttpManager = gameModeBase->HttpManager;
	}

}

void UKJH_LoginWidget::OnClickSignIn()
{
	if(HttpManager == nullptr)
		return;

	FString id = EditTextId->GetText().ToString();
	FString password = EditTextPassword->GetText().ToString();
	
	HttpManager->ReqLogin(id, password);
}

void UKJH_LoginWidget::OnClickRegister()
{

}