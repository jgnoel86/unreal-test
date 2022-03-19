// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ViewController.generated.h"

/**
 * 
 */
DECLARE_DELEGATE_OneParam(FOnViewTransitionComplete, class UViewController*);

UCLASS()
class UMGINTRO_API UViewController : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void BeforeShow();
	virtual void Show(FOnViewTransitionComplete OnComplete);
	virtual void AfterShow();
	
	virtual void BeforeHide();
	virtual void Hide(FOnViewTransitionComplete OnComplete);
	virtual void AfterHide();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShow();
	UFUNCTION(BlueprintImplementableEvent)
	void OnHide();
	
	UFUNCTION(BlueprintCallable)
	void ShowComplete();
	UFUNCTION(BlueprintCallable)
	void HideComplete();

	void SetIsReturning(bool IsReturning);
	
protected:
	UPROPERTY(BlueprintReadOnly)
	bool mIsReturning;
	
	FOnViewTransitionComplete mOnShowComplete;
	FOnViewTransitionComplete mOnHideComplete;
};
