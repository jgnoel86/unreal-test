/**
 * @author Justin Noel
 * @file   ViewControllerStackManager.cpp
 */


#include "ViewControllerStackManager.h"

/**
 * @brief Given an id, return the stack. If a stack does not actively exist for the provided Id a new one will be
 *        created. While the ID is an int, at the blueprint level a datatable is used to track a more user friendly
 *        name to id.
 * @param StackId The integer id for the specific stack to retrieve.
 * @return A valid stack to use with ViewControllers.
 */
UViewControllerStack* UViewControllerStackManager::GetStack(int StackId)
{
    if(mStackMap.Contains(StackId))
        return mStackMap[StackId];
    
    UViewControllerStack* stack = NewObject<UViewControllerStack>(this);
    mStackMap.Add(StackId, stack);
    return stack;
}
