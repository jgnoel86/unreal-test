#include "DMApp.h"

void UDMApp::Initialize(const FDMAppRecord& record)
{
    mStartingCollection = record.startingCollection;

    mCollectionList.Reserve(record.collectionList.Num());
    for(const FDMCollectionRecord& collectionRecord : record.collectionList)
    {
        UDMCollection* collection = NewObject<UDMCollection>(this);
        collection->Initialize(collectionRecord);
        mCollectionList.Add(collection);
    }
    
    mItemList.Reserve(record.collectionList.Num());
    for(const FDMItemRecord& itemRecord : record.itemList)
    {
        UDMItem* item = NewObject<UDMItem>(this);
        item->Initialize(itemRecord);
        mItemList.Add(item);
    }
}
