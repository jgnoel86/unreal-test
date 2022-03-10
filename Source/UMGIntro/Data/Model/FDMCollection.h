#pragma once

#include "FDMBase.h"

#include "FDMCollection.generated.h"


USTRUCT(BlueprintType)
struct FDMCollection : public FDMBase
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FString> itemIds;
};