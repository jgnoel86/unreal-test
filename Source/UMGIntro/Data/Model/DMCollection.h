/**
 * @author Justin Noel
 * @file   DMCollection.h
 */

#pragma once

#include "DMBase.h"
#include "DMCollection.generated.h"

/**
 * @brief Struct used to deserialize Collection objects from JSON.
 */
USTRUCT()
struct FDMCollectionRecord : public FDMBaseRecord
{
	GENERATED_BODY()

	/**
	 * @brief List of base objects that this collection contains.
	 */
	UPROPERTY()
	TArray<FString> itemIds;
};

/**
 * @brief In addition to Base, Collection stores off a list of UUIDs that belong to this collection.
 *	      Collections are allowed to have Collections or Items in them.
 */
UCLASS(BlueprintType)
class UDMCollection : public UDMBase
{
	GENERATED_BODY()
	
public: 
	/**
	 * @brief Invoked to setup the unreal instance of the deserialized object.
	 * @param Record Deserialized struct to convert into unreal object.
	 */
	void Initialize(const FDMCollectionRecord& Record);
	
	/**
	 * @brief List of base objects that this collection contains.
	 */
	UPROPERTY()
	TArray<FString> mItemIdList;
};