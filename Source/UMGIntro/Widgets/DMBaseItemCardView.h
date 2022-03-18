// Fill out your copyright notice in the Description page of Project Settings.

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
	
	UFUNCTION(BlueprintCallable)
	void SetupData(const FDMBase& BaseItem);

	UFUNCTION(BlueprintCallable)
	const FString& GetItemId() const;

private:
	FString mItemId;
};
