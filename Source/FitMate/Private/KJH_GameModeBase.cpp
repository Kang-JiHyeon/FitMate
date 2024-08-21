// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_GameModeBase.h"
#include "KJH_HttpManager.h"

void AKJH_GameModeBase::BeginPlay()
{
    Super::BeginPlay();

    HttpManager = GetWorld()->SpawnActor<AKJH_HttpManager>(AKJH_HttpManager::StaticClass());

    if (HttpManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("Create HttpManager!")); 
    }
}
