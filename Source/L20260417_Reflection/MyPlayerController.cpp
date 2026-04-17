// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "MyPawn.h"

void AMyPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	//차도 조정, 배도 조정, 사람도 조정
	//1. SubSystem, 자동 싱글턴, 
	//2. 향상된 입력, Sub System임.
	//3. 그래서 아래 코드 쓴다.
	//Get SubSystem, why, 향상된 입력도 서브 시스템임, 입력 장치는 하나만 있으니깐

	//network에 사용 할 코드
	if (!IsLocalPlayerController())
	{
		return;
	}

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem*  MySubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (MySubsystem)
	{

		MySubsystem->ClearAllMappings();
		//for (int i = 0; i < IMC_Defaults.Num(); ++i)
		//{
		//	MySubsystem->AddMappingContext(IMC_Defaults[i], 0);
		//}

		for (const auto& Context : IMC_Defaults)
		{
			MySubsystem->AddMappingContext(Context.LoadSynchronous(), 0);
			//MySubsystem->AddMappingContext(Context.LoadAsync(), 0);
		}
	}

	AMyPawn* MyPawn = Cast<AMyPawn>(aPawn);
	if (MyPawn)
	{
		MyPawn->OnUpdateCount.RemoveAll(this);
		MyPawn->OnUpdateCount.AddDynamic(this, &AMyPlayerController::DisplayCount);
	}
}

void AMyPlayerController::DisplayCount()
{
	UE_LOG(LogTemp, Warning, TEXT("DisplayCount"));
}
