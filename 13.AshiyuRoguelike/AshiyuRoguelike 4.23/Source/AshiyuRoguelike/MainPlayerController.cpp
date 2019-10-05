// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

// Sets default values
AMainPlayerController::AMainPlayerController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("output ssss : %s"), L"設定アップ");

}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("output ssss : %s"), L"Begin Play");

	AMainPlayerController::Initialize();
}

// 初期化
void AMainPlayerController::Initialize()
{
	MyActor = GetViewTarget();
	MyActor->InputComponent->BindAxis("MoveForward", this, &AMainPlayerController::MoveForward);
	MyActor->InputComponent->BindAxis("MoveRight", this, &AMainPlayerController::MoveRight);

	MyPawn = GetPawnOrSpectator();
	FVector location = MyPawn->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("output ssss : %s"), *location.ToString());
}

// Called every frame
void AMainPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// // CurrentVelocityに値があるかどうか
	// if (!CurrentVelocity.IsZero())
	// {
	// 		// myPawn->AddMovementInput((CurrentVelocity * DeltaTime), 0);

	// 		FVector NewLocation = MyActor->GetActorLocation() + (CurrentVelocity * DeltaTime);
	// 		// UE_LOG(LogTemp, Warning, TEXT("output ssss : %s"), *NewLocation.ToString());
	// 		MyActor->SetActorLocation(NewLocation);
	// 		// ClientSetLocation_Implementation(NewLocation);
	// }
}

// bool AMainPlayerController::InputKey(FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad)
// {
//   	Super::InputKey(Key, EventType, AmountDepressed, bGamepad);
// 		UE_LOG(LogTemp, Warning, TEXT("output : %s"), *Key.GetDisplayName().ToString());

//     if(Key.GetDisplayName().ToString() == "K")
//     {
// 			UE_LOG(LogTemp, Warning, TEXT("output : %s"), L"入力 X");
// 			AMainPlayerController::Move_XAxis(1);
//     }

//     return bGamepad;
// }

void AMainPlayerController::MoveForward(float axisValue)
{
			UE_LOG(LogTemp, Warning, TEXT("output : %s"), L"X ログ 0");
		// if (AxisValue == 0)
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("output : %s"), L"X ログ 0");
		// 	return;
		// }

		// 1秒間に前後へ200移動。 AxisValue は -1.0fから1.0fの間
    // CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 300.0f;

		FRotator rotate = MyPawn->GetControlRotation();
		// UE_LOG(LogTemp, Warning, TEXT("output : %f"), rotate.Pitch);

		FVector location = MyActor->GetActorForwardVector();
		location.Z += rotate.Yaw;
		// UE_LOG(LogTemp, Warning, TEXT("location x : %s"), location.X.ToString());
		// UE_LOG(LogTemp, Warning, TEXT("location y : %s"), location.Y.ToString());
		// UE_LOG(LogTemp, Warning, TEXT("location z : %s"), location.Z.ToString());

		// FVector location = MyPawn->GetActorLocation();

		MyPawn->AddMovementInput(location, axisValue, true);
}

void AMainPlayerController::MoveRight(float axisValue)
{
		// if (AxisValue == 0)
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("output : %s"), L"Y ログ 0");
		// 	return;
		// }

    // 1秒間に前後へ100移動。 AxisValue は -1.0fから1.0fの間
    // CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 300.0f;

		// FRotator rotate = MyPawn->GetControlRotation();
		// UE_LOG(LogTemp, Warning, TEXT("output : %f"), rotate.Pitch);
		// FVector location = MyPawn->GetActorLocation();
		FVector location = MyActor->GetActorRightVector();

		MyPawn->AddMovementInput(location, axisValue, true);
}
