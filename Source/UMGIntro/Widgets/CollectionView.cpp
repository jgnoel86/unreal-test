/**
 * @author Justin Noel
 * @file   CollectionView.cpp
 */

#include "CollectionView.h"

/**
 * @brief Expected to be invoked by a blueprint with the specific collection that should be displayed
 *        as well as the AppDataStore so the individual elements can be setup.
 * @param Collection Collection that this view should display.
 * @param DataStore AppDataStore to get more information for the individual items.
 */
void UCollectionView::SetupData(const UDMCollection* Collection, const UAppDataStore* DataStore)
{
    if(!Collection || !Collection->IsValidLowLevelFast())
        return;
    if(!DataStore || !DataStore->IsValidLowLevelFast())
        return;
    
    const int itemCount = Collection->mItemIdList.Num();
    for(int i = 0; i < itemCount; i++)
    {
        const UDMBase* basePtr = DataStore->GetBasePointer(Collection->mItemIdList[i]);
        if(!basePtr)
            continue;
        
        OnSetupElement(basePtr);
    }
}
