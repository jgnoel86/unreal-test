// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Data/Model/DMBase.h"
#include "DMBaseView.generated.h"

/**
 * 
 */
UCLASS()
class UMGINTRO_API UDMBaseView : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent)
	void SetupImage(const FString& Url);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupTitle(const FString& title);
	
	UFUNCTION(BlueprintCallable)
	void SetupAndDisplay(const FDMBase& baseItem);
};
