/**
 * @author Justin Noel
 * @file   DMUrlAsset.h
 * @brief 
 */

#pragma once

#include "DMUrlAsset.generated.h"

/**
 * @brief Struct used to deserialize a JSON UrlAsset
 */
USTRUCT()
struct FDMUrlAssetRecord
{
	GENERATED_BODY()

	UPROPERTY()
	FString id;

	UPROPERTY()
	FString url;
};

/**
 * @brief A url asset is an object pointing to some sort of externally hosted asset.
 *        In a real world setup these would have more data.
 *        Examples include:
 *        asset type (to distinguish between say Mesh, Video, Image type)
 *        asset meta data
 */
UCLASS(BlueprintType)
class UDMUrlAsset : public UObject
{
	GENERATED_BODY()
	
public:
	/**
	 * @brief Invoked to setup the unreal instance of the deserialized object.
	 * @param Record Deserialized struct to convert into unreal object.
	 */
	void Initialize(const FDMUrlAssetRecord& Record);

	/**
	 * @brief UUID used to track the asset on an internal system.
	 */
	UPROPERTY()
	FString mId;
	
	/**
	 * @brief Url to the external asset.
	 */
	UPROPERTY()
	FString mUrl;
};