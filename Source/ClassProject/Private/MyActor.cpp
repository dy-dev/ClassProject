// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    RunningTime = 0;
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    DropPosition = GetActorLocation();

    if (bTeleport)
        SetActorLocation(InitialPosition);


    if (bApplyForce)
        StaticMesh->AddForce(InitialForce);
    if (bApplyTorque)
        StaticMesh->AddTorque(InitialTorque);

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FHitResult HitResult;
    FVector Position = DropPosition;
    if (bShouldMove) {
        auto tmp = InitialDirection;
        tmp.Normalize();
        AddActorLocalOffset(MovementSpeed * tmp, true, &HitResult);
        UE_LOG(LogTemp, Warning, TEXT("%f, %f, %f"), HitResult.Location.X,
            HitResult.Location.Y, HitResult.Location.Z);
        Position = GetActorLocation();
    }

    if (bShouldRotate) {
        AddActorLocalRotation(RotationAxis, false, &HitResult);
    }                

    if (bShouldOscillate) {
        auto tmp = OscillationDirection;
        tmp.Normalize();
        
        if (bShouldMove)
            SetActorLocation(Position + tmp * OscillationAmplitude * (FMath::Sin(OscillationFrequency * RunningTime+DeltaTime) - FMath::Sin(OscillationFrequency * RunningTime) ));
        else
            SetActorLocation(Position + tmp * OscillationAmplitude * FMath::Sin(OscillationFrequency * RunningTime));
    }
    RunningTime += DeltaTime;

}

