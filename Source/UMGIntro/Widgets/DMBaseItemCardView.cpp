/**
 * @author Justin Noel
 * @file   DMBaseItemCardView.cpp
 */

#include "DMBaseItemCardView.h"
#include "../Data/Model/DMCollection.h"

void UDMBaseItemCardView::SetupData(const UDMBase* BaseItem)
{
	mBaseItem = BaseItem;
	
	if(BaseItem->IsA(UDMCollection::StaticClass()))
	{
		mIsCollection = true;
		SetupCollection();
	}
	
	SetupImage(BaseItem->mImage->mUrl);
	SetupTitle(BaseItem->mName);
}