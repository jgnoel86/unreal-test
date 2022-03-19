// Fill out your copyright notice in the Description page of Project Settings.


#include "DetailView.h"

void UDetailView::SetupData(UPARAM(ref) const FDMItem& item)
{
    if(!FDMItem::IsValid(item))
        return;
    
    SetupTitle(item.name);
    SetupImage(item.image.url);
    SetupDescription(item.description);
}
