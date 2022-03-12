// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "EnumRequestVerbs.h"
#include "RestCaller.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCallComplete, FString, ResponseData);

UCLASS()
class UMGINTRO_API URestCaller : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "REST")
    static void MakeRestCall(const FString& Url, ERequestVerbs RequestVerb, FOnCallComplete OnComplete);

	UFUNCTION(BlueprintCallable, Category = "REST")
	static void PrintResponse(const FString& response);

private:

	static void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnCallComplete onComplete);
};
