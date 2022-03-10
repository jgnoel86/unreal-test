// Fill out your copyright notice in the Description page of Project Settings.


#include "RestCaller.h"
#include "EnumRequestVerbs.h"

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

void URestCaller::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnCallComplete OnComplete)
{
	FString responseContent;
	UE_LOG(LogTemp, Warning, TEXT("OnResponseReceived"));
	
	if (bWasSuccessful)
	{
		responseContent = Response->GetContentAsString();
	}
	
	OnComplete.ExecuteIfBound(responseContent);
}