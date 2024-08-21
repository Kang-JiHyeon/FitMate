// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "KMK_MakeWidgetComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FITMATE_API UKMK_MakeWidgetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKMK_MakeWidgetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	class AKMK_Player* me;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_Interaction = nullptr;

	void SetupInputBinding(class UEnhancedInputComponent* input);

	void InputInteraction(const struct FInputActionValue& value);
	UPROPERTY()
	int count = 0;
	UPROPERTY()
	class UUserWidget* widget;
	
	UFUNCTION()
	void SetViewPortLayer(UUserWidget* wid, int num);
	UFUNCTION(BlueprintCallable)
	void DeleteMyWidget();

	UPROPERTY(EditAnywhere)
	class UParticleSystem* SelectedParticle;
};
