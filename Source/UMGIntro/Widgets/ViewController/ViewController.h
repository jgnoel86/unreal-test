/**
 * @author Justin Noel
 * @file   ViewController.h
 * @brief A ViewController designed to be pushed into or popped out of a ViewControllerStack.
 *        Alternatively can be managed directly through helper methods. Provides a structured
 *        way of setting up data before a displaying, transitioning between ViewControllers,
 *        and finally tearing down data after the display is hidden.
 */

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ViewController.generated.h"


/**
 * @brief Delegate triggered when a views transition is complete.
 *	      The ViewController is passed into the delegate.
 */
DECLARE_DELEGATE_OneParam(FOnViewTransitionComplete, class UViewController*);

/**
 * @brief ViewController, a UUserWidget base class used to make a stack based navigation flow simpler to develop.
 */
UCLASS()
class UMGINTRO_API UViewController : public UUserWidget
{
	GENERATED_BODY()
public:
	/**
	 * @brief Invoked before a ViewController Show is called. This is where data setup would commonly be done.
	 */
	virtual void BeforeShow();

	/**
	 * @brief Invoked when a view should start showing itself. If this is overridden be sure to invoke Super::Show
	 * @param OnComplete Transition complete delegate that will be invoked externally when the view has completed
	 *	                 presenting itself.
	 */
	virtual void Show(FOnViewTransitionComplete OnComplete);

	/**
	 * @brief Once the OnComplete delegate is invoked from the previous Show method, this method will fire.
	 *        Mostly intended for post show cleanup.
	 */
	virtual void AfterShow();
	
	/**
	 * @brief Invoked before a ViewController Hide is called. Prep to hide a ViewController should happen here.
	 */
	virtual void BeforeHide();
	
	/**
	 * @brief Invoked when a view should start hiding itself. If this is overridden be sure to invoke Super::Hide
	 * @param OnComplete Transition complete delegate that will be invoked externally when the view has completed
	 *	                 hiding itself.
	 */
	virtual void Hide(FOnViewTransitionComplete OnComplete);
	
	/**
	 * @brief Once the OnComplete delegate is invoked from the previous Hide method, this method will fire.
	 *        Mostly intended for cleaning up data after a view has been hidden.
	 */
	virtual void AfterHide();
	
	/**
	 * @brief Will trigger when the Show method is invoked. Provides a means for blueprints to handle starting
	 *        a displaying animation.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnShow();
	
	/**
	 * @brief Will trigger when the Hide method is invoked. Provides a means for blueprints to handle starting
	 *        a hiding animation.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnHide();
	
	/**
	 * @brief Should be triggered when a view has completed showing itself. Internally invokes the delegate
	 *        passed into the Show method.
	 */
	UFUNCTION(BlueprintCallable)
	void ShowComplete();
	
	/**
	 * @brief Should be triggered when a view has completed hiding itself. Internally invokes the delegate
	 *        passed into the Hide method.
	 */
	UFUNCTION(BlueprintCallable)
	void HideComplete();

	/**
	 * @brief Set the internal bool indicating if the show or hide transition for this ViewController
	 *        is a returning transition. IsReturning means a backwards navigation (someone hitting a back button).
	 * @param IsReturning Pass in True to indicate this ViewController is in a backwards navigation flow,
	 *                    otherwise false.
	 */
	void SetIsReturning(bool IsReturning);
	
protected:
	
	/**
	 * @brief IsReturning means a backwards navigation (someone hitting a back button).
	 */
	UPROPERTY(BlueprintReadOnly)
	bool mIsReturning;

private:
	/**
	 * @brief Delegate passed into the Show method
	 */
	FOnViewTransitionComplete mOnShowComplete;
	/**
	 * @brief Delegate passed into the Hide method
	 */
	FOnViewTransitionComplete mOnHideComplete;
};
