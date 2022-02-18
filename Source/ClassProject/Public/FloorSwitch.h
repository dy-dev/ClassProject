// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

UCLASS()
class CLASSPROJECT_API AFloorSwitch : public AActor
{
	GENERATED_BODY()

private:
	FTimerHandle TimerHandle;

	void CloseDoorWithDelay();

public:
	// Sets default values for this actor's properties
	AFloorSwitch();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UBoxComponent* TriggerVolume;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Switch;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Door;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector InitialSwitchPosition;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector InitialDoorPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float nbSecondsToClose;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bIsOnSwitch;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category = "FloorSwitch")
		void RaiseDoor();
	UFUNCTION(BlueprintImplementableEvent, Category = "FloorSwitch")
		void CloseDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "FloorSwitch")
		void RaiseSwitch();
	UFUNCTION(BlueprintImplementableEvent, Category = "FloorSwitch")
		void LowerSwitch();

	UFUNCTION(BlueprintCallable, Category = "FloorSwitch")
		void UpdateZPopsition(float Position);
	UFUNCTION(BlueprintCallable, Category = "FloorSwitch")
		void UpdateZSwitchPopsition(float Position);




public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
