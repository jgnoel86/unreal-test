// Fill out your copyright notice in the Description page of Project Settings.


#include "AppDataStore.h"
#include "JsonObjectConverter.h"

void UAppDataStore::SetupDataFromResponseString(FString response)
{
    if(response.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("Data response is empty."));
        return;
    }
    
    FJsonObjectConverter::JsonObjectStringToUStruct(response, &mAppData, 0, 0);
    
    const int collectionCount = mAppData.collectionList.Num();
    const int itemCount = mAppData.itemList.Num();
    const int totalCount = collectionCount + itemCount;

    mBaseItems.Reserve(totalCount);
    for(FDMCollection& collection : mAppData.collectionList)
    {
        mBaseItems.Add(collection.id, &collection);
    }
    for(FDMItem& item : mAppData.itemList)
    {
        mBaseItems.Add(item.id, &item);
    }
}

const FDMCollection& UAppDataStore::GetStartingCollection() const
{
    return GetCastedBase<FDMCollection>(mAppData.startingCollection);
}

const FDMCollection& UAppDataStore::GetCollection(const FString& collectionId) const
{
    return GetCastedBase<FDMCollection>(collectionId);
}

const FDMItem& UAppDataStore::GetItem(const FString& itemId) const
{
    return GetCastedBase<FDMItem>(itemId);
}

