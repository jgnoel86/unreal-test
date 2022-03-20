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

	UFUNCTION(BlueprintCallable)
	int Count() const;

	UFUNCTION(BlueprintCallable)
	bool IsEmpty() const;

	UFUNCTION(BlueprintCallable)
	int IndexOf(const UViewController* ViewController) const;
	
	UFUNCTION(BlueprintCallable)
	bool IsRootOfStack(const UViewController* ViewController) const;
	
private:
	UViewController* PeekAtTopOffset(int Offset) const;

	void PushInternal(UViewController* ViewController);

	void OnShowComplete(UViewController* ViewController);
	void OnHideComplete(UViewController* ViewController);
	/**
	 * @brief General stack manipulation is push/pop, but there are times
	 * when we want to manipulate things further down the stack, so while this
	 * will generally behave like a stack, sometimes we need the functionality of
	 * a pure array.
	 */
	TArray<UViewController*> mViewControllerStack;

	FOnViewTransitionComplete mOnShowComplete;
	FOnViewTransitionComplete mOnHideComplete;
};
