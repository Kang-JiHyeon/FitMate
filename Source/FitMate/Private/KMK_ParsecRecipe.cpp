// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_ParsecRecipe.h"

TMap<FString, FString> UKMK_ParsecRecipe::RecipeJsonParsec(const FString& json)
{
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(json);
	TSharedPtr<FJsonObject> response = MakeShareable(new FJsonObject());

	TMap<FString, FString> result;

	if (FJsonSerializer::Deserialize(reader, response))
	{
		// 받아오는 값
		TArray<TSharedPtr<FJsonValue>> parseDataList = response->GetArrayField(TEXT("ingredients"));

		if (parseDataList.Num() <= 0)
		{
			return result;
		}

		for (TSharedPtr<FJsonValue> data : parseDataList)
		{
			FString menu = data->AsObject()->GetStringField("Menu");
			FString ingredient = data->AsObject()->GetStringField("ingredient");
			FString recipe = data->AsObject()->GetStringField("Recipe");
			// 서버에서 주는 주소값
			result.Add("menu", menu);
			result.Add("", ingredient);
			result.Add("", recipe);
		}
	}
	return result;
}
