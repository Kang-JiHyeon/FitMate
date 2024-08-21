// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

UKJH_GameInstance::UKJH_GameInstance()
{
    ConstructorHelpers::FObjectFinder<USoundBase> BGMObject(TEXT("/Script/Engine.SoundCue'/Game/KMK/SC_BGM.SC_BGM'"));
    if (BGMObject.Succeeded())
    {
        bgm = BGMObject.Object;
    }
}

void UKJH_GameInstance::OnStart()
{
    Super::OnStart();
    UAudioComponent* audio = UGameplayStatics::SpawnSound2D(GetWorld(), bgm, 0.45f, 1.0f, 0.f, nullptr, true, false);
    audio->Play();
}

void UKJH_GameInstance::SetUserInfo(FString userId, FString userName)
{
    UserId = userId;
    UserName = userName;

    UE_LOG(LogTemp, Warning, TEXT("%s, %s"), *UserId, *UserName);
}
