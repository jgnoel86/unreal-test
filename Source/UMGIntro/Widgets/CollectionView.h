// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Data/AppDataStore.h"
#include "../Data/Model/DMCollection.h"
#include "ViewController/ViewController.h"
#include "CollectionView.generated.h"

struct FDMCollection;
/**
 * 
 */
UCLASS()
class UMGINTRO_API UCollectionView : public UViewController
{
	GENERATED_BODY()
public:
	virtual void BeforeShow() override;
	virtual void Show(FOnViewTransitionComplete OnComplete) override;
	virtual void AfterShow() override;
	virtual void BeforeHide() override;
	virtual void Hide(FOnViewTransitionComplete OnComplete) override;
	virtual void AfterHide() override;
	
	UFUNCTION(BlueprintCallable)
	void SetupData(UPARAM(ref) const FDMCollection& Collection, const UAppDataStore* DataStore);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupElement(const FDMBase& BaseItem);
};
