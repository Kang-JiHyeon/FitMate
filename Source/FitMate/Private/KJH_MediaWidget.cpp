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

    //ButtonSend->OnClicked.AddDynamic(this, &UKJH_MediaWidget::OnClickSend);

    //OpenAndPlayVideo();
}

void UKJH_MediaWidget::OpenAndPlayVideo()
{
    OnInitialize();

    if (MyMediaPlayer && MyMediaTexture)
    {
        MyMediaTexture->SetMediaPlayer(MyMediaPlayer);

        FString filePath = UKJH_FileDialogLib::OpenFileDialog();
        if (!filePath.IsEmpty())
        {
            MyMediaPlayer->OpenFile(filePath);
            MyMediaPlayer->Play();

            if (MediaRenderImage)
            {
                UMaterialInstanceDynamic* dynamicMaterial = MediaRenderImage->GetDynamicMaterial();

                if (dynamicMaterial)
                    dynamicMaterial->SetTextureParameterValue(FName("MediaTexture"), MyMediaTexture);
            }
        }
    }

}

void UKJH_MediaWidget::OnClickSend()
{
    // todo : 저장하기
    
    //this->RemoveFromParent();
}

void UKJH_MediaWidget::OnInitialize()
{
    if (MyMediaPlayer)
    {
        MyMediaPlayer->Pause();
        if (MediaRenderImage)
        {
            UMaterialInstanceDynamic* dynamicMaterial = MediaRenderImage->GetDynamicMaterial();

            if (dynamicMaterial)
                dynamicMaterial->SetTextureParameterValue(FName("MediaTexture"), nullptr);
        }
    }
}
