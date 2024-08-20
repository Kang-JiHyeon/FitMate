// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_HttpManager.h"
#include "HttpModule.h"
#include "JsonParseLib.h"
#include "KJH_JsonParseUserInfo.h"

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

	//TMap<FString, FString> data;

	//// ȸ������
 //   data.Add("userId", "user02");
 //   data.Add("userPass", "pass01");
 //   data.Add("userName", "Kang02");
 //   data.Add("userEmail", "user01@naver.com");
 //   data.Add("role", "USER");

	////ReqSignUp(UJsonParseLib::MakeJson(data));

	////// �α���
 //   //data.Add("id", "user02");
 //   //data.Add("pass", "pass01");
 //   //ReqLogin(UJsonParseLib::MakeJson(data));

	//UE_LOG(LogTemp, Warning, TEXT("Request Data : %s"), *UJsonParseLib::MakeJson(data));
}

/// <summary>
/// ȸ������ ��û
/// </summary>
/// <param name="SubUrl"></param>
/// <param name="Json"></param>
void AKJH_HttpManager::ReqSignUp(FString Id, FString Password, FString UserName)
{
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	TMap<FString, FString> data;
	data.Add("userId", Id);
	data.Add("userPass", Password);
	data.Add("userName", UserName);
	data.Add("userEmail", "user01@naver.com");
	data.Add("role", "USER");

	// ��û ����
	req->SetURL(GetURL("signup"));
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	req->SetContentAsString(UJsonParseLib::MakeJson(data));

	// ������� �Լ�
	req->OnProcessRequestComplete().BindUObject(this, &AKJH_HttpManager::OnResSignUp);
	// ������ ��û
	req->ProcessRequest();
}

/// <summary>
/// �α��� ��û
/// </summary>
/// <param name="Json"></param>
void AKJH_HttpManager::ReqLogin(FString Id, FString Password)
{
	// Http ����� ����
	FHttpModule& httpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();

	TMap<FString, FString> data;
	data.Add("id", Id);
    data.Add("pass", Password);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *UJsonParseLib::MakeJson(data));


	// ��û ����
	req->SetURL(GetURL("login"));
	req->SetVerb(TEXT("PUT"));
	req->SetHeader(TEXT("content-type"), TEXT("application/json"));
	req->SetContentAsString(UJsonParseLib::MakeJson(data));

	// ������� �Լ�
	req->OnProcessRequestComplete().BindUObject(this, &AKJH_HttpManager::OnResLogin);
	// ������ ��û
	req->ProcessRequest();
}

/// <summary>
/// ȸ������ ����
/// </summary>
/// <param name="Request"></param>
/// <param name="Response"></param>
/// <param name="bConnectedSuccessfully"></param>
void AKJH_HttpManager::OnResSignUp(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Warning, TEXT("OnResSignUp Call!!"));

	if (bConnectedSuccessfully)
	{
		FString result = Response->GetContentAsString();

		UE_LOG(LogTemp, Warning, TEXT("OnResSignUp Successed!! : \n%s "), *result);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnResSignUp Failed!!"));
	}
}

/// <summary>
/// �α��� ����
/// </summary>
/// <param name="Request"></param>
/// <param name="Response"></param>
/// <param name="bConnectedSuccessfully"></param>
void AKJH_HttpManager::OnResLogin(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Warning, TEXT("OnResLogin Call!!"));

	if (bConnectedSuccessfully)
    {
        FString res = Response->GetContentAsString();
		FString result = UKJH_JsonParseUserInfo::JsonParse(res);

		if (result.IsEmpty() == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("OnResLogin Successed!! : \n%s "), *result);
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

}

