// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewController.h"

void UViewController::BeforeShow()
{
}

void UViewController::Show(FOnViewTransitionComplete OnComplete)
{
	mOnShowComplete = OnComplete;
	OnShow();
}

void UViewController::AfterShow()
{
}

void UViewController::BeforeHide()
{
}

void UViewController::Hide(FOnViewTransitionComplete OnComplete)
{
	mOnHideComplete = OnComplete;
	OnHide();
}

void UViewController::AfterHide()
{
}

void UViewController::ShowComplete()
{
	mOnShowComplete.ExecuteIfBound(this);
}
void UViewController::HideComplete()
{
	mOnHideComplete.ExecuteIfBound(this);
}

void UViewController::SetIsReturning(bool IsReturning)
{
	mIsReturning = IsReturning;
}
