/**
 * @author Justin Noel
 * @file   AppDataStore.cpp
 */

#include "AppDataStore.h"
#include "JsonObjectConverter.h"
#include "Model/DMItem.h"
#include "Model/DMCollection.h"

/**
 * @brief Expects a JSON string in order to parse off the application data to store it off for later lookup and use.
 * @param response Valid JSON string to be deserialized.
 */
void UAppDataStore::SetupDataFromResponseString(FString response)
{
    if(response.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("Data response is empty."));
        return;
    }

    FDMAppRecord appData;
    FJsonObjectConverter::JsonObjectStringToUStruct(response, &appData, 0, 0);

    mAppData = NewObject<UDMApp>(this);
    mAppData->Initialize(appData);

    TArray<UDMCollection*>& collectionList = mAppData->mCollectionList;
    TArray<UDMItem*>& itemList = mAppData->mItemList;
    const int collectionCount = collectionList.Num();
    const int itemCount = itemList.Num();
    const int totalCount = collectionCount + itemCount;

    mBaseItems.Reserve(totalCount);
    for(UDMCollection* collection : collectionList)
    {
        mBaseItems.Add(collection->mId, collection);
    }
    for(UDMItem* item : itemList)
    {
        mBaseItems.Add(item->mId, item);
    }
}

/**
 * @brief Every app object has a starting collection id, the collection that should be presented first
 * @return Collection object for the starting collection id.
 */
const UDMCollection* UAppDataStore::GetStartingCollection() const
{
	return GetCollection(mAppData->mStartingCollection);
}

/**
 * @brief Given a collection id, retrieve the Collection object. Will be null if non exists.
 * @param collectionId UUID of the collection to retrieve an object for.
 * @return Valid UDMCollection object if one exists, otherwise nullptr.
 */
const UDMCollection* UAppDataStore::GetCollection(const FString& collectionId) const
{
	UDMBase* basePtr = mBaseItems[collectionId];
    return Cast<UDMCollection>(basePtr);
}

/**
 * @brief Given an item UUID, retrieve the Item object. Will be nullptr if none exists
 * @param itemId UUID of the item to retrieve an object for.
 * @return Valid UDMItem object if one exists, otherwise nullptr.
 */
const UDMItem* UAppDataStore::GetItem(const FString& itemId) const
{
    UDMBase* basePtr = mBaseItems[itemId];
    return Cast<UDMItem>(basePtr);
}

/**
 * @brief Given any Base UUID, retrieve the base ptr for that object. Will be nullptr if none exists
 * @param baseId UUID of the item to retrieve an object for.
 * @return Valid UDMBase pointer object if one exists, otherwise nullptr.
 */
const UDMBase* UAppDataStore::GetBasePointer(const FString& baseId) const
{
    UDMBase* const* ptrToItem = mBaseItems.Find(baseId);
    return ptrToItem != nullptr ? *ptrToItem : nullptr;
}

