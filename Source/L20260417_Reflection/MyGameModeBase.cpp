// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

//OOP에서 Property -> 멤버 변수
AMyGameModeBase::AMyGameModeBase()
{
	FString InputValue;
	//실행 중에 클래스의 정보를 가져오는 기능 -> Reflection
	//C++에서 변수 이름 가져오는 방법 있어? 이런 기능의 코드 생성?
	//C++, UE
	//Editor 작업을 하기 위해서
	//for (TFieldIterator<FProperty> Iter(GetClass()); Iter; ++Iter)
	//{
	//	auto Value = *Iter;
	//	//UE_LOG(LogTemp, Warning, TEXT("Property %s"), *Value->GetName());
	//	if (Value->GetName().Equals(InputValue))
	//	{
	//		float* SampleTestValue = Value->ContainerPtrToValuePtr<float>(this);
	//		*SampleTestValue = -11111.0f;
	//	}
	//}

	////멤버 함수
	//for (TFieldIterator<UFunction> Iter(GetClass()); Iter; ++Iter)
	//{
	//	auto Value = *Iter;

	//	UE_LOG(LogTemp, Warning, TEXT("UFunction %s"), *Value->GetName());
	//	if (Value->GetName().Equals(TEXT("TestReflection")))
	//	{
	//		this->ProcessEvent(Value, nullptr);
	//	}
	//}



	
}

void AMyGameModeBase::TestReflection()
{
	UE_LOG(LogTemp, Warning, TEXT("Execute TestReflection"));
}
