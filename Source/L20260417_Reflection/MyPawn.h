// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "InputActionValue.h"


#include "MyPawn.generated.h"

class UBoxComponent;

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FCountSignature, AMyPawn, OnUpdateCount);


UCLASS()
class L20260417_REFLECTION_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void Rotate(const FInputActionValue& Value);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> Box;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<class UInputAction> IA_Rotate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<class UInputAction> IA_Fire;

	UFUNCTION()
	void ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void ProcessBeginOverlap2(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(BlueprintAssignable, Category = "UMG")
	FCountSignature OnUpdateCount;

	//C++에서 BP 함수 호출 하고 싶어.
	UFUNCTION(BlueprintImplementableEvent)
	void CallCPPToExecuteBP();

	UFUNCTION(BlueprintNativeEvent)
	void CallDefaultCPPToExecuteBP();
	void CallDefaultCPPToExecuteBP_Implementation();

	//BP 함수 제공
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "이건 내가 제공", ScriptName = "Support", Keywords = "Support"))
	void SupportBlueprint();

};



