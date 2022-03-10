#pragma once

#include "FDMBase.h"

#include "FDMItem.generated.h"


USTRUCT(BlueprintType)
struct FDMItem : public FDMBase
{
	GENERATED_BODY()

	UPROPERTY()
	FString description;
};