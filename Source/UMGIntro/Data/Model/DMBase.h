#pragma once

#include "DMUrlAsset.h"

#include "DMBase.generated.h"

USTRUCT()
struct FDMBaseRecord
{
	GENERATED_BODY()
	
	UPROPERTY()
	FString id;

	UPROPERTY()
	FString name;

	UPROPERTY()
	FDMUrlAssetRecord image;
};

UCLASS(BlueprintType)
class UDMBase : public UObject
{
	GENERATED_BODY()
public:
	void Initialize(const FDMBaseRecord& record);
	
	UPROPERTY()
	FString mId;

	UPROPERTY()
	FString mName;

	UPROPERTY()
	UDMUrlAsset* mImage;
};
