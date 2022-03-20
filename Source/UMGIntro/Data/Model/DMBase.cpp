#include "DMBase.h"
#include "DMUrlAsset.h"

void UDMBase::Initialize(const FDMBaseRecord& record)
{
    mId = record.id;
    mName = record.name;
    
    mImage = NewObject<UDMUrlAsset>(this);
    mImage->Initialize(record.image);
}
