#pragma once

#include "DMBase.h"

#include "DMItem.generated.h"

USTRUCT()
struct FDMItemRecord : public FDMBaseRecord
{
	GENERATED_BODY()

	UPROPERTY()
	FString description;
};

UCLASS(BlueprintType)
class UDMItem : public UDMBase
{
	GENERATED_BODY()
	
public:
	void Initialize(const FDMItemRecord& record);
	
	UPROPERTY()
	FString mDescription;
};