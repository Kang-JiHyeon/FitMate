// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_JsonParseUserInfo.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonWriter.h"
#include "KJH_GameInstance.h"

TMap<FString, FString> UKJH_JsonParseUserInfo::JsonParse(const FString& json)
{
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(json);
	TSharedPtr<FJsonObject> response = MakeShareable(new FJsonObject());

	TMap<FString, FString> result;
	if (FJsonSerializer::Deserialize(reader, response))
	{
		TSharedPtr<FJsonObject> parseData = response->GetObjectField(TEXT("userInfo"));

		if (parseData == nullptr)
		{
			return result;
		}

		FString userId = parseData->GetStringField("userId");
		FString userName = parseData->GetStringField("userName");

		if (userId.IsEmpty() || userName.IsEmpty())
		{
			return result;
		}

		result.Add("UserId", userId);
		result.Add("UserName", userName);
	}
	return result;
}
