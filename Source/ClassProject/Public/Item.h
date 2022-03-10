// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class CLASSPROJECT_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();

	UPROPERTY(Visibleanywhere, BlueprintReadWrite, Category = "Item| collision")
		class USphereComponent* SphereComponent;

	UPROPERTY(Visibleanywhere, BlueprintReadWrite, Category = "Item| collision")
		class UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(Visibleanywhere, BlueprintReadWrite, Category = "Item| collision")
		class UParticleSystemComponent* IdleParticleSystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item| collision")
		class UParticleSystem* OverlapParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item| collision")
		class USoundCue* OverlapSoundCue;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item| ItemProperties")
		bool bRotate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item| ItemProperties")
		float RotationRate;

	UFUNCTION()
		virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
