/**
 * @author Justin Noel
 * @file   RestCaller.h
 */

#pragma once

#include "CoreMinimal.h"
#include "EnumRequestVerbs.h"
#include "RestCaller.generated.h"

/**
 * @brief OnComplete delegate invoked when a REST call has completed.
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCallComplete, FString, ResponseData);

/**
 * @brief Helper function library to make basic REST calls.
 */
UCLASS()
class UMGINTRO_API URestCaller : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	/**
	 * @brief Triggers a basic REST call. Right now this is a non-body call. But it would
	 *	      be easy to extend this library to have support for others.
	 * @param Url Destination url to invoke a REST call on.
	 * @param RequestVerb Request type, GET, PUT, POST, DELETE
	 * @param OnComplete Callback delegate to trigger when the call has completed.
	 */
	UFUNCTION(BlueprintCallable, Category = "REST")
    static void MakeRestCall(const FString& Url, ERequestVerbs RequestVerb, FOnCallComplete OnComplete);
};
