#pragma once

#include "DMBase.h"

#include "DMItem.generated.h"

USTRUCT(BlueprintType)
struct FDMItem : public FDMBase
{
	GENERATED_BODY()

	UPROPERTY()
	FString description;

	static bool IsValid(const FDMItem& item);

	static const FDMItem SInvalidItem;
};