// Fill out your copyright notice in the Description page of Project Settings.


#include "CppGameInstance.h"
#include "Engine/Engine.h"

UCppGameInstance* UCppGameInstance::GetInstance()
{
    UCppGameInstance* instance = nullptr;

    if (GEngine)
    {
        FWorldContext* context = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
        instance = Cast<UCppGameInstance>(context->OwningGameInstance);
    }

    return instance;
}

TArray<FString> UCppGameInstance::GetEnemyBroken()
{
    return GetInstance()->enemyBroken;
}

bool UCppGameInstance::GetIsRun()
{
    return GetInstance()->isRun;
}
