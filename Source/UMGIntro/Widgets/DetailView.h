/**
 * @author Justin Noel
 * @file   DetailView.h
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "UMGIntro/Data/Model/DMBase.h"
#include "UMGIntro/Data/Model/DMItem.h"
#include "UObject/Object.h"
#include "ViewController/ViewController.h"
#include "DetailView.generated.h"

/**
 * @brief DetailView is a ViewController that displays more specific information about a detail view.
 */
UCLASS()
class UMGINTRO_API UDetailView : public UViewController
{
    GENERATED_BODY()
public:
    /**
     * @brief Called by a blueprint to set the specific item that detailed information should be shown for.
     * @param Item Item that will be used to setup this detail view.
     */
    UFUNCTION(BlueprintCallable)
    void SetupData(const UDMItem* Item);

    /**
     * @brief Invoked from SetupData to allow a blueprint to setup the title.
     * @param Title Title that should be setup on the detail view.
     */
    UFUNCTION(BlueprintImplementableEvent)
    void SetupTitle(const FString& Title);
    
    /**
     * @brief Invoked from SetupData to allow a blueprint to setup an image representing the detail item.
     * @param ImageUrl ImageUrl where the image lives.
     */
    UFUNCTION(BlueprintImplementableEvent)
    void SetupImage(const FString& ImageUrl);
    
    /**
     * @brief Invoked from the SetupData to allow a blueprint to setup a description representing the detail item.
     * @param Description Description string that should be presented on the detail view.
     */
    UFUNCTION(BlueprintImplementableEvent)
    void SetupDescription(const FString& Description);
};
