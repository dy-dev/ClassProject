// Fill out your copyright notice in the Description page of Project Settings.

#include <Components/SphereComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Particles/ParticleSystemComponent.h>
#include <Kismet/GameplayStatics.h>
#include <Sound/SoundCue.h>

#include <Engine/World.h>


#include "Item.h"

// Sets default values
AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(GetRootComponent());
	IdleParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("IdleParticleSystemComponent"));
	IdleParticleSystemComponent->SetupAttachment(GetRootComponent());

	bRotate = false;
	RotationRate = 45.0f;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AItem::BeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AItem::EndOverlap);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bRotate)
	{
		FRotator ActorRotation = GetActorRotation();
		ActorRotation.Yaw += RotationRate * DeltaTime;
		SetActorRotation(ActorRotation);
	}
}



void AItem::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OverlapParticleSystem)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticleSystem, GetActorLocation(), FRotator(0.f), true);
	}

	if (OverlapSoundCue)
	{
		UGameplayStatics::PlaySound2D(this, OverlapSoundCue);
	}
	Destroy();
}

void AItem::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
