/**
 * @author Justin Noel
 * @file   DMApp.h
 */

#pragma once

#include "DMBase.h"
#include "DMCollection.h"
#include "DMItem.h"
#include "DMApp.generated.h"

/**
 * @brief App record struct used for deserialization.
 */
USTRUCT()
struct FDMAppRecord
{
	GENERATED_BODY()
	
	/**
	 * @brief Collection list for the application.
	 *		  In a real world setup, this would only include collections actively referenced by the starting collection
	 *		  or another collection.
	 */
	UPROPERTY()
	TArray<FDMCollectionRecord> collectionList;

	/**
	 * @brief Item list for this application.
	 *		  In a real world setup, this would only include items actively referenced by a valid collection.
	 */
	UPROPERTY()
	TArray<FDMItemRecord> itemList;
	
	/**
	 * @brief UUID for the starting collection that should be shown.
	 */
	UPROPERTY()
	FString startingCollection;
};

/**
 * @brief App data object for use within blueprints, and Unreal classes.
 */
UCLASS(BlueprintType)
class UDMApp : public UDMBase
{
	GENERATED_BODY()
	
public:
	/**
	 * @brief Invoked to convert deserialized data structure into an unreal usable object.
	 * @param Record Deserialized data struct of the Application data.
	 */
	void Initialize(const FDMAppRecord& Record);
	
	/**
	 * @brief Collection list for the application.
	 *		  In a real world setup, this would only include collections actively referenced by the starting collection
	 *		  or another collection.
	 */
	UPROPERTY()
	TArray<UDMCollection*> mCollectionList;

	/**
	 * @brief Item list for this application.
	 *		  In a real world setup, this would only include items actively referenced by a valid collection.
	 */
	UPROPERTY()
	TArray<UDMItem*> mItemList;

	/**
	 * @brief UUID for the starting collection that should be shown.
	 */
	UPROPERTY()
	FString mStartingCollection;
};