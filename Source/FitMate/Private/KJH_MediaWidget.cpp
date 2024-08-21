// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_MediaWidget.h"
#include "KJH_FileDialogLib.h"
#include "Components/Image.h"
#include "MediaPlayer.h"
#include "MediaTexture.h"
#include "Components/Button.h"


void UKJH_MediaWidget::NativeConstruct()
{
    Super::NativeConstruct();

    ButtonSend->OnClicked.AddDynamic(this, &UKJH_MediaWidget::OnClickSend);

    OpenAndPlayVideo();
}

void UKJH_MediaWidget::OpenAndPlayVideo()
{
    if (MyMediaPlayer && MyMediaTexture)
    {
        MyMediaTexture->SetMediaPlayer(MyMediaPlayer);

        FString FilePath = UKJH_FileDialogLib::OpenFileDialog();
        if (!FilePath.IsEmpty())
        {
            MyMediaPlayer->OpenFile(FilePath);
            MyMediaPlayer->Play();
        }
    }

    UMaterialInstanceDynamic* DynamicMaterial = MediaRenderImage->GetDynamicMaterial();

    if (DynamicMaterial)
        DynamicMaterial->SetTextureParameterValue(FName("MediaTexture"), MyMediaTexture);
}

void UKJH_MediaWidget::OnClickSend()
{
    // todo : 저장하기
    
    this->RemoveFromParent();
}
