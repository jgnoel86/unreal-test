/**
 * @author Justin Noel
 * @file   DMBaseItemCardView.h
 */

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Data/Model/DMBase.h"
#include "DMBaseItemCardView.generated.h"

/**
 * @brief A BaseItemCard is simply a card displayed in a collection view, that can be clicked on
 *		  and will navigate to a Collection or an Item. Though they could be passive instead of active.
 */
UCLASS()
class UMGINTRO_API UDMBaseItemCardView : public UUserWidget
{
	GENERATED_BODY()
public:

	/**
	 * @brief Invoked from SetupData, allowing a blueprint to decide how it wants to setup an image
	 *        given a url.
	 * @param Url Url where the image is hosted, could be remote or local.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void SetupImage(const FString& Url);

	/**
	 * @brief Invoked from SetupData, allow a blueprint to handle setting up the card title.
	 * @param Title title that should be displayed.
	 *              In real world, there would be localization data that came with the original object, and the
	 *              SetupTitle event would only be invoked with the localized data.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void SetupTitle(const FString& Title);
	
	/**
	 * @brief Invoked from SetupData if this card's base item is a Collection object.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void SetupCollection();
	
	/**
	 * @brief Invoked by a blueprint to ensure this card is setup.
	 * @param BaseItem Base item that this card should display.
	 */
	UFUNCTION(BlueprintCallable)
	void SetupData(const UDMBase* BaseItem);

protected:
	
	/**
	 * @brief Does this card represent a collection. This is useful as collections often display slightly differently.
	 */
	UPROPERTY(BlueprintReadOnly)
	bool mIsCollection;

	/**
	 * @brief BaseItem is held onto by the card only to ensure it can be passed forward to the next View.
	 */
	UPROPERTY(BlueprintReadOnly)
	const UDMBase* mBaseItem;
};
