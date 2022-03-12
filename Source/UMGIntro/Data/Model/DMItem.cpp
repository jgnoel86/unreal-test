#include "DMItem.h"

const FDMItem FDMItem::SInvalidItem = FDMItem();

bool FDMItem::IsValid(const FDMItem& item)
{
    return &item != &SInvalidItem;
}
