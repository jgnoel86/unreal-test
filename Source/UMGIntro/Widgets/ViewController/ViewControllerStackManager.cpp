// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewControllerStackManager.h"

UViewControllerStack* UViewControllerStackManager::GetStack(int StackId)
{
    if(mStackMap.Contains(StackId))
        return mStackMap[StackId];
    
    UViewControllerStack* stack = NewObject<UViewControllerStack>(this);
    mStackMap.Add(StackId, stack);
    return stack;
}
