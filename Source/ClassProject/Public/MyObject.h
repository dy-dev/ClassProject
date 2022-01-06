// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CLASSPROJECT_API UMyObject : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MyValues")
    float Myfloat;
    
    UFUNCTION(BlueprintCallable, Category = "MyValues")
    void MyFunction();

};
