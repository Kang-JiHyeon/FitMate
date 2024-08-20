// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_JsonParseUserInfo.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonWriter.h"

FString UKJH_JsonParseUserInfo::JsonParse(const FString& json)
{
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(json);
	TSharedPtr<FJsonObject> response = MakeShareable(new FJsonObject());

	FString result;
	if (FJsonSerializer::Deserialize(reader, response))
	{
		TArray<TSharedPtr<FJsonValue>> parseDataList = response->GetArrayField(TEXT("userInfo"));

		if (parseDataList.Num() <= 0)
		{
			return result;
		}

		for (TSharedPtr<FJsonValue> data : parseDataList)
		{
			FString userName = data->AsObject()->GetStringField("userName");
			FString userId = data->AsObject()->GetStringField("userId");
			result.Append(FString::Printf(TEXT("userName : %s / userId : %s\n"), *userName, *userId));
		}
	}
	return result;
}
