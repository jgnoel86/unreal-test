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

void UCollectionView::SetupData(const UDMCollection* Collection, const UAppDataStore* DataStore)
{
    if(!Collection || !Collection->IsValidLowLevelFast())
        return;
    if(!DataStore || !DataStore->IsValidLowLevelFast())
        return;

    UE_LOG(LogTemp, Warning, TEXT("Setting up data collection: Name: %s - Id: %s"), *Collection->mName, *Collection->mId);
    
    const int itemCount = Collection->mItemIdList.Num();
    for(int i = 0; i < itemCount; i++)
    {
        const UDMBase* basePtr = DataStore->GetBasePointer(Collection->mItemIdList[i]);
        if(!basePtr)
            continue;
        
        OnSetupElement(basePtr);
    }
}
