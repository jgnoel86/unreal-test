// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ViewController.h"
#include "ViewControllerStack.generated.h"

/**
 * @brief There are few ways to go with stack, the common when the app is pure UI
 * is simply to hide the top of the stack as a new view controller is pushed on.
 * However, given that we may want UI to live in the game, I'm instead going to
 * try to go with an approach of potentially rebuilding the UI, as we go backwards.
 */
UCLASS(BlueprintType)
class UMGINTRO_API UViewControllerStack : public UObject
{
	GENERATED_BODY()
public:
	UViewControllerStack();
	
	UFUNCTION(BlueprintCallable)
	void Push(UViewController* ViewController);
	
	UFUNCTION(BlueprintCallable)
	void Pop();
	
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
	 * is somewhere in the stack. This is an O(n) operation.
	 * @param ViewController Pointer to search the stack for.
	 * @return If found will return the index the ViewController resides at, if not found will return -1.
	 */
	UFUNCTION(BlueprintCallable)
	int IndexOf(const UViewController* ViewController) const;

	
	/**
	 * @brief Determines if the provided ViewController pointed is at the bottom (or root) of the stack.
	 * @param ViewController Pointer used to check the stack root.
	 * @return True if the ViewController pointer is the bottom of the stack, otherwise false.
	 * Will also be false if the stack is empty.
	 */
	UFUNCTION(BlueprintCallable)
	bool IsRootOfStack(const UViewController* ViewController) const;
	
private:
	UViewController* PeekAtTopOffset(int Offset) const;

	void PopBack();
	void PushInternal(UViewController* ViewController);

	void OnShowComplete(UViewController* ViewController);
	void OnHideComplete(UViewController* ViewController);
	/**
	 * @brief General stack manipulation is push/pop, but there are times
	 * when we want to manipulate things further down the stack, so while this
	 * will generally behave like a stack, sometimes we need the functionality of
	 * a pure array.
	 */
	UPROPERTY()
	TArray<UViewController*> mViewControllerStack;

	UPROPERTY()
	TArray<UViewController*> mViewsHiding;

	FOnViewTransitionComplete mOnShowComplete;
	FOnViewTransitionComplete mOnHideComplete;
};
