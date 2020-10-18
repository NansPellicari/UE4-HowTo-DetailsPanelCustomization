#pragma once

#include "CoreMinimal.h"

#include "MyStruct.generated.h"

UENUM(BlueprintType)
enum class EValueType : uint8
{
	AMOUNT UMETA(DisplayName = "Amount"),
	RANGE UMETA(DisplayName = "Range")
};

USTRUCT(BlueprintType)
struct FMyStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice")
	EValueType Type = EValueType::AMOUNT;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Amount")
	float Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")
	float RangeMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Range")
	float RangeMax;
};
