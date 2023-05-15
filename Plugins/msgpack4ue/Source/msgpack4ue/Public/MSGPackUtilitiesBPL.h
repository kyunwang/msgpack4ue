// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "json/json.hpp"

#include "MSGPackUtilitiesBPL.generated.h"

using json = nlohmann::json;

/**
 *
 */
UCLASS()
class MSGPACK4UE_API UMSGPackUtilitiesBPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MSGPack")
		static bool GetPayloadMsgpackToJson(UPARAM(DisplayName = "MsgpackValue") const TArray<uint8> InMsgpackValue, FJsonObjectWrapper& OutJsonObject);
};
