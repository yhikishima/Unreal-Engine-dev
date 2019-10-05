// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase()
{
  UBlueprint* BulletBP = FindObject<UBlueprint>(NULL, TEXT("/Game/BluePrints/BP_Character"));
 AActor* targetActor = GetWorld()->SpawnActor(BulletBP->GeneratedClass);
//
  // APawn* targetPawn =

//  DefaultPawnClass = targetActor;
}