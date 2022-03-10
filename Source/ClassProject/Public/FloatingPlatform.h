// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class CLASSPROJECT_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFloatingPlatform();
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Platform")
		class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnyWhere, BlueprintReadonly, Category = "Platform")
		FVector StartPoint;

	UPROPERTY(EditAnyWhere, BlueprintReadonly, meta = (MakeEditWidget = "true"), Category = "Platform")
		FVector EndPoint;

	UPROPERTY(EditAnyWhere, BlueprintReadonly, Category = "Platform")
		float InterpSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadonly, Category = "Platform")
		bool bInterping;

	UPROPERTY(EditAnyWhere, BlueprintReadonly, Category = "Platform")
		float InterpTime;

	UPROPERTY(EditAnyWhere, BlueprintReadonly, Category = "Platform")
		float Distance;

	FTimerHandle InterpTimer;


	void ToggleInterpoling();

	void SwapVector(FVector& VecOne, FVector& VecTwo);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
