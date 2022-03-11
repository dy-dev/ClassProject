// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "MainPlayerController.h"
#include "Pickup.h"

APickup::APickup()
{
	CoinsCount = 1;
}

void APickup::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::BeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (OtherActor)
	{
		AMainCharacter* Main = Cast< AMainCharacter>(OtherActor);
		if (Main)
		{
			AMainPlayerController* MainPlayerController = Cast< AMainPlayerController>(Main->GetController());
			if (MainPlayerController)
			{
				MainPlayerController->AddCoins(CoinsCount);
			}
		}
	}
}

void APickup::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::EndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	
}
