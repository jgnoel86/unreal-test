// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Model/FDMApp.h"
#include "Subsystems/EngineSubsystem.h"
#include "Http.h"
#include "AppRetriever.generated.h"

/**
 * 
 */


DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAppDataCallComplete, const FDMApp&, Data);

UCLASS()
class UMGINTRO_API UAppRetriever : public UEngineSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
    void GetApplicationData(const FString& Url, FOnAppDataCallComplete OnComplete);

	UFUNCTION(BlueprintCallable)
	static void PrintResponseData(UPARAM(ref) const FDMApp& data);
private:
    FDMApp mAppData;
	static void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnAppDataCallComplete onComplete);
};
