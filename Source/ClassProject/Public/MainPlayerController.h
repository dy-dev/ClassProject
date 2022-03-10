// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CLASSPROJECT_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	AMainPlayerController();
	/** Reference to the UMG asset in editor*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> HUDOverlayAsset;
	
	/** Variable referecing HUD widget once created*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		UUserWidget* HudOverlayWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	float Health;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	float MaxHealth;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	float Stamina;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	float MaxStamina;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	int32 CoinsCount;


protected:
	void BeginPlay() override;
};
