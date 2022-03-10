// Fill out your copyright notice in the Description page of Project Settings.


#include "AppRetriever.h"
#include "JsonObjectConverter.h"
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


void UAppRetriever::PrintResponseData(const FDMApp& data)
{
	for(int i = 0; i < data.collectionList.Num(); i++)
	{
		const FDMCollection& collection = data.collectionList[i];
		UE_LOG(LogTemp, Warning, TEXT("Collection id %s"), *collection.name, *collection.id);
	}
}
void UAppRetriever::GetApplicationData(const FString& Url, FOnAppDataCallComplete OnComplete)
{
	const FString verbName = ERequestVerbNameMap[ERequestVerbs::GET];
	UE_LOG(LogTemp, Warning, TEXT("%s Request to: %s"), *verbName, *Url);

	const TSharedRef<IHttpRequest> request = FHttpModule::Get().CreateRequest();

	request->OnProcessRequestComplete().BindStatic(&OnResponseReceived, OnComplete);

	request->SetURL(Url);

	request->SetVerb(verbName);

	request->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");

	request->ProcessRequest();
}

void UAppRetriever::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnAppDataCallComplete OnComplete)
{
	FString requestUrl = Request->GetURL();
	FDMApp appData;
	
	if (bWasSuccessful)
	{
		const FString responseContent = Response->GetContentAsString();
		FJsonObjectConverter::JsonObjectStringToUStruct(responseContent, &appData, 0, 0);
	}
	
	OnComplete.ExecuteIfBound(appData);
}