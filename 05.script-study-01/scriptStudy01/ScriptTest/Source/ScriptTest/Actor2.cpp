// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor2.h"

// Sets default values
AActor2::AActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AActor2::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

