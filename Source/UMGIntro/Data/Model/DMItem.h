#pragma once

#include "DMBase.h"

#include "DMItem.generated.h"

USTRUCT(BlueprintType)
struct FDMItem : public FDMBase
{
	GENERATED_BODY()

	UPROPERTY()
	FString description;
};