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

	/** Short Comments need to be added to ercxplain those information */
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


	void DecrementHealth(float Amount);
	void Die();
	void AddCoins(int32 Value);


protected:
	void BeginPlay() override;
};
