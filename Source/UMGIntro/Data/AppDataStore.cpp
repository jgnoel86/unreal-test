// Fill out your copyright notice in the Description page of Project Settings.


#include "AppDataStore.h"
#include "JsonObjectConverter.h"
#include "Model/DMItem.h"
#include "Model/DMCollection.h"

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

const UDMBase* UAppDataStore::GetBasePointer(const FString& itemId) const
{
    return mBaseItems[itemId];
}


const UDMCollection* UAppDataStore::GetStartingCollection() const
{
	return GetCollection(mAppData->mStartingCollection);
}

const UDMCollection* UAppDataStore::GetCollection(const FString& collectionId) const
{
	UDMBase* basePtr = mBaseItems[collectionId];
    return Cast<UDMCollection>(basePtr);
}

const UDMItem* UAppDataStore::GetItem(const FString& itemId) const
{
    UDMBase* basePtr = mBaseItems[itemId];
    return Cast<UDMItem>(basePtr);
}

