#pragma once

#include "DMBase.h"
#include "DMCollection.h"
#include "DMItem.h"

#include "DMApp.generated.h"

USTRUCT()
struct FDMAppRecord
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FDMCollectionRecord> collectionList;

	UPROPERTY()
	TArray<FDMItemRecord> itemList;

	UPROPERTY()
	FString startingCollection;
};

UCLASS(BlueprintType)
class UDMApp : public UDMBase
{
	GENERATED_BODY()
	
public:
	void Initialize(const FDMAppRecord& record);
	
	UPROPERTY()
	TArray<UDMCollection*> mCollectionList;

	UPROPERTY()
	TArray<UDMItem*> mItemList;

	UPROPERTY()
	FString mStartingCollection;
};