// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/Model/DMApp.h"
#include "AppProcessor.generated.h"

/**
 * 
 */
UCLASS()
class UMGINTRO_API UAppProcessor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    static FDMCollection GetStartingCollectionFromAppData(UPARAM(ref) const FDMApp& AppData);
};
