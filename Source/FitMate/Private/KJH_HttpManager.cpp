// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_HttpManager.h"
#include "HttpModule.h"
#include "JsonParseLib.h"
#include "KJH_JsonParseUserInfo.h"
#include "KJH_GameInstance.h"
#include "KMK_ParsecRecipe.h"
#include "KMK_MakeWidgetComponent.h"
#include "KMK_ReceipWidget.h"


// Sets default values
AKJH_HttpManager::AKJH_HttpManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AKJH_HttpManager::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UKJH_GameInstance>(GetWorld()->GetGameInstance());
}

/// <summary>
/// 회원가입 요청
/// </summary>
/// <param name="SubUrl"></param>
/// <param name="Json"></param>
void AKJH_HttpManager::ReqSignUp(FString Password, FString UserName)
{
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	TMap<FString, FString> data;
	data.Add(TEXT("userPass"), Password);
	data.Add(TEXT("userName"), UserName);

	// 요청 정보
	req->SetURL(GetURL(TEXT("signup")));
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	req->SetContentAsString(UJsonParseLib::MakeJson(data));

	// 응답받을 함수
	req->OnProcessRequestComplete().BindUObject(this, &AKJH_HttpManager::OnResSignUp);
	// 서버에 요청
	req->ProcessRequest();
}

/// <summary>
/// 로그인 요청
/// </summary>
/// <param name="Json"></param>
void AKJH_HttpManager::ReqLogin(FString Id, FString Password)
{
	// Http 모듈을 생성
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	TMap<FString, FString> data;
	data.Add(TEXT("userName"), Id);
    data.Add(TEXT("userPass"), Password);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *UJsonParseLib::MakeJson(data));

	// 요청 정보
	req->SetURL(GetURL(TEXT("login")));
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	req->SetContentAsString(UJsonParseLib::MakeJson(data));

	// 응답받을 함수
	req->OnProcessRequestComplete().BindUObject(this, &AKJH_HttpManager::OnResLogin);
	// 서버에 요청
	req->ProcessRequest();
}

/// <summary>
/// 회원가입 응답
/// </summary>
/// <param name="Request"></param>
/// <param name="Response"></param>
/// <param name="bConnectedSuccessfully"></param>
void AKJH_HttpManager::OnResSignUp(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Warning, TEXT("OnResSignUp Call!!"));

	bool result = false;
	if (bConnectedSuccessfully)
	{
		FString res = Response->GetContentAsString();
		result = UKJH_JsonParseUserInfo::JsonParseSignUp(res);

		UE_LOG(LogTemp, Warning, TEXT("OnResSignUp result : \n%d "), result);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnResSignUp Failed!!"));
	}

	OnResponseRegister.Broadcast(result);
}

/// <summary>
/// 로그인 응답
/// </summary>
/// <param name="Request"></param>
/// <param name="Response"></param>
/// <param name="bConnectedSuccessfully"></param>
void AKJH_HttpManager::OnResLogin(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Warning, TEXT("OnResLogin Call!!"));

	bool bSuccessed = false;
	if (bConnectedSuccessfully)
    {
        FString res = Response->GetContentAsString();
		TMap<FString, FString> result = UKJH_JsonParseUserInfo::JsonParseLogin(res);

		if (!result.IsEmpty() || result.Contains(TEXT("userId")) || result.Contains(TEXT("succeed")))
		{
			bSuccessed = result[TEXT("succeed")] == TEXT("true");
			GameInstance->SetUserInfo(result[TEXT("userId")]);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("OnResLogin Empty!!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnResLogin Failed!!"));
	}

	OnResponseLogin.Broadcast(bSuccessed);
}

#pragma region KMK

FString url;
void AKJH_HttpManager::ReqIngredient(FString Ingredients)
{
	FString tocken;
	// Http 모듈을 생성
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();
	dataSet = Ingredients;
	TMap<FString, FString> data;
	FString originalString = Ingredients;
	FString modifiedString = originalString.Replace(TEXT(" "), TEXT(""));

	data.Add(TEXT("ingredient"), modifiedString);

	// 요청 정보
	req->SetURL(GetURL(TEXT("result")));
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	req->SetContentAsString(UJsonParseLib::MakeJson(data));

	// 응답받을 함수
	req->OnProcessRequestComplete().BindUObject(this, &AKJH_HttpManager::OnResIngredients);
	// 서버에 요청
	req->ProcessRequest();
}

void AKJH_HttpManager::OnResIngredients(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		FString respon = Response->GetContentAsString();
		TMap<FString, FString> result = UKMK_ParsecRecipe::RecipeJsonParsec(respon, dataSet);
        // GEngine->AddOnScreenDebugMessage(3, 10, FColor::Blue, FString::Printf(TEXT("%s"), *respon));
        UE_LOG(LogTemp, Warning, TEXT("OnResIngredient Successed!! : \n%s "), *respon);
		// 플레이어 컴포넌트에 보내줘야함
		auto* playerComp = GetWorld()->GetFirstPlayerController()->GetPawn()->FindComponentByClass<UKMK_MakeWidgetComponent>();
		if (playerComp)
		{
			playerComp->DeleteMyWidget(playerComp->widget);
			playerComp->SetViewPortLayer(playerComp->RecipWidget, 2);
			auto* logWidget = Cast<UKMK_ReceipWidget>(playerComp->RecipWidget);
			logWidget->SetTextLog(result);
		}

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnResIngredient Failed!!"));
	}
}
#pragma endregion