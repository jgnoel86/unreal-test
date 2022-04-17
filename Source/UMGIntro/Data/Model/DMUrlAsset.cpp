/**
 * @author Justin Noel
 * @file   DMUrlAsset.cpp
 */

#include "DMUrlAsset.h"

/**
 * @brief Invoked to setup the unreal instance of the deserialized object.
 * @param Record Deserialized struct to convert into unreal object.
 */
void UDMUrlAsset::Initialize(const FDMUrlAssetRecord& Record)
{
    mId = Record.id;
    mUrl = Record.url;
}
