#include "DMUrlAsset.h"

void UDMUrlAsset::Initialize(const FDMUrlAssetRecord& record)
{
    mId = record.id;
    mUrl = record.url;
}
