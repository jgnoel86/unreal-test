// Fill out your copyright notice in the Description page of Project Settings.


#include "DMBaseView.h"
void UDMBaseView::SetupAndDisplay(const FDMBase& baseItem)
{
	SetupImage(baseItem.image.url);
	SetupTitle(baseItem.name);
}
