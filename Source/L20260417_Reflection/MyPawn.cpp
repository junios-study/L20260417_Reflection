// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/BoxComponent.h"
#include "EnhancedInputComponent.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	UE_LOG(LogTemp, Warning, TEXT("AMyPawn"));

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AMyPawn::ProcessBeginOverlap2);
	OnActorBeginOverlap.AddDynamic(this, &AMyPawn::ProcessBeginOverlap);
	OnActorBeginOverlap.RemoveDynamic(this, &AMyPawn::ProcessBeginOverlap2);


	//점수 계산 로직, 데미지 계산
	//CallCPPToExecuteBP();

	CallDefaultCPPToExecuteBP();

}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//HP 바뀌면 호출 해줘.
	OnUpdateCount.Broadcast();
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UIC)
	{
		UIC->BindAction(IA_Rotate, ETriggerEvent::Triggered, this, &AMyPawn::Rotate);
	}

}

void AMyPawn::Rotate(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Value.ToString());
}


void AMyPawn::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("ProcessBeginOverlap"));
}

void AMyPawn::ProcessBeginOverlap2(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("ProcessBeginOverlap2"));

}

void AMyPawn::CallDefaultCPPToExecuteBP_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("이건 CPP에서 기본 구현"));
}

void AMyPawn::SupportBlueprint()
{
	UE_LOG(LogTemp, Warning, TEXT("이건 CPP에서 BP에 제공"));
}

