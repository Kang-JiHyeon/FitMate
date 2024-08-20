// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KMK_Player.generated.h"

UCLASS()
class FITMATE_API AKMK_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKMK_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 컴포넌트 제작
	UPROPERTY(EditDefaultsOnly)
	class UKMK_MakeWidgetComponent* MakeWidgetComp;
	// 플레이어 움직임
#pragma region InputKey
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* IMC_Mapping = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_Move = nullptr;

#pragma endregion
#pragma region Function
	void InputMove(const struct FInputActionValue& value);
#pragma endregion
#pragma region Variables

	FVector dir;
	UPROPERTY(EditAnywhere, Category = "Speed")
	float speed = 600;

	APlayerController* pc;
#pragma endregion


};
