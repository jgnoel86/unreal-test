// Fill out your copyright notice in the Description page of Project Settings.

#include "ViewControllerStack.h"
#include "ViewController.h"

UViewControllerStack::UViewControllerStack()
{
	mOnShowComplete =
		FOnViewTransitionComplete::CreateUObject(this, &UViewControllerStack::OnShowComplete);
	
	mOnHideComplete =
		FOnViewTransitionComplete::CreateUObject(this, &UViewControllerStack::OnHideComplete);

	// Honestly probably only 1 item at a time will really be hiding, but just in case.
	mViewsHiding.Reserve(5);
}

void UViewControllerStack::Push(UViewController* ViewController)
{
	if(UViewController* top = Peek())
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
	
	if(UViewController* oneBeforeTop = PeekBeforeTop())
	{
		UE_LOG(LogTemp, Warning, TEXT("ViewControllerStack::One before top valid: Showing. Stack size %d"), mViewControllerStack.Num());
		oneBeforeTop->SetIsReturning(true);
		oneBeforeTop->BeforeShow();
		oneBeforeTop->Show(mOnShowComplete);
	}

	if(UViewController* top = Peek())
	{
		UE_LOG(LogTemp, Warning, TEXT("ViewControllerStack::Top Valid: Hiding. Stack size %d"), mViewControllerStack.Num());
		top->SetIsReturning(true);
		top->BeforeHide();
		top->Hide(mOnHideComplete);
		mViewsHiding.Add(top);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("ViewControllerStack::Before Pop: View controller stack size %d"), mViewControllerStack.Num());
	PopBack();
	UE_LOG(LogTemp, Warning, TEXT("ViewControllerStack::After Pop: View controller stack size %d"), mViewControllerStack.Num());
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
	return count > Offset ? mViewControllerStack[count - (Offset + 1)] : nullptr;
}
void UViewControllerStack::PopBack()
{
	mViewControllerStack.RemoveAt(mViewControllerStack.Num() - 1, 1, false);
}
void UViewControllerStack::PushInternal(UViewController* ViewController)
{
	mViewControllerStack.Add(ViewController);
	UE_LOG(LogTemp, Warning, TEXT("Pushing: View controller stack size %d"), mViewControllerStack.Num());
}


void UViewControllerStack::OnShowComplete(UViewController* ViewController)
{
	if(ViewController)
	{
		ViewController->AfterShow();
		ViewController->SetIsReturning(false);
	}
}

void UViewControllerStack::OnHideComplete(UViewController* ViewController)
{
	if(ViewController)
	{
		ViewController->AfterHide();
		ViewController->SetIsReturning(false);
		mViewsHiding.Remove(ViewController);
	}
}
