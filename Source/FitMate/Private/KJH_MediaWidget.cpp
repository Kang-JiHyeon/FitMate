// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_MediaWidget.h"
#include "KJH_FileDialogLib.h"
#include "Components/Image.h"
#include "MediaPlayer.h"
#include "MediaTexture.h"
#include "Components/Button.h"
#include "KJH_GameModeBase.h"


void UKJH_MediaWidget::NativeConstruct()
{
    Super::NativeConstruct();

    MyGameMode = Cast<AKJH_GameModeBase>(GetWorld()->GetAuthGameMode());
}

void UKJH_MediaWidget::OpenAndPlayVideo()
{
    OnInitialize();

    if (MyMediaPlayer && MyMediaTexture)
    {
        MyMediaTexture->SetMediaPlayer(MyMediaPlayer);

        FilePath = UKJH_FileDialogLib::OpenFileDialog();
        if (!FilePath.IsEmpty())
        {
            MyMediaPlayer->OpenFile(FilePath);
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
    if(MyGameMode)
        MyGameMode->SaveVideoPath(FilePath);
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
