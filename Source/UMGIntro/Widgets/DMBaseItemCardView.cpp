// Fill out your copyright notice in the Description page of Project Settings.


#include "DMBaseItemCardView.h"

void UDMBaseItemCardView::SetupData(UPARAM(ref) const FDMBase& BaseItem)
{
	SetupImage(BaseItem.image.url);
	SetupTitle(BaseItem.name);
	mItemId = BaseItem.id;
}

const FString& UDMBaseItemCardView::GetItemId() const
{
	return mItemId;
}
