// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// このポーンが最小値のプレイヤーで制御されるように設定。0番目のプレイヤー
	AutoPossessPlayer = EAutoReceiveInput::Player0;


	TotalDamage = 200;
	DamageTimeInSeconds = 1.f;


// // 親子付可能なダミーのルートコンポーネント
// 	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
// 	// カメラオブジェクト作成
// 	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
// 	// 可視オブジェクトを作成
// 	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

// 	// カメラをRootComponent以下へぶら下げる
// 	OurCamera->AttachTo(RootComponent);
// 	// カメラ位置を調整
// 	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
// 	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

// 	// 可視オブジェクトをRootComponentにぶら下げ
// 	OurVisibleComponent->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		// CurrentVelocityに値があるかどうか
    if (!CurrentVelocity.IsZero())
    {
        FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			 	UE_LOG(LogTemp, Warning, TEXT("output : %s"), L"動いた");

        SetActorLocation(NewLocation);
    }
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Warning, TEXT("output : %s"), L"セットアップ");

	InputComponent->BindAxis("MoveX", this, &AMainCharacter::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &AMainCharacter::Move_YAxis);
}

void AMainCharacter::Move_XAxis(float AxisValue) {
		UE_LOG(LogTemp, Warning, TEXT("output : %s"), L"X ログ");

    // 1秒間に前後へ100移動。 AxisValue は -1.0fから1.0fの間
    CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMainCharacter::Move_YAxis(float AxisValue) {
		UE_LOG(LogTemp, Warning, TEXT("output : %s"), L"Y ログ");

    // 1秒間に左右へ100移動。 AxisValue は -1.0fから1.0fの間
    CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

