#pragma once

#include "DMUrlAsset.generated.h"

USTRUCT()
struct FDMUrlAssetRecord
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString url;
};

UCLASS(BlueprintType)
class UDMUrlAsset : public UObject
{
	GENERATED_BODY()
	
public:
	void Initialize(const FDMUrlAssetRecord& record);

	UPROPERTY()
	FString mId;

	UPROPERTY()
	FString mUrl;
};