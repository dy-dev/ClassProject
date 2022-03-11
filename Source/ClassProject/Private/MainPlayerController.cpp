// Fill out your copyright notice in the Description page of Project Settings.

#include <Blueprint/UserWidget.h>

#include "MainPlayerController.h"



AMainPlayerController::AMainPlayerController()
{
	Health = 150.f;
	MaxHealth = 200.f;
	Stamina = 190.f;
	MaxStamina = 320.f;
	CoinsCount = 0;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (HUDOverlayAsset)
	{
		HudOverlayWidget = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
	}
	if (HudOverlayWidget)
	{
		HudOverlayWidget->AddToViewport();
		HudOverlayWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMainPlayerController::DecrementHealth(float Amount)
{
	Health -= Amount;
	if (Health < 0)
	{
		Health = 0;
		Die();
	}
}

void AMainPlayerController::Die()
{
}

void AMainPlayerController::AddCoins(int32 Value)
{
	CoinsCount += Value;
}
