// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorSwitch.h"

#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <TimerManager.h>

// Sets default values
AFloorSwitch::AFloorSwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	RootComponent = TriggerVolume;


	Switch = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch"));
	Switch->SetupAttachment(GetRootComponent());
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(GetRootComponent());

	nbSecondsToClose = 1.f;

}

// Called when the game starts or when spawned
void AFloorSwitch::BeginPlay()
{
	Super::BeginPlay();

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AFloorSwitch::BeginOverlap);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &AFloorSwitch::EndOverlap);

	TriggerVolume->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerVolume->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	TriggerVolume->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerVolume->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	InitialDoorPosition = Door->GetComponentLocation();
	InitialSwitchPosition = Switch->GetComponentLocation();

	bIsOnSwitch = false;
}

void AFloorSwitch::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bIsOnSwitch = true;
	RaiseDoor();
	LowerSwitch();
}

void AFloorSwitch::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bIsOnSwitch = false;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AFloorSwitch::CloseDoorWithDelay, nbSecondsToClose);
}


void AFloorSwitch::CloseDoorWithDelay()
{
	if (!bIsOnSwitch) 
	{
		CloseDoor();
		RaiseSwitch();
	}
}


void AFloorSwitch::UpdateZPopsition(float Position)
{
	FVector Location = InitialDoorPosition;
	Location.Z += Position;

	Door->SetWorldLocation(Location);
}

void AFloorSwitch::UpdateZSwitchPopsition(float Position)
{
	FVector Location = InitialSwitchPosition;
	Location.Z += Position;

	Switch->SetWorldLocation(Location);
}

// Called every frame
void AFloorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

