// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_ReceipWidget.h"
#include "../../../../Plugins/Runtime/WebBrowserWidget/Source/WebBrowserWidget/Public/WebBrowser.h"
#include "Components/TextBlock.h"
#include "Components/MultiLineEditableTextBox.h"

void UKMK_ReceipWidget::PlayYoutube(FString& youtube)
{
    youtube = TEXT("https://www.youtube.com/watch?v=nJ0iCRxgcr4");
    if (youtubeBrowser)
    {
        youtubeBrowser->LoadURL(youtube);
    }
}

void UKMK_ReceipWidget::SetTextLog(TMap<FString, FString> logs)
{
    // 서버에서 주는 주소값
    MenuText->SetText(FText::FromString(logs["Menu"]));
    FString originalString = logs["ingred"];
    FString modifiedString = originalString.Replace(TEXT(","), TEXT("\n"));
    IngredientText->SetText(FText::FromString(modifiedString));
    ReceEdiableText->SetText(FText::FromString(logs["recipe"]));
}
