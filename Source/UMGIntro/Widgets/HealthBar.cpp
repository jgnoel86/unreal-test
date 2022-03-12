// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBar.h"

const float UHealthBar::kMaxHealth = 100.0f;

void UHealthBar::UpdateHealth_Implementation(float health)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World"));
}



void UHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	mHealth -= 0.1f;
	if (mHealth <= 0)
		mHealth = kMaxHealth;

	UpdateHealth(mHealth);
}
