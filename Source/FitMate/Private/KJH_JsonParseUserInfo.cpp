// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_JsonParseUserInfo.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonWriter.h"
#include "KJH_GameInstance.h"

bool UKJH_JsonParseUserInfo::JsonParseSignUp(const FString& json)
{
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(json);
	TSharedPtr<FJsonObject> response = MakeShareable(new FJsonObject());
	
	if (FJsonSerializer::Deserialize(reader, response))
	{
		bool succeed = response->GetBoolField(TEXT("succeed"));

		return succeed;

		//FString userId = parseData->GetStringField("userId");
		//FString userName = parseData->GetStringField("userName");

		//if (userId.IsEmpty() || userName.IsEmpty())
		//{
		//	return result;
		//}

		//result.Add("UserId", userId);
		//result.Add("UserName", userName);
	}

	return false;
}

TMap<FString, FString> UKJH_JsonParseUserInfo::JsonParseLogin(const FString& json)
{
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(json);
	TSharedPtr<FJsonObject> response = MakeShareable(new FJsonObject());

	TMap<FString, FString> result;
	if (FJsonSerializer::Deserialize(reader, response))
	{
		FString userId = response->GetStringField(TEXT("userName"));
		bool succeed = response->GetBoolField(TEXT("succeed"));

		if (userId.IsEmpty())
		{
			return result;
		}

		result.Add("userId", userId);
		result.Add("succeed", succeed ? TEXT("true") : TEXT("false"));
	}
	return result;
}
