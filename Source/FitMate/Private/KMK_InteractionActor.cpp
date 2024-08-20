// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_InteractionActor.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AKMK_InteractionActor::AKMK_InteractionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AKMK_InteractionActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AKMK_InteractionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

