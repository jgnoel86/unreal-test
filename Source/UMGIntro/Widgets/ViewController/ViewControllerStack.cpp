// Fill out your copyright notice in the Description page of Project Settings.

#include "ViewControllerStack.h"
#include "ViewController.h"

UViewControllerStack::UViewControllerStack()
{
	mOnShowComplete =
		FOnViewTransitionComplete::CreateUObject(this, &UViewControllerStack::OnShowComplete);
	
	mOnHideComplete =
		FOnViewTransitionComplete::CreateUObject(this, &UViewControllerStack::OnHideComplete);
}

void UViewControllerStack::Push(UViewController* ViewController)
{
	UViewController* top = Peek();
	
	if(top && top->IsValidLowLevel())
	{
		top->BeforeHide();
		top->Hide(mOnHideComplete);
	}
	
	PushInternal(ViewController);
	
	ViewController->BeforeShow();
	ViewController->Show(mOnShowComplete);
}

void UViewControllerStack::Pop()
{
	if(mViewControllerStack.IsEmpty())
		return;
	
	UViewController* top = Peek();
	UViewController* oneBeforeTop = PeekBeforeTop();

	if(oneBeforeTop && oneBeforeTop->IsValidLowLevel())
	{
		oneBeforeTop->SetIsReturning(true);
		oneBeforeTop->BeforeShow();
		oneBeforeTop->Show(mOnShowComplete);
	}

	mViewControllerStack.RemoveAt(mViewControllerStack.Num() - 1);
	
	if(top && top->IsValidLowLevel())
	{
		top->SetIsReturning(true);
		top->BeforeHide();
		top->Hide(mOnHideComplete);
	}
}

void UViewControllerStack::Clear()
{
}

UViewController* UViewControllerStack::Peek() const
{
	return PeekAtTopOffset(0);
}

UViewController* UViewControllerStack::PeekBeforeTop() const
{
	return PeekAtTopOffset(1);
}

UViewController* UViewControllerStack::Bottom() const
{
	return !mViewControllerStack.IsEmpty() ? mViewControllerStack[0] : nullptr;
}

int UViewControllerStack::Count() const
{
	return mViewControllerStack.Num();
}

bool UViewControllerStack::IsEmpty() const
{
	return mViewControllerStack.IsEmpty();
}

int UViewControllerStack::IndexOf(const UViewController* ViewController) const
{
	for(int i = 0; i < mViewControllerStack.Num(); i++)
	{
		if(mViewControllerStack[i] == ViewController)
			return i;
	}
	return -1;
}

bool UViewControllerStack::IsRootOfStack(const UViewController* ViewController) const
{
	if(mViewControllerStack.IsEmpty())
		return false;

	return mViewControllerStack[0] == ViewController; 
}

UViewController* UViewControllerStack::PeekAtTopOffset(int Offset) const
{
	const int count = mViewControllerStack.Num();
	return count > Offset ? mViewControllerStack[count - Offset - 1] : nullptr;
}

void UViewControllerStack::PushInternal(UViewController* ViewController)
{
	mViewControllerStack.Add(ViewController);
	UE_LOG(LogTemp, Warning, TEXT("View controller stack size %d"), mViewControllerStack.Num());
}


void UViewControllerStack::OnShowComplete(UViewController* ViewController)
{
	if(ViewController && ViewController->IsValidLowLevelFast())
		ViewController->AfterShow();
}

void UViewControllerStack::OnHideComplete(UViewController* ViewController)
{
	if(ViewController && ViewController->IsValidLowLevelFast())
		ViewController->AfterHide();
}
