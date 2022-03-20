// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "UMGIntro/Data/Model/DMBase.h"
#include "UMGIntro/Data/Model/DMItem.h"
#include "UObject/Object.h"
#include "ViewController/ViewController.h"
#include "DetailView.generated.h"

/**
 * 
 */
UCLASS()
class UMGINTRO_API UDetailView : public UViewController
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    void SetupData(const UDMItem* Item);

    UFUNCTION(BlueprintImplementableEvent)
    void SetupTitle(const FString& Title);
    
    UFUNCTION(BlueprintImplementableEvent)
    void SetupImage(const FString& ImageUrl);
    
    UFUNCTION(BlueprintImplementableEvent)
    void SetupDescription(const FString& Description);
};
