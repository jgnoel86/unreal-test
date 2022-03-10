#pragma once

#include "FDMUrlAsset.h"

#include "FDMBase.generated.h"


USTRUCT(BlueprintType)
struct FDMBase
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FDMUrlAsset image;
};