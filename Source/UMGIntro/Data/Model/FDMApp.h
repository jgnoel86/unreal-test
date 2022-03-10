#pragma once

#include "FDMBase.h"
#include "FDMCollection.h"
#include "FDMItem.h"

#include "FDMApp.generated.h"


USTRUCT(BlueprintType)
struct FDMApp : public FDMBase
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FDMCollection> collectionList;

	UPROPERTY()
	TArray<FDMItem> itemList;

	UPROPERTY()
	TArray<FString> orderedList;
};