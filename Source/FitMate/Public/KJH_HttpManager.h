// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "KJH_HttpManager.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateHttpManagerOnResponseLogin, bool)
DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateHttpManagerOnResponseRegister, bool)

UCLASS()
class FITMATE_API AKJH_HttpManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKJH_HttpManager();

	FDelegateHttpManagerOnResponseLogin OnResponseLogin;
	FDelegateHttpManagerOnResponseRegister OnResponseRegister;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	class UKJH_GameInstance* GameInstance;

	// ¼­¹ö URL
	const FString ServerURL = "192.168.1.49:8080/";
	const FString GetURL(FString SubUrl) { return ServerURL + SubUrl;};


public:
	void ReqSignUp(FString Id, FString Password);
	void ReqLogin(FString Id, FString Password);
	
#pragma region Food with AI
	void ReqIngredient(FString Ingredients);
	FString dataSet;
#pragma endregion


private:
	void OnResSignUp(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	void OnResLogin(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
#pragma region Food with AI
	void OnResIngredients(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
#pragma endregion
};
