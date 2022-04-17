/**
 * @author Justin Noel
 * @file   DMBase.h
 */

#pragma once

#include "DMUrlAsset.h"
#include "DMBase.generated.h"

/**
 * @brief Struct used to deserialize JSON data from mock service. Base represents the foundation that
 *	      both Collection and Item inherit from.
 */
USTRUCT()
struct FDMBaseRecord
{
	GENERATED_BODY()
	
	/**
	 * @brief UUID for the base object.
	 */
	UPROPERTY()
	FString id;

	/**
	 * @brief UUID for the base object.
	 */
	UPROPERTY()
	FString name;

	/**
	 * @brief URL Asset generally pointing to an image to use for the base object.
	 */
	UPROPERTY()
	FDMUrlAssetRecord image;
};

/**
 * @brief Base is the foundation that Collection and Item both inherit from.
 *	      Presently includes, ID (UUID), Name, and an URL Asset for an image.
 */
UCLASS(BlueprintType)
class UDMBase : public UObject
{
	GENERATED_BODY()
public:
	
	/**
	 * @brief Invoked to setup the unreal instance of the deserialized object.
	 * @param Record Base object record to initialize the base Unreal object from.
	 */
	void Initialize(const FDMBaseRecord& Record);
	
	/**
	 * @brief UUID for the base object.
	 */
	UPROPERTY()
	FString mId;

	/**
	 * @brief Display name for the base object.
	 */
	UPROPERTY()
	FString mName;

	/**
	 * @brief URL Asset generally pointing to an image to use for the base object.
	 */
	UPROPERTY()
	UDMUrlAsset* mImage;
};
