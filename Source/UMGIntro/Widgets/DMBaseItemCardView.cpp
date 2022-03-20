// Fill out your copyright notice in the Description page of Project Settings.


#include "DMBaseItemCardView.h"

#include "UMGIntro/Data/Model/DMCollection.h"

void UDMBaseItemCardView::SetupData(const UDMBase* BaseItem)
{
	mItemId = BaseItem->mId;
	
	if(BaseItem->IsA(UDMCollection::StaticClass()))
	{
		mIsCollection = true;
		SetupCollection();
	}
	
	SetupImage(BaseItem->mImage->mUrl);
	SetupTitle(BaseItem->mName);
}