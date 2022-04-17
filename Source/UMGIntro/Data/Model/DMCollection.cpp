/**
 * @author Justin Noel
 * @file   DMCollection.h
 */

#include "DMCollection.h"

/**
 * @brief Invoked to setup the unreal instance of the deserialized object.
 * @param Record Deserialized struct to convert into unreal object.
 */
void UDMCollection::Initialize(const FDMCollectionRecord& Record)
{
    Super::Initialize(Record);

    for(const FString& string : Record.itemIds)
        mItemIdList.Add(string);
}
