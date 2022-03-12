// Fill out your copyright notice in the Description page of Project Settings.


#include "RestCaller.h"
#include "EnumRequestVerbs.h"

#define BOOL_TO_STRING(b) b ? TEXT("True") : TEXT("False")

namespace
{
	const TMap<ERequestVerbs, FString> ERequestVerbNameMap =
	{
        { ERequestVerbs::GET, "GET" },
        { ERequestVerbs::POST, "POST" },
        { ERequestVerbs::PUT, "PUT" },
        { ERequestVerbs::DELETE, "DELETE" }
	};

}

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

void URestCaller::PrintResponse(const FString& response)
{
	UE_LOG(LogTemp, Warning, TEXT("Printing Response %s"), *response);
}

void URestCaller::OnResponseReceived(
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
	
	int responseCode = Response->GetResponseCode();
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
