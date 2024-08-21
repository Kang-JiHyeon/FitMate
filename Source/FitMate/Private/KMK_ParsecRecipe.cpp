// Fill out your copyright notice in the Description page of Project Settings.


#include "KMK_ParsecRecipe.h"

TMap<FString, FString> UKMK_ParsecRecipe::RecipeJsonParsec(const FString& json, FString ingredient)
{
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(json);
	TSharedPtr<FJsonObject> response = MakeShareable(new FJsonObject());

	TMap<FString, FString> result;

	if (FJsonSerializer::Deserialize(reader, response))
	{
		FString menu = response->GetStringField("food_name");
		FString recipe = response->GetStringField("recipe");

		// 서버에서 주는 주소값
		result.Add("Menu", menu);
		result.Add("ingred", ingredient);
		result.Add("recipe", recipe);
	}
	return result;
}
