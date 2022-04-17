/**
 * @author Justin Noel
 * @file   DMItem.cpp
 */
#include "DMItem.h"

/**
 * @brief Invoked to setup the unreal instance of the deserialized object.
 * @param Record Deserialized struct to convert into unreal object.
 */
void UDMItem::Initialize(const FDMItemRecord& Record)
{
    Super::Initialize(Record);

    mDescription = Record.description;
}
