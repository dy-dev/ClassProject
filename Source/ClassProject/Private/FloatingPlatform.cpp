// Fill out your copyright notice in the Description page of Project Settings.

#include <Components/StaticMeshComponent.h>
#include "FloatingPlatform.h"

// Sets default values
AFloatingPlatform::AFloatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
	EndPoint = FVector(0.f);

	InterpSpeed = 1.0f;
	bInterping = true;
	InterpTime = 1.f;
}

// Called when the game starts or when spawned
void AFloatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	Distance = EndPoint.Size();

	StartPoint = GetActorLocation();
	EndPoint += StartPoint;
}

// Called every frame
void AFloatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bInterping)
	{
		FVector Interp = FMath::VInterpTo(GetActorLocation(), EndPoint, DeltaTime, InterpSpeed);
		SetActorLocation(Interp);
		if (Distance < (GetActorLocation() - StartPoint).Size() + 1.f) {
			ToggleInterpoling();
			SwapVector(StartPoint, EndPoint);
			GetWorldTimerManager().SetTimer(InterpTimer, this, &AFloatingPlatform::ToggleInterpoling, InterpTime);
		}
	}
}


void AFloatingPlatform::ToggleInterpoling()
{
	bInterping = !bInterping;
}

void AFloatingPlatform::SwapVector(FVector& VecOne, FVector& VecTwo)
{
	FVector tmp = VecOne;
	VecOne = VecTwo;
	VecTwo = tmp;
}
