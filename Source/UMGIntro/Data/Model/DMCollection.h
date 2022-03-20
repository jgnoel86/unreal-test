#pragma once

#include "DMBase.h"

#include "DMCollection.generated.h"


USTRUCT()
struct FDMCollectionRecord : public FDMBaseRecord
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FString> itemIds;
};

UCLASS(BlueprintType)
class UDMCollection : public UDMBase
{
	GENERATED_BODY()
	
public: 
	void Initialize(const FDMCollectionRecord& record);
	
	UPROPERTY()
	TArray<FString> mItemIdList;
};