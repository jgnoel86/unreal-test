// Fill out your copyright notice in the Description page of Project Settings.


#include "DetailView.h"

void UDetailView::SetupData(const UDMItem* Item)
{
    if(!Item || !Item->IsValidLowLevelFast())
        return;
    
    SetupTitle(Item->mName);
    SetupImage(Item->mImage->mUrl);
    SetupDescription(Item->mDescription);
}
