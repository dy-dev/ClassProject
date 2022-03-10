// Fill out your copyright notice in the Description page of Project Settings.

#include <Components/BoxComponent.h>
#include <Kismet/KismetMathLibrary.h>
#include <Engine/World.h>
#include "Critter.h"
#include "SpawningVolume.h"

// Sets default values
ASpawningVolume::ASpawningVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(GetRootComponent());
}



// Called when the game starts or when spawned
void ASpawningVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawningVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawningVolume::GetSpawningPoint()
{
	FVector Origin = SpawningBox->GetComponentLocation();
	FVector Extent = SpawningBox->GetScaledBoxExtent();

	return UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extent);
}

void ASpawningVolume::SpawnOurPawn_Implementation(UClass* ToSpawn, const FVector& Location)
{
	if (ToSpawn) 
	{
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParameters;
			ACritter* Critter = World->SpawnActor<ACritter>(ToSpawn, Location, FRotator(0.f), SpawnParameters);
		}
	}
}
