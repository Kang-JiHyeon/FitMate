// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_MakeWidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"
#include "KMK_InteractionActor.h"
#include "KMK_Player.h"
#include "KMK_ReceipWidget.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../../../../Plugins/FX/Niagara/Source/Niagara/Public/NiagaraFunctionLibrary.h"
#include "../../../../Plugins/FX/Niagara/Source/Niagara/Classes/NiagaraSystem.h"
#include "../../../../Plugins/FX/Niagara/Source/Niagara/Public/NiagaraComponent.h"

// Sets default values for this component's properties
UKMK_MakeWidgetComponent::UKMK_MakeWidgetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKMK_MakeWidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	me = Cast< AKMK_Player>(GetOwner());
}


// Called every frame
void UKMK_MakeWidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UKMK_MakeWidgetComponent::SetupInputBinding(class UEnhancedInputComponent* input)
{
	// Ű�Է� ���ε�
	input->BindAction(IA_Interaction, ETriggerEvent::Triggered, this, &UKMK_MakeWidgetComponent::InputInteraction);
}

void UKMK_MakeWidgetComponent::InputInteraction(const struct FInputActionValue& value)
{

	// ���� Ʈ���̽��� ���� Ŭ���� ������Ʈ�� ����
	FHitResult HitResult;
	me->pc->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	// ��Ʈ�� ������Ʈ�� �ִ��� Ȯ��
	if (HitResult.bBlockingHit)
	{
		// Ŭ���� ������Ʈ�� ���� �޾ƿ���
		AActor* HitActor = HitResult.GetActor();
		if (HitActor)
		{
			FVector ActorLocation = HitActor->GetActorLocation();
			if (HitActor->ActorHasTag("Media"))
			{
				FVector RandomLocation = HitActor->GetActorLocation() + HitActor->GetActorRightVector() * FMath::RandRange(-500.f, 500.f) + HitActor->GetActorUpVector() * FMath::RandRange(-300.f, 300.f);

				GEngine->AddOnScreenDebugMessage(3, 1, FColor::Cyan, FString::Printf(TEXT("HIIII")));
				UNiagaraComponent* pa = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
					GetWorld(),                 // 월드 컨텍스트
					SelectedParticle,           // 나이아가라 시스템
					RandomLocation,             // 위치
					FRotator(0, 45, -20),                // 회전값
					FVector(1.0f),              // 스케일
					true                       // 자동 파괴 여부
				);
				
			}
			count = 0;
			auto* actorClass = Cast<AKMK_InteractionActor>(HitActor);
			if (actorClass)
			{
				widget = CreateWidget(GetWorld(), actorClass->widgetFact);
				if (widget && count < 1)
				{
					if (actorClass->ResWidgetFact && count < 1)
					{
						RecipWidget = CreateWidget(GetWorld(), actorClass->ResWidgetFact);
					}
					SetViewPortLayer(widget, actorClass->layer);
					count++;
				}
			}
			UWidgetComponent* widgetComp = HitActor->FindComponentByClass<UWidgetComponent>();
			if (widgetComp)
			{
				widget = CreateWidget(GetWorld(), widgetComp->GetWidgetClass());
				SetViewPortLayer(widget, 0);
			}
		}
	}
}

// �ܺο��� ȣ��
void UKMK_MakeWidgetComponent::SetViewPortLayer(UUserWidget* wid, int num)
{
	wid->AddToViewport(num);
	me->pc->SetPause(true);
}

void UKMK_MakeWidgetComponent::DeleteMyWidget(UUserWidget* wid)
{
	wid->RemoveFromParent();
	me->pc->SetPause(false);
}
