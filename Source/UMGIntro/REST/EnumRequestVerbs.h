/**
 * @author Justin Noel
 * @file   EnumRequestVerbs.h
 */

#pragma once

#include "EnumRequestVerbs.generated.h"

/**
 * @brief Request enum to support drop down in blueprints.
 */
UENUM(BlueprintType)
enum class ERequestVerbs : uint8
{
	GET UMETA(DisplayName = "GET"),
	POST UMETA(DisplayName = "POST"),
	PUT UMETA(DisplayName = "PUT"),
	DELETE UMETA(DisplayName = "DELETE")
};