// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Model/DMApp.h"
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
	const FDMCollection& GetStartingCollection() const;

	UFUNCTION(BlueprintCallable)
	const FDMCollection& GetCollection(const FString& collectionId) const;
	
	UFUNCTION(BlueprintCallable)
	const FDMItem& GetItem(const FString& itemId) const;

private:
	FDMApp mAppData;
	
	TMap<FString, FDMBase*> mBaseItems;

	template <typename T>
	const T& GetCastedBase(const FString& id) const
	{
		FDMBase* basePtr = mBaseItems[id];		
		return *static_cast<T*>(basePtr);
	}
};
