#include "DMCollection.h"

const FDMCollection FDMCollection::SInvalidCollection = FDMCollection();

bool FDMCollection::IsValid(const FDMCollection& Collection)
{
    return &Collection != &SInvalidCollection;
}
