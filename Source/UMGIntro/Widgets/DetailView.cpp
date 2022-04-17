/**
 * @author Justin Noel
 * @file   DetailView.cpp
 */

#include "DetailView.h"

/**
 * @brief Called by a blueprint to set the specific item that detailed information should be shown for.
 * @param Item Item that will be used to setup this detail view.
 */
void UDetailView::SetupData(const UDMItem* Item)
{
    if(!Item || !Item->IsValidLowLevelFast())
        return;
    
    SetupTitle(Item->mName);
    SetupImage(Item->mImage->mUrl);
    SetupDescription(Item->mDescription);
}
