// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * キャラクターコントローラー
 */
UCLASS()
class ASHIYUROGUELIKE_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPlayerController();

	virtual void BeginPlay() override;
	// void SetupInputComponent() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// bool InputKey(FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad) override;

	// X方向への移動
	void MoveForward(float AxisValue);
	// Y方向への移動
	void MoveRight(float AxisValue);

	// 入力変数
	UPROPERTY(EditAnywhere)
	FVector CurrentVelocity;

	// Called to bind functionality to input
	// virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Initialize();

	AActor* MyActor;
	APawn* MyPawn;
	FVector ForwardVector;

};
