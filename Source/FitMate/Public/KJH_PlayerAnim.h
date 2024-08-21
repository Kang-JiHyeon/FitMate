// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "KJH_PlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class FITMATE_API UKJH_PlayerAnim : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Speed = 0;
	
};
