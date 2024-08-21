// Fill out your copyright notice in the Description page of Project Settings.


#include "KJH_FileDialogLib.h"
#include "DesktopPlatformModule.h"


FString UKJH_FileDialogLib::OpenFileDialog()
{
    FString FilePath;

    IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();

    if (DesktopPlatform)
    {
        TArray<FString> OutFiles;
        bool bOpened = DesktopPlatform->OpenFileDialog(
            nullptr, // Parent Window Handle
            TEXT("Select Video File"), // Dialog Title
            FPaths::ProjectDir(), // Default Directory
            TEXT(""), // Default File
            TEXT("Video Files (*.mp4; *.avi; *.mov)|*.mp4;*.avi;*.mov"), // File Types
            EFileDialogFlags::None,
            OutFiles // Array to store the selected file paths
        );

        if (bOpened && OutFiles.Num() > 0)
        {
            FilePath = OutFiles[0]; // Select the first file
        }
    }

    return FilePath;
}
