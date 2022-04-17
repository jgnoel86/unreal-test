/**
 *	@author Justin Noel
 * @file   ViewController.cpp
 * @brief A ViewController designed to be pushed into or popped out of a ViewControllerStack.
 *        Alternatively can be managed directly through helper methods. Provides a structured
 *        way of setting up data before a displaying, transitioning between ViewControllers,
 *        and finally tearing down data after the display is hidden.
 */

#include "ViewController.h"

/**
 * @brief Invoked before a ViewController Show is called. This is where data setup would commonly be done.
 */
void UViewController::BeforeShow()
{
}

/**
 * @brief Invoked when a view should start showing itself. If this is overridden be sure to invoke Super::Show
 * @param OnComplete Transition complete delegate that will be invoked externally when the view has completed
 *	                 presenting itself.
 */
void UViewController::Show(FOnViewTransitionComplete OnComplete)
{
	mOnShowComplete = OnComplete;
	OnShow();
}

/**
 * @brief Once the OnComplete delegate is invoked from the previous Show method, this method will fire.
 *        Mostly intended for post show cleanup.
 */
void UViewController::AfterShow()
{
}

/**
 * @brief Invoked before a ViewController Hide is called. Prep to hide a ViewController should happen here.
 */
void UViewController::BeforeHide()
{
}

/**
 * @brief Invoked when a view should start hiding itself. If this is overridden be sure to invoke Super::Hide
 * @param OnComplete Transition complete delegate that will be invoked externally when the view has completed
 *	                 hiding itself.
 */
void UViewController::Hide(FOnViewTransitionComplete OnComplete)
{
	mOnHideComplete = OnComplete;
	OnHide();
}

/**
 * @brief Once the OnComplete delegate is invoked from the previous Hide method, this method will fire.
 *        Mostly intended for cleaning up data after a view has been hidden.
 */
void UViewController::AfterHide()
{
}

/**
 * @brief Should be triggered when a view has completed showing itself. Internally invokes the delegate
 *        passed into the Show method.
 */
void UViewController::ShowComplete()
{
	mOnShowComplete.ExecuteIfBound(this);
}

/**
 * @brief Should be triggered when a view has completed hiding itself. Internally invokes the delegate
 *        passed into the Hide method.
 */
void UViewController::HideComplete()
{
	mOnHideComplete.ExecuteIfBound(this);
}

/**
 * @brief Set the internal bool indicating if the show or hide transition for this ViewController
 *        is a returning transition. IsReturning means a backwards navigation (someone hitting a back button).
 * @param IsReturning Pass in True to indicate this ViewController is in a backwards navigation flow,
 *                    otherwise false.
 */
void UViewController::SetIsReturning(bool IsReturning)
{
	mIsReturning = IsReturning;
}