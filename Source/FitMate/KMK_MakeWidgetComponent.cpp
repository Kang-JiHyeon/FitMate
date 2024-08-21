// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_MakeWidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "../../../../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"
#include "KMK_InteractionActor.h"
#include "KMK_Player.h"
#include "WidgetFacComponent.h"
#include "Components/WidgetComponent.h"

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
	input->BindAction(IA_Interaction, ETriggerEvent::Triggered, this, &UKMK_MakeWidgetComponent::InputInteraction);
}

void UKMK_MakeWidgetComponent::InputInteraction(const struct FInputActionValue& value)
{
	// GEngine->AddOnScreenDebugMessage(1, 1, FColor::Magenta, FString::Printf(TEXT("click")));
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
			FString ActorName = HitActor->GetName();
			
			UWidgetFacComponent* widgetComp = HitActor->FindComponentByClass<UWidgetFacComponent>();
			if (widgetComp)
			{
				widget = CreateWidget(GetWorld(), widgetComp->WidgetFactory);
				if (widget)
				{
					widget->AddToViewport();
				}
			}
		}
	}
}


// �ܺο��� ȣ��
void UKMK_MakeWidgetComponent::SetViewPortLayer(UUserWidget* wid, int num)
{
	wid->AddToViewport(num);
}