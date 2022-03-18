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
		oneBeforeTop->SetReturningFlag(true);
		oneBeforeTop->BeforeShow();
		oneBeforeTop->Show(mOnShowComplete);
	}

	mViewControllerStack.RemoveAt(mViewControllerStack.Num() - 1);
	
	if(top && top->IsValidLowLevel())
	{
		top->SetReturningFlag(true);
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
