/**
 * @author Justin Noel
 * @file   DMApp.cpp
 */

#include "DMApp.h"

/**
 * @brief Invoked to convert deserialized data structure into an unreal usable object.
 * @param Record Deserialized data struct of the Application data.
 */
void UDMApp::Initialize(const FDMAppRecord& Record)
{
    mStartingCollection = Record.startingCollection;

    mCollectionList.Reserve(Record.collectionList.Num());
    for(const FDMCollectionRecord& collectionRecord : Record.collectionList)
    {
        UDMCollection* collection = NewObject<UDMCollection>(this);
        collection->Initialize(collectionRecord);
        mCollectionList.Add(collection);
    }
    
    mItemList.Reserve(Record.collectionList.Num());
    for(const FDMItemRecord& itemRecord : Record.itemList)
    {
        UDMItem* item = NewObject<UDMItem>(this);
        item->Initialize(itemRecord);
        mItemList.Add(item);
    }
}
