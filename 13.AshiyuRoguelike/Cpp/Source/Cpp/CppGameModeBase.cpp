// Fill out your copyright notice in the Description page of Project Settings.

#include "CppGameModeBase.h"
#include "Core/MainCharacter.h"

ACppGameModeBase::ACppGameModeBase()
{
//    this. = GetWorld()->SpawnActor<AActor>(Chara001Class , SpawnInfo);

//    TArray<AActor*> FoundActors;
//    UE_LOG(LogTemp, Log, TEXT("MyValue"));
//    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);
//
//
//    for (auto Actor : FoundActors)
//    {
//        UE_LOG(LogTemp, Log, TEXT("MyValue=%d"), Actor);
//
//        ACharacter* AnyActor = Cast<ACharacter>(Actor);
//        if (AnyActor)
//        {
////            DefaultPawnClass = AnyActor;
//        }
//    }

//    ACharacter* AnyActor = Cast<ACharacter>(Actor);


    DefaultPawnClass = AMainCharacter::StaticClass();
}