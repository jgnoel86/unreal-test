#pragma once

#include "EnumRequestVerbs.generated.h"

UENUM(BlueprintType)
enum class ERequestVerbs : uint8
{
	GET UMETA(DisplayName = "GET"),
	POST UMETA(DisplayName = "POST"),
	PUT UMETA(DisplayName = "PUT"),
	DELETE UMETA(DisplayName = "DELETE")
};