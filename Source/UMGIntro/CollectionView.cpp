// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectionView.h"
#include "Data/Model/DMCollection.h"

void UCollectionView::SetupAndDisplayView(UPARAM(ref) const FDMCollection& Collection, const UAppDataStore* DataStore)
{
    UE_LOG(LogTemp, Warning, TEXT("Setting up data collection: Name: %s - Id: %s"), *Collection.name, *Collection.id);
}
