// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_Player.h"
#include "../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/InputActionValue.h"
#include "../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"
#include "../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "Camera/CameraActor.h"
#include "GameFramework/PlayerController.h"
#include "KMK_InteractionActor.h"
#include "KMK_MakeWidgetComponent.h"
// Sets default values
AKMK_Player::AKMK_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MakeWidgetComp = CreateDefaultSubobject<UKMK_MakeWidgetComponent>(TEXT("WidgetComp"));
}

// Called when the game starts or when spawned
void AKMK_Player::BeginPlay()
{
	Super::BeginPlay();
    pc = Cast<APlayerController>(Controller);
	pc->bShowMouseCursor = true;
	if (pc)
	{
		UEnhancedInputLocalPlayerSubsystem* subSys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());
		if (subSys)
		{
			subSys->AddMappingContext(IMC_Mapping, 0);
		}
	}
	
}

// Called every frame
void AKMK_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 이동 인풋
	AddMovementInput(dir, speed * DeltaTime);
	dir = FVector::ZeroVector;
}

// Called to bind functionality to input
void AKMK_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// 플레이어 인풋 처리
	auto playerInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	if (playerInput)
	{
		// 움직임 바인딩
		playerInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AKMK_Player::InputMove);
		MakeWidgetComp->SetupInputBinding(playerInput);
	}
}

void AKMK_Player::InputMove(const struct FInputActionValue& value)
{
	FVector2D v = value.Get<FVector2D>();
	dir.X = v.X;
	dir.Y = v.Y;

	dir.Normalize();

}


