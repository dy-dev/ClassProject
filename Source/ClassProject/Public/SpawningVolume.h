// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawningVolume.generated.h"

UCLASS()
class CLASSPROJECT_API ASpawningVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawningVolume();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
		class UBoxComponent* SpawningBox;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Spawning")
		TSubclassOf<class ACritter> PawnToSpawn;

	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetSpawningPoint();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawning")
		void SpawnOurPawn(UClass * ToSpawn, const FVector& Location);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
