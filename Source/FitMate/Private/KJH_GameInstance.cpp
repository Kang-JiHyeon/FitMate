// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_GameInstance.h"

void UKJH_GameInstance::SetUserInfo(FString userId, FString userName)
{
    UserId = userId;
    UserName = userName;
    
    UE_LOG(LogTemp, Warning, TEXT("%s, %s"), *UserId, *UserName);
}
