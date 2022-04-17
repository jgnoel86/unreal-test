/**
 * @author Justin Noel
 * @file   ViewControllerStack.cpp
 * @brief 
 */

#include "ViewControllerStack.h"
#include "ViewController.h"

/**
 * @brief Sets up the initial callbacks for this ViewControllerStack
 *		  and general allocations.
 */
UViewControllerStack::UViewControllerStack()
{
	mOnShowComplete =
		FOnViewTransitionComplete::CreateUObject(this, &UViewControllerStack::OnShowComplete);
	
	mOnHideComplete =
		FOnViewTransitionComplete::CreateUObject(this, &UViewControllerStack::OnHideComplete);

	// Honestly probably only 1 item at a time will really be hiding, but just in case.
	mViewsHiding.Reserve(5);
}

/**
 * @brief Push a ViewController onto this stack, this ensures it can be popped later.
 *		  Before displaying this ViewController widget the show methods will be invoked.
 *		  The previous ViewController on the stack will have it's hide methods invoked.
 * @param ViewController Widget to push on that stack.
 */
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

/**
 * @brief Pop the top of the stack, this will ensure the hide methods of the ViewController
 *		  are invoked, while the show methods of the last ViewController in the stack will
 *		  be invoked.
 */
void UViewControllerStack::Pop()
{
	if(mViewControllerStack.IsEmpty())
		return;
	
	if(UViewController* oneBeforeTop = PeekBeforeTop())
	{
		oneBeforeTop->SetIsReturning(true);
		oneBeforeTop->BeforeShow();
		oneBeforeTop->Show(mOnShowComplete);
	}

	if(UViewController* top = Peek())
	{
		top->SetIsReturning(true);
		top->BeforeHide();
		top->Hide(mOnHideComplete);
		mViewsHiding.Add(top);
	}
	
	PopBack();
}

/**
 * @brief This will clear the entire stack. As everything is being cleared off, and cleaned up
 *		  only the top of the stack will have it's hide methods called. All others will simply
 *		  be removed and cleaned up.
 */
void UViewControllerStack::Clear()
{
	if(UViewController* top = Peek())
	{
		top->SetIsReturning(true);
		top->BeforeHide();
		top->Hide(mOnHideComplete);
		mViewsHiding.Add(top);
	}

	mViewControllerStack.Empty();
}

/**
 * @brief Get the item on the top of the stack.
 * @return Returns the top element on the stack, if there is anything in
 * the stack, otherwise will return null.
 */
UViewController* UViewControllerStack::Peek() const
{
	return PeekAtTopOffset(0);
}

/**
 * @brief Sometimes we need the item under the top of the stack, this is that.
 * @return The IViewController one item below the top of the stack.
 */
UViewController* UViewControllerStack::PeekBeforeTop() const
{
	return PeekAtTopOffset(1);
}

/**
 * @brief I feel like I needed this in the past, but I can't remember why.
 * @return The first item in the stack.
 */
UViewController* UViewControllerStack::Bottom() const
{
	return !mViewControllerStack.IsEmpty() ? mViewControllerStack[0] : nullptr;
}

/**
 * @brief Number of ViewControllers in the stack
 * @return Number of elements in the stack
 */
int UViewControllerStack::Count() const
{
	return mViewControllerStack.Num();
}

/**
 * @brief If the stack is empty or not
 * @return true if the stack has more than 0 elements in it, otherwise false
 */
bool UViewControllerStack::IsEmpty() const
{
	return mViewControllerStack.IsEmpty();
}

/**
 * @brief Given a ViewController pointer determines if that specific ViewController
 *	      is somewhere in the stack. This is an O(n) operation.
 * @param ViewController Pointer to search the stack for.
 * @return If found will return the index the ViewController resides at, if not found will return -1.
 */
int UViewControllerStack::IndexOf(const UViewController* ViewController) const
{
	for(int i = 0; i < mViewControllerStack.Num(); i++)
	{
		if(mViewControllerStack[i] == ViewController)
			return i;
	}
	return -1;
}

/**
 * @brief Determines if the provided ViewController pointed is at the bottom (or root) of the stack.
 * @param ViewController Pointer used to check the stack root.
 * @return True if the ViewController pointer is the bottom of the stack, otherwise false.
 *		   Will also be false if the stack is empty.
 */
bool UViewControllerStack::IsRootOfStack(const UViewController* ViewController) const
{
	if(mViewControllerStack.IsEmpty())
		return false;

	return mViewControllerStack[0] == ViewController; 
}

/**
 * @brief Retrieves the ViewController an offset distance from the top.
 * @param Offset The number of items below the top to retrieve the ViewController for.
 *		         0 is the top, 1 is one below the top, etc.
 * @return A valid ViewController if the offset is valid, otherwise nullptr.
 */
UViewController* UViewControllerStack::PeekAtTopOffset(int Offset) const
{
	const int count = mViewControllerStack.Num();
	return count > Offset ? mViewControllerStack[count - (Offset + 1)] : nullptr;
}

/**
 * @brief Helper method to remove the top element of the stack. Mostly added to ease
 *        additional logging later.
 */
void UViewControllerStack::PopBack()
{
	mViewControllerStack.RemoveAt(mViewControllerStack.Num() - 1, 1, false);
}

/**
* @brief Helper method to push the passed in ViewController onto the top of stack. Mostly added to ease
 *        additional logging later.
 * @param ViewController The ViewController to add to the top of the stack.
 */
void UViewControllerStack::PushInternal(UViewController* ViewController)
{
	mViewControllerStack.Add(ViewController);
}

/**
 * @brief Callback triggered when a ViewController transition has completed. Specifically a Show transition.
 * @param ViewController ViewController the transition is complete for. 
 */
void UViewControllerStack::OnShowComplete(UViewController* ViewController)
{
	if(ViewController)
	{
		ViewController->AfterShow();
		ViewController->SetIsReturning(false);
	}
}

/**
 * @brief Callback triggered when a ViewController transition has completed. Specifically a Hide transition.
 * @param ViewController ViewController the transition is complete for. 
 */
void UViewControllerStack::OnHideComplete(UViewController* ViewController)
{
	if(ViewController)
	{
		ViewController->AfterHide();
		ViewController->SetIsReturning(false);
		mViewsHiding.Remove(ViewController);
	}
}
