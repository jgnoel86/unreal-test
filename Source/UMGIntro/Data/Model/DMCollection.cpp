#include "DMCollection.h"

void UDMCollection::Initialize(const FDMCollectionRecord& record)
{
    Super::Initialize(record);

    for(const FString& string : record.itemIds)
        mItemIdList.Add(string);
}
