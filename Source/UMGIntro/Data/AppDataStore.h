/**
 * @author Justin Noel
 * @file   AppDataStore.h
 */

#pragma once

#include "CoreMinimal.h"
#include "Model/DMApp.h"
#include "AppDataStore.generated.h"

/**
 * @brief AppDataStore is a basic support system to store off the data pulled from the mock app service. If provided
 *		  a valid JSON string it will parse the string and store off the various items from the service for use later.
 *		  While right now everything is cached, it would not be difficult to async the GetCollection and GetItem calls
 *		  and only store off a top list view of the app data.
 */
UCLASS()
class UMGINTRO_API UAppDataStore : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	/**
	 * @brief Expects a JSON string in order to parse off the application data to store it off for later lookup and use.
	 * @param response Valid JSON string to be deserialized.
	 */
	UFUNCTION(BlueprintCallable)
	void SetupDataFromResponseString(FString response);

	/**
	 * @brief Every app object has a starting collection id, the collection that should be presented first.
	 * @return Collection object for the starting collection id.
	 */
	UFUNCTION(BlueprintCallable)
	const UDMCollection* GetStartingCollection() const;
	
	/**
	 * @brief Given a collection UUID, retrieve the Collection object. Will be nullptr if none exists.
	 * @param collectionId UUID of the collection to retrieve an object for.
	 * @return Valid UDMCollection object if one exists, otherwise nullptr.
	 */
	UFUNCTION(BlueprintCallable)
	const UDMCollection* GetCollection(const FString& collectionId) const;
	
	/**
	 * @brief Given an item UUID, retrieve the Item object. Will be nullptr if none exists
	 * @param itemId UUID of the item to retrieve an object for.
	 * @return Valid UDMItem object if one exists, otherwise nullptr.
	 */
	UFUNCTION(BlueprintCallable)
	const UDMItem* GetItem(const FString& itemId) const;
	
	/**
	 * @brief Given any Base UUID, retrieve the base ptr for that object. Will be nullptr if none exists
	 * @param baseId UUID of the item to retrieve an object for.
	 * @return Valid UDMBase pointer object if one exists, otherwise nullptr.
	 */
	const UDMBase* GetBasePointer(const FString& baseId) const;


private:
	/**
	 * @brief Store off the deserialized UDMApp data object as a UProperty to ensure it's not released. 
	 */
	UPROPERTY()
	UDMApp* mAppData;

	
	/**
	 * @brief All of the objects from AppData after they have been deserialized have their pointers stored here.
	 */
	UPROPERTY()
	TMap<FString, UDMBase*> mBaseItems;
};
