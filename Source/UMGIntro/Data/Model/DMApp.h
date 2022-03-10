#pragma once

#include "DMBase.h"
#include "DMCollection.h"
#include "DMItem.h"

#include "DMApp.generated.h"


USTRUCT(BlueprintType)
struct FDMApp : public FDMBase
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FDMCollection> collectionList;

	UPROPERTY()
	TArray<FDMItem> itemList;

	UPROPERTY()
	FString startingCollection;
};