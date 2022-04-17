/**
 * @author Justin Noel
 * @file   DMBase.cpp
 */

#include "DMBase.h"
#include "DMUrlAsset.h"

/**
 * @brief Invoked to setup the unreal instance of the deserialized object.
 * @param Record Base object record to initialize the base Unreal object from.
 */
void UDMBase::Initialize(const FDMBaseRecord& Record)
{
    mId = Record.id;
    mName = Record.name;
    
    mImage = NewObject<UDMUrlAsset>(this);
    mImage->Initialize(Record.image);
}
