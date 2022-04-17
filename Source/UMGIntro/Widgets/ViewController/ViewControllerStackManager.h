/**
 * @author Justin Noel
 * @file   ViewControllerStackManager.h
 */

#pragma once

#include "CoreMinimal.h"
#include "ViewControllerStack.h"
#include "UObject/Object.h"
#include "ViewControllerStackManager.generated.h"

/**
 * @brief A managing system that tracks the ViewControllerStack objects that exist. Stacks are not currently removed,
 *        in a real world setup, we might want a way to remove them, but right now everything lives on one stack
 *        so there is no need.
 */
UCLASS()
class UMGINTRO_API UViewControllerStackManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /**
     * @brief Given an id, return the stack. If a stack does not actively exist for the provided Id a new one will be
     *        created. While the ID is an int, at the blueprint level a datatable is used to track a more user friendly
     *        name to id.
     * @param StackId The integer id for the specific stack to retrieve.
     * @return A valid stack to use with ViewControllers.
     */
    UFUNCTION(BlueprintCallable)
    UViewControllerStack* GetStack(int StackId);

private:
    /**
	 * @brief The map that tracks the currently active stacks.
	 */
	UPROPERTY()
    TMap<int, UViewControllerStack*> mStackMap;
};
