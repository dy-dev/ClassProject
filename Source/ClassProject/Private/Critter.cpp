// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include <Components/StaticMeshComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
ACritter::ACritter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    StaticMeshComponent->SetupAttachment(GetRootComponent());
    
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(GetRootComponent());
    CameraComponent->SetRelativeLocation(FVector(-300,0,300));
    CameraComponent->SetRelativeRotation(FRotator(-45,0,0));

    AutoPossessPlayer = EAutoReceiveInput::Player0;

    MaxSpeed = 650.f;
}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    FVector CurLocation = GetActorLocation() + CurrentVelocity * DeltaTime;
    SetActorLocation(CurLocation);
}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveVertical", this, &ACritter::MoveVertical);
    PlayerInputComponent->BindAxis("MoveHorizontal", this, &ACritter::MoveHorizontal);
}



void  ACritter::MoveVertical(float InValue)
{
    CurrentVelocity.X = FMath::Clamp(InValue, -1.f, 1.f) * MaxSpeed;
}

void  ACritter::MoveHorizontal(float InValue)
{
    CurrentVelocity.Y = FMath::Clamp(InValue, -1.f, 1.f) * MaxSpeed;
}

