﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Data/Model/DMBase.h"
#include "DMBaseItemCardView.generated.h"

/**
 * 
 */
UCLASS()
class UMGINTRO_API UDMBaseItemCardView : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent)
	void SetupImage(const FString& Url);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupTitle(const FString& Title);
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetupCollection();
	
	UFUNCTION(BlueprintCallable)
	void SetupData(const UDMBase* BaseItem);

protected:
	UPROPERTY(BlueprintReadOnly)
	bool mIsCollection;

	UPROPERTY(BlueprintReadOnly)
	FString mItemId;
};
