// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class CLASSPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

    UPROPERTY (BluePrintReadOnly, VisibleAnywhere, Category ="ActorComponents")
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(EditInstanceOnly, Category = "ActorComponents")
    FVector InitialPosition;
 
    UPROPERTY(EditInstanceOnly, Category = "ActorComponents")
    FVector InitialDirection;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorComponents")
    FVector DropPosition;

    UPROPERTY(EditInstanceOnly, Category = "ActorComponents")
        bool bTeleport;

    UPROPERTY(EditInstanceOnly, Category = "ActorComponents")
        bool bShouldMove;

    UPROPERTY(EditInstanceOnly, Category = "ActorComponents")
        float MovementSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
