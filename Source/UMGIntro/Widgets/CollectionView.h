/**
 * @author Justin Noel
 * @file   CollectionView.h
 */
#pragma once

#include "CoreMinimal.h"
#include "../Data/AppDataStore.h"
#include "../Data/Model/DMCollection.h"
#include "ViewController/ViewController.h"
#include "CollectionView.generated.h"

/**
 * @brief CollectionView is a Widget designed to display a grid like scrolling view of collections.
 *        It does not attempt to handle pooling, it simply ensures the data exists in the DataStore
 *        before triggering the OnSetupElement event to let the blueprint setup the item.
 */
UCLASS()
class UMGINTRO_API UCollectionView : public UViewController
{
	GENERATED_BODY()
public:	
	/**
	 * @brief Expected to be invoked by a blueprint with the specific collection that should be displayed
	 *        as well as the AppDataStore so the individual elements can be setup.
	 * @param Collection Collection that this view should display.
	 * @param DataStore AppDataStore to get more information for the individual items.
	 */
	UFUNCTION(BlueprintCallable)
	void SetupData(const UDMCollection* Collection, const UAppDataStore* DataStore);

	
	/**
	 * @brief Triggered for each item in the collection view, during the SetupData method.
	 * @param BaseItem The BaseItem that a new element should be created for.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupElement(const UDMBase* BaseItem);
};
