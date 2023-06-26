// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Json.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Variant.h"
#include "Serialization/JsonSerializer.h"
#include "Templates/SharedPointer.h"

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

private:
	// static bool TryConvertFromMsgpack(TArray<uint8> InMsgpackValue, json& OutJsonData) noexcept;
	// static int32 SafeStringToInt(const FString& InString);
	// static float SafeStringToFloat(const FString& InString);
	// static nlohmann::json SafeJsonParse(const TArray<uint8>& InBuffer, bool& OutbIsSuccessful);

	static bool ConvertMsgpackToJsonObject(const TArray<uint8>& InBuffer, std::vector<uint8> OutDataVector, nlohmann::json& OutMsgpackJson);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MSGPack")
	static void ConvertBufferToString(UPARAM(DisplayName = "Buffer") const TArray<uint8> InBuffer, FString& OutString);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MSGPack")
	static bool GetPayloadMsgpackToJsonString(UPARAM(DisplayName = "MsgpackValue") const TArray<uint8> InMsgpackValue, FString& OutString);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MSGPack")
	static bool GetPayloadMsgpackToJson(UPARAM(DisplayName = "MsgpackValue") const TArray<uint8> InMsgpackValue, FJsonObjectWrapper& OutJsonObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MSGPack")
	static bool GetPayloadMsgpackToArray(UPARAM(DisplayName = "MsgpackValue") const TArray<uint8> InMsgpackValue, FJsonObjectWrapper& OutJsonObject);

};
