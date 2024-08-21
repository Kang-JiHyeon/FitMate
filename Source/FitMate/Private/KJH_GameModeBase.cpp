// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_GameModeBase.h"
#include "KJH_HttpManager.h"
#include "Kismet/GameplayStatics.h"
#include "KJH_SaveGame.h"

void AKJH_GameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // ���
    HttpManager = GetWorld()->SpawnActor<AKJH_HttpManager>(AKJH_HttpManager::StaticClass());

}

void AKJH_GameModeBase::SaveVideoPath(FString Path)
{
    VideoPath = Path;

    // ShootingSaveGame ��ü�� �����
    UKJH_SaveGame* saveGame = Cast<UKJH_SaveGame>(UGameplayStatics::CreateSaveGameObject(UKJH_SaveGame::StaticClass()));

    if (saveGame != nullptr)
    {
        // �� ��ü�� HighScoreSave�� ���� HighScore�� �����Ѵ�.
        saveGame->VideoPath = Path;
        // ���Ϸ� ���� �ʹ�.
        UGameplayStatics::SaveGameToSlot(saveGame, VideoPathKey, MyUserIndex);
    }
}
