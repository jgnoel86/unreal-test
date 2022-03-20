// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ViewControllerStack.h"
#include "UObject/Object.h"
#include "ViewControllerStackManager.generated.h"

/**
 * 
 */
UCLASS()
class UMGINTRO_API UViewControllerStackManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    UViewControllerStack* GetStack(int StackId);

private:
    TMap<int, UViewControllerStack*> mStackMap;
};
