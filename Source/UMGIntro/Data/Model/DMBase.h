#pragma once

#include "DMUrlAsset.h"

#include "DMBase.generated.h"

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