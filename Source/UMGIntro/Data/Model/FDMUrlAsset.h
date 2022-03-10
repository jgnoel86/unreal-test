#pragma once

#include "FDMUrlAsset.generated.h"

USTRUCT(BlueprintType)
struct FDMUrlAsset
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString url;
};