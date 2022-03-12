// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectionView.h"
#include "../Data/Model/DMCollection.h"

void UCollectionView::SetupAndDisplayView(UPARAM(ref) const FDMCollection& Collection, const UAppDataStore* DataStore)
{
    if(!FDMCollection::IsValid(Collection))
        return;
    if(!DataStore || !DataStore->IsValidLowLevelFast())
        return;

    const int itemCount = Collection.itemIds.Num();
    for(int i = 0; i < itemCount; i++)
    {
        const FDMBase* basePtr = DataStore->GetBasePointer(Collection.itemIds[i]);
        if(!basePtr)
            continue;
        
        SetupElement(*basePtr);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Setting up data collection: Name: %s - Id: %s"), *Collection.name, *Collection.id);
    AddToViewport();
}
