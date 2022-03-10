#pragma once

#include "DMBase.h"

#include "DMCollection.generated.h"


USTRUCT(BlueprintType)
struct FDMCollection : public FDMBase
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FString> itemIds;
};