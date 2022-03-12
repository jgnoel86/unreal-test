// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class UMGINTRO_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()
private:
	static const float kMaxHealth;

public:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	//BlueprintNativeEvent
	//BlueprintImplementableEvent
	UFUNCTION(BlueprintNativeEvent, Category = "User Interface|Health")
	void UpdateHealth(float health = 0);

private:
	float mHealth = kMaxHealth;
};
