/**
 * @author Justin Noel
 * @file   ViewControllerStack.h
 */

#pragma once

#include "CoreMinimal.h"
#include "ViewController.h"
#include "ViewControllerStack.generated.h"

/**
 * @brief ViewControllerStack is a stack that manages ViewControllers, I know duh. However, what it does above
 *        and beyond a normal stack is ensure that the various Show related methods and Hide related methods are
 *        invoked on the ViewController as a user Navigates forward or backward.
 *
 *        When a ViewController is Pushed onto a stack, it will have BeforeShow, and then Show invoked, while at the
 *        same time the item on the top of the stack will have it's BeforeHide and Hide invoked. Once the Show and Hide
 *        OnTransitionComplete delegates are invoked, then the AfterShow and AfterHide will be called on the
 *        ViewControllers respectively.
 * 
 *        As a user Pops ViewControllers off, the Top item on the stack will have it's BeforeHide, then Hide methods
 *        invoked. The item below the top of the stack will then have it's BeforeShow and Show method invoked.
 */
UCLASS(BlueprintType)
class UMGINTRO_API UViewControllerStack : public UObject
{
	GENERATED_BODY()
public:
	/**
	 * @brief Sets up the initial callbacks for this ViewControllerStack
	 *		  and general allocations.
	 */
	UViewControllerStack();
	
	/**
	 * @brief Push a ViewController onto this stack, this ensures it can be popped later.
	 *		  Before displaying this ViewController widget the show methods will be invoked.
	 *		  The previous ViewController on the stack will have it's hide methods invoked.
	 * @param ViewController Widget to push on that stack.
	 */
	UFUNCTION(BlueprintCallable)
	void Push(UViewController* ViewController);

	
	/**
	 * @brief Pop the top of the stack, this will ensure the hide methods of the ViewController
	 *		  are invoked, while the show methods of the last ViewController in the stack will
	 *		  be invoked.
	 */
	UFUNCTION(BlueprintCallable)
	void Pop();

	
	/**
	 * @brief This will clear the entire stack. As everything is being cleared off, and cleaned up
	 *		  only the top of the stack will have it's hide methods called. All others will simply
	 *		  be removed and cleaned up.
	 */
	UFUNCTION(BlueprintCallable)
	void Clear();

	/**
	 * @brief Get the item on the top of the stack.
	 * @return Returns the top element on the stack, if there is anything in
	 * the stack, otherwise will return null.
	 */
	UViewController* Peek() const; 
	/**
	 * @brief Sometimes we need the item under the top of the stack, this is that.
	 * @return The IViewController one item below the top of the stack.
	 */
	UViewController* PeekBeforeTop() const;

	/**
	 * @brief I feel like I needed this in the past, but I can't remember why.
	 * @return The first item in the stack.
	 */
	UViewController* Bottom() const;

	
	/**
	 * @brief Number of ViewControllers in the stack
	 * @return Number of elements in the stack
	 */
	UFUNCTION(BlueprintCallable)
	int Count() const;

	/**
	 * @brief If the stack is empty or not
	 * @return true if the stack has more than 0 elements in it, otherwise false
	 */
	UFUNCTION(BlueprintCallable)
	bool IsEmpty() const;

	/**
	 * @brief Given a ViewController pointer determines if that specific ViewController
	 *	      is somewhere in the stack. This is an O(n) operation.
	 * @param ViewController Pointer to search the stack for.
	 * @return If found will return the index the ViewController resides at, if not found will return -1.
	 */
	UFUNCTION(BlueprintCallable)
	int IndexOf(const UViewController* ViewController) const;

	
	/**
	 * @brief Determines if the provided ViewController pointed is at the bottom (or root) of the stack.
	 * @param ViewController Pointer used to check the stack root.
	 * @return True if the ViewController pointer is the bottom of the stack, otherwise false.
	 *		   Will also be false if the stack is empty.
	 */
	UFUNCTION(BlueprintCallable)
	bool IsRootOfStack(const UViewController* ViewController) const;
	
private:
	/**
	 * @brief Retrieves the ViewController an offset distance from the top.
	 * @param Offset The number of items below the top to retrieve the ViewController for.
	 *		         0 is the top, 1 is one below the top, etc.
	 * @return A valid ViewController if the offset is valid, otherwise nullptr.
	 */
	UViewController* PeekAtTopOffset(int Offset) const;

	/**
	 * @brief Helper method to remove the top element of the stack. Mostly added to ease
	 *        additional logging later.
	 */
	void PopBack();
	
	/**
	* @brief Helper method to push the passed in ViewController onto the top of stack. Mostly added to ease
	 *        additional logging later.
	 * @param ViewController The ViewController to add to the top of the stack.
	 */
	void PushInternal(UViewController* ViewController);

	/**
	 * @brief Callback triggered when a ViewController transition has completed. Specifically a Show transition.
	 * @param ViewController ViewController the transition is complete for. 
	 */
	void OnShowComplete(UViewController* ViewController);
	
	/**
	 * @brief Callback triggered when a ViewController transition has completed. Specifically a Hide transition.
	 * @param ViewController ViewController the transition is complete for. 
	 */
	void OnHideComplete(UViewController* ViewController);
	
	/**
	 * @brief General stack manipulation is push/pop, but there are times
	 *	      when we want to manipulate things further down the stack.
	 */
	UPROPERTY()
	TArray<UViewController*> mViewControllerStack;

	/**
	 * @brief Ensures that views are held onto until they are fully hidden, this is only used
	 *	      for views that are returning, meaning they are hiding while being fully removed
	 *	      the stack. 
	 */
	UPROPERTY()
	TArray<UViewController*> mViewsHiding;

	FOnViewTransitionComplete mOnShowComplete;
	FOnViewTransitionComplete mOnHideComplete;
};
