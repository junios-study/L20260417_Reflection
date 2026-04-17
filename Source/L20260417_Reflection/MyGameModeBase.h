// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class L20260417_REFLECTION_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameModeBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float TestValue;


	UFUNCTION()
	void TestReflection();

	//C++ class 이름을 등록하거나 이름으로 생성하는게 런타임중 X
	//class를 이름 등록
	//Mean 그냥 클래스 이름을 알고 싶다. 
	TSubclassOf<AActor> AActorTemplate;
	//new AActorTemplate
};
