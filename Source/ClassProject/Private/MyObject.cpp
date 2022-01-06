// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject.h"


void UMyObject::MyFunction()
{
    UE_LOG(LogTemp, Warning, TEXT("We got there !!!!, Value of MyFloat : %f"), Myfloat);
}