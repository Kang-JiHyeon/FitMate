// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_UserWidget.h"
#include "Components/EditableText.h"
#include "Blueprint/UserWidget.h"
#include "Internationalization/Text.h"
#include "Components/Button.h"

void UKMK_UserWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (SendButt)
    {
        // 버튼 클릭 이벤트 바인딩
        SendButt->OnClicked.AddDynamic(this, &UKMK_UserWidget::OnCommitButtonClicked);
    }
}
void UKMK_UserWidget::OnCommitButtonClicked()
{
    if (indgredientEditText)
    {
        // 현재 텍스트를 가져오고, 커밋 처리
        FText CurrentText = indgredientEditText->GetText();
        // 서버에게 데이터값 보내기
        GEngine->AddOnScreenDebugMessage(1, 1, FColor::Green, FString::Printf(TEXT("%s"), *CurrentText.ToString()));
    }
}
