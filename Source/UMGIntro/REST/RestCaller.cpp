/**
 * @author Justin Noel
 * @file   RestCaller.cpp
 */

#include "RestCaller.h"
#include "EnumRequestVerbs.h"
#include "Http.h"

/**
 * @brief Helper macro to perform a bool to string conversion.
 * @param b bool to convert to True or False 
 */
#define BOOL_TO_STRING(b) b ? TEXT("True") : TEXT("False")

namespace
{
    /**
     * @brief Request map allows Enum selection to be used at the blue print level, and converted to the required
     *        string for use with the Request object.
     */
    const TMap<ERequestVerbs, FString> ERequestVerbNameMap =
    {
        { ERequestVerbs::GET, "GET" },
        { ERequestVerbs::POST, "POST" },
        { ERequestVerbs::PUT, "PUT" },
        { ERequestVerbs::DELETE, "DELETE" }
    };

}

/**
 * @brief Callback triggered by IHTTPRequest OnProcessRequestComplete
 * @param Request Original request that ultimately triggered this callback.
 * @param Response Response object after the request has completed.
 * @param bWasSuccessful If the call was successful.
 * @param OnComplete OnComplete callback delegate that was originally passed into the MakeRestCall.
 */
void OnResponseReceived(
    FHttpRequestPtr Request,
    FHttpResponsePtr Response,
    bool bWasSuccessful,
    FOnCallComplete OnComplete)
{
    UE_LOG(LogTemp, Log, TEXT("OnResponseReceived"));
    
    FString responseContent;
    if(!Response.IsValid())
    {
        responseContent = "Unable to process request.";
        return;
    }
    
    const int responseCode = Response->GetResponseCode();
    if (bWasSuccessful && EHttpResponseCodes::IsOk(responseCode))
    {
        responseContent = Response->GetContentAsString();
    }
    else
    {
        responseContent = FString::Printf(TEXT("Http Error occured code: %d"), responseCode);
    }
    
    // ReSharper disable once CppExpressionWithoutSideEffects
    OnComplete.ExecuteIfBound(responseContent);
}

/**
 * @brief Triggers a basic REST call. Right now this is a non-body call. But it would
 *	      be easy to extend this library to have support for others.
 * @param Url Destination url to invoke a REST call on.
 * @param RequestVerb Request type, GET, PUT, POST, DELETE
 * @param OnComplete Callback delegate to trigger when the call has completed.
 */
void URestCaller::MakeRestCall(const FString& Url, ERequestVerbs RequestVerb, FOnCallComplete OnComplete)
{
    const FString verbName = ERequestVerbNameMap[RequestVerb];
    UE_LOG(LogTemp, Warning, TEXT("%s Request to: %s"), *verbName, *Url);

    const TSharedRef<IHttpRequest> request = FHttpModule::Get().CreateRequest();

    request->OnProcessRequestComplete().BindStatic(&OnResponseReceived, OnComplete);

    request->SetURL(Url);

    request->SetVerb(verbName);

    request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");

    request->ProcessRequest();
}
