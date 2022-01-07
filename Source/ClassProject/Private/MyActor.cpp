// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    DropPosition = GetActorLocation();

    if (bTeleport)
        SetActorLocation(InitialPosition);


}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


    if (bShouldMove) {
        FHitResult HitResult;
        AddActorLocalOffset(MovementSpeed * InitialDirection, true, &HitResult);
        UE_LOG(LogTemp, Warning, TEXT("%f, %f, %f"), HitResult.Location.X,
            HitResult.Location.Y, HitResult.Location.Z);
    }


}

