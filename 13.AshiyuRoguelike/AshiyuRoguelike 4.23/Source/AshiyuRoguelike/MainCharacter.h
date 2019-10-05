// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class ASHIYUROGUELIKE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere) USceneComponent* OurVisibleComponent;

	// X方向への移動
	void Move_XAxis(float AxisValue);
	// Y方向への移動
	void Move_YAxis(float AxisValue);

	// 入力変数
	FVector CurrentVelocity;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	int32 TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	float DamageTimeInSeconds;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category="Damage")
	float DamagePerSecond;

};
