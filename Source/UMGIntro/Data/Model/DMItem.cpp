#include "DMItem.h"

void UDMItem::Initialize(const FDMItemRecord& record)
{
    Super::Initialize(record);

    mDescription = record.description;
}
