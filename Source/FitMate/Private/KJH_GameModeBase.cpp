// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_GameModeBase.h"
#include "KJH_HttpManager.h"
#include "Kismet/GameplayStatics.h"
#include "KJH_SaveGame.h"

void AKJH_GameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // 통신
    HttpManager = GetWorld()->SpawnActor<AKJH_HttpManager>(AKJH_HttpManager::StaticClass());

}

void AKJH_GameModeBase::SaveVideoPath(FString Path)
{
    VideoPath = Path;

    // ShootingSaveGame 객체를 만들고
    UKJH_SaveGame* saveGame = Cast<UKJH_SaveGame>(UGameplayStatics::CreateSaveGameObject(UKJH_SaveGame::StaticClass()));

    if (saveGame != nullptr)
    {
        // 그 객체의 HighScoreSave의 값을 HighScore로 갱신한다.
        saveGame->VideoPath = Path;
        // 파일로 쓰고 싶다.
        UGameplayStatics::SaveGameToSlot(saveGame, VideoPathKey, MyUserIndex);
    }
}
