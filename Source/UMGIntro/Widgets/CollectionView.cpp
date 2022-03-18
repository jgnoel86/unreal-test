// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectionView.h"
#include "../Data/Model/DMCollection.h"

void UCollectionView::BeforeShow()
{
    UE_LOG(LogTemp, Warning, TEXT("CollectionView::BeforeShow"));
}

void UCollectionView::Show(FOnViewTransitionComplete OnComplete)
{
    Super::Show(OnComplete);
}

void UCollectionView::AfterShow()
{
    UE_LOG(LogTemp, Warning, TEXT("CollectionView::AfterShow"));
}

void UCollectionView::BeforeHide()
{
    UE_LOG(LogTemp, Warning, TEXT("CollectionView::BeforeHide"));
}

void UCollectionView::Hide(FOnViewTransitionComplete OnComplete)
{
    Super::Hide(OnComplete);
}

void UCollectionView::AfterHide()
{
    UE_LOG(LogTemp, Warning, TEXT("CollectionView::AfterHide"));
}

void UCollectionView::SetupData(UPARAM(ref) const FDMCollection& Collection, const UAppDataStore* DataStore)
{
    if(!FDMCollection::IsValid(Collection))
        return;
    if(!DataStore || !DataStore->IsValidLowLevelFast())
        return;

    UE_LOG(LogTemp, Warning, TEXT("Setting up data collection: Name: %s - Id: %s"), *Collection.name, *Collection.id);
    
    const int itemCount = Collection.itemIds.Num();
    for(int i = 0; i < itemCount; i++)
    {
        const FDMBase* basePtr = DataStore->GetBasePointer(Collection.itemIds[i]);
        if(!basePtr)
            continue;
        
        UE_LOG(LogTemp, Warning, TEXT("Setting up item: name: %s - Id: %s"), *basePtr->name, *basePtr->id);
        
        OnSetupElement(*basePtr);
    }
}
