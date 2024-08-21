// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_ParsecRecipe.h"

TMap<int, FString> UKMK_ParsecRecipe::RecipeJsonParsec(const FString& json)
{
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(json);
	TSharedPtr<FJsonObject> response = MakeShareable(new FJsonObject());

	TMap<int, FString> result;
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
			result.Add(0, menu);
			result.Add(1, ingredient);
			result.Add(2, recipe);
		}
	}
	return result;
}
