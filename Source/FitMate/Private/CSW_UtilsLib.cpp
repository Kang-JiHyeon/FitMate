// Fill out your copyright notice in the Description page of Project Settings.


#include "CSW_UtilsLib.h"



void UCSW_UtilsLib::OnClearHabit(int32 Num)
{
	FString FilePath = FPaths::ProjectPersistentDownloadDir() + "/Habit.txt";
	FString OutContent;
	FString InContent = FString::FromInt(Num);
	
	FFileHelper::LoadFileToString(OutContent, *FilePath);

	for (int i = 0; i < OutContent.Len(); i++)
		if (OutContent[i] == InContent[0])
			return ;
	InContent = OutContent + InContent;
	FFileHelper::SaveStringToFile(InContent, *FilePath);
}

int32 UCSW_UtilsLib::PlusPoint(int32 Num)
{
	FString FilePath = FPaths::ProjectPersistentDownloadDir() + "/Point.txt";
	int32 point = Num + ReadPoint();
	FString InContent = FString::FromInt(point);
	
	FFileHelper::SaveStringToFile(InContent, *FilePath);

	return point;
}

int32 UCSW_UtilsLib::MinusPoint(int32 Num)
{
	FString FilePath = FPaths::ProjectPersistentDownloadDir() + "/Point.txt";
	int32 point = ReadPoint() - Num;
	FString InContent = FString::FromInt(point);
	
	FFileHelper::SaveStringToFile(InContent, *FilePath);

	return point;
}

TArray<int32> UCSW_UtilsLib::GetClearHabits()
{
	FString FilePath = FPaths::ProjectPersistentDownloadDir() + "/Habit.txt";
	FString OutContent;
	TArray<int32> ret;

	FFileHelper::LoadFileToString(OutContent, *FilePath);
	for (int i = 0; i < OutContent.Len(); i++)
		ret.Add(OutContent[i] - '0');
	return ret;
}

int32 UCSW_UtilsLib::ReadPoint()
{
	FString FilePath = FPaths::ProjectPersistentDownloadDir() + "/Point.txt";
	FString OutContent = "0";

	FFileHelper::LoadFileToString(OutContent, *FilePath);
	return FCString::Atoi(*OutContent);
}
