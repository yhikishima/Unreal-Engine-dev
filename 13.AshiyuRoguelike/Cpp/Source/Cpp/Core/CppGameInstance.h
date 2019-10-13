// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CppGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPP_API UCppGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    static UCppGameInstance* GetInstance();
    static bool GetIsRun();
    static TArray<FString> GetEnemyBroken();

public:
    UPROPERTY(EditAnywhere)
    bool isRun;

    UPROPERTY(EditAnywhere)
    TArray<FString> enemyBroken;
};
