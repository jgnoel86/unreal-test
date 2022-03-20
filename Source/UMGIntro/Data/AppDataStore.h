// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Model/DMApp.h"
#include "AppDataStore.generated.h"

/**
 * 
 */
UCLASS()
class UMGINTRO_API UAppDataStore : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetupDataFromResponseString(FString response);

	UFUNCTION(BlueprintCallable)
	const UDMCollection* GetStartingCollection() const;

	UFUNCTION(BlueprintCallable)
	const UDMCollection* GetCollection(const FString& collectionId) const;
	
	UFUNCTION(BlueprintCallable)
	const UDMItem* GetItem(const FString& itemId) const;

	const UDMBase* GetBasePointer(const FString& itemId) const;

private:
	UPROPERTY();
	UDMApp* mAppData;

	UPROPERTY();
	TMap<FString, UDMBase*> mBaseItems;
};
