/**
 * @author Justin Noel
 * @file   DMItem.h
 */

#pragma once

#include "DMBase.h"
#include "DMItem.generated.h"

/**
 * @brief Struct used to deserialize JSON into item.
 */
USTRUCT()
struct FDMItemRecord : public FDMBaseRecord
{
	GENERATED_BODY()

	/**
	 * @brief Description that can be displayed to user.
	 */
	UPROPERTY()
	FString description;
};

/**
 * @brief In addition to Base, Item includes a description to display on a detail page.
 *        In a real world application there would be considerably more data here.
 *        Examples include, pricing (for purchases), video url asset (for content playback), mesh asset (for rendering).
 */
UCLASS(BlueprintType)
class UDMItem : public UDMBase
{
	GENERATED_BODY()
	
public:
	
	/**
	 * @brief Invoked to setup the unreal instance of the deserialized object.
	 * @param Record Deserialized struct to convert into unreal object.
	 */
	void Initialize(const FDMItemRecord& Record);
	
	/**
	 * @brief Description that can be displayed to user.
	 */
	UPROPERTY()
	FString mDescription;
};