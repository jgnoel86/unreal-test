// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Data/AppDataStore.h"
#include "Blueprint/UserWidget.h"
#include "../Data/Model/DMCollection.h"
#include "CollectionView.generated.h"

struct FDMCollection;
/**
 * 
 */
UCLASS()
class UMGINTRO_API UCollectionView : public UUserWidget
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    void SetupAndDisplayView(UPARAM(ref) const FDMCollection& Collection, const UAppDataStore* DataStore);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupElement(const FDMBase& BaseItem);
};
