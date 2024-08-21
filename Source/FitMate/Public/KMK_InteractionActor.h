// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KMK_InteractionActor.generated.h"

// ���͸� Ŭ������ ��, ������ �߰� ����� �ʹ�.
UCLASS()
class FITMATE_API AKMK_InteractionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKMK_InteractionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget>widgetFact;
	UPROPERTY(EditAnywhere, Category = "Widget")
	int layer = 0;
};
