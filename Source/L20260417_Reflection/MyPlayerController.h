// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class L20260417_REFLECTION_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void OnPossess(APawn* aPawn) override;


	//TArray<TObjectPtr<UInputMappingContext>> IMC_Defaults;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TArray<TSoftObjectPtr<UInputMappingContext>> IMC_Defaults;


};
