// Fill out your copyright notice in the Description page of Project Settings.

#include "MSGPackUtilitiesBPL.h"
#include "JsonObjectWrapper.h"
#include "JsonUtilities.h"

#include "Dom/JsonObject.h"
#include "Misc/DefaultValueHelper.h"
#include "Misc/Variant.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Templates/SharedPointer.h"

#include "json/json.hpp"

// Helper function to convert a string to a number sfely
// int32 UMSGPackUtilitiesBPL::SafeStringToInt(const FString& InString)
// {
// 	// if (FDefaultValueHelper::IsStringValidInteger(InString))
// 	if (InString.IsNumeric())
// 	{
// 		int32 Result;
// 		TTypeFromString<int32>::FromString(Result, *InString);
// 		return Result;
// 		// return FCString::Atoi(*InString);
// 	}

// 	UE_LOG(LogTemp, Error, TEXT("Conversion to integer failed for string: %s"), *InString);
// 	return 0; // Value indicating failure
// }

// Helper function to convert a string to a float safely
// float UMSGPackUtilitiesBPL::SafeStringToFloat(const FString& InString)
// {
// 	if (FDefaultValueHelper::IsStringValidFloat(InString))
// 	{
// 		float Result;
// 		TTypeFromString<float>::FromString(Result, *InString);
// 		return Result;
// 		// return FCString::Atof(*InString);
// 	}
// 	UE_LOG(LogTemp, Error, TEXT("Conversion to float failed for string: %s"), *InString);
// 	return 0.0f; // Value indicating failure
// }

// nlohmann::json UMSGPackUtilitiesBPL::SafeJsonParse(const TArray<uint8>& InBuffer, bool& OutbIsSuccessful)
// {
// 	UE_LOG(LogTemp, Warning, TEXT("Starting method SafeJsonParse..."));

// 	OutbIsSuccessful = false;

// 	// Convert TArray<uint8> to string for inspection
// 	FString str(UTF8_TO_TCHAR(reinterpret_cast<const char*>(InBuffer.GetData())));
// 	// UE_LOG(LogTemp, Warning, TEXT("Buffer: %s"), *str);

// 	if (str.IsEmpty()) {
// 		UE_LOG(LogTemp, Error, TEXT("Error: Buffer is empty: %s"), *str);
// 		return nlohmann::json();
// 	}
// 	else {
// 		nlohmann::json JsonResult;
// 		nlohmann::json result;

// 		UE_LOG(LogTemp, Warning, TEXT("Startinfg JSON parsing... %s"), *str);

// 		// Convert FString to std::String for parsing
// 		// std::string stdStr(TCHAR_TO_UTF8(*str));
// 		// auto errorHandler = [&](int /*unused*/, std::string_view /*unused*/, nlohmann::json::parse_error& ex) {
// 		// 	UE_LOG(LogTemp, Error, TEXT("JSON parsing failed: %s"), UTF8_TO_TCHAR(ex.what()));
// 		// 	OutbIsSuccessful = false;
// 		// 	// Additional error handling if needed
// 		// 	return nlohmann::json(nullptr);  // Return a null JSON object
// 		// };

// 		// std::string stdStr(TCHAR_TO_UTF8(*str));

// 		// nlohmann::json JsonResult = nlohmann::json::parse(stdStr, nullptr, errorHandler);

// 		auto errorHandler = [&](int /*unused*/, std::string_view /*unused*/, nlohmann::json::parse_error& ex)
// 			{
// 				UE_LOG(LogTemp, Warning, TEXT("JSON parsing failed: %s"), *FString(ex.what()));
// 				return false;
// 			};

// 		// Convert FString to std::string for parse function
// 		std::string stdStr(TCHAR_TO_UTF8(*str));

// 		if (nlohmann::json::accept(stdStr)) {
// 			UE_LOG(LogTemp, Warning, TEXT("Wants to parse"));
// 			// Cannot use parse - crashed without logging
// 			// return nlohmann::json::parse(stdStr);
// 		}
// 		else
// 			// result = nlohmann::json::parse(stdStr.data(), stdStr.data() + stdStr.size(), nullptr, errorHandler);

// 			// nlohmann::json::parser_callback_t cb = [&](const char* buffer, std::size_t length, bool /*unused*/) -> bool {
// 			// 	stdStr.assign(buffer, length);
// 			// 	return true;
// 			// };

// 			// std::function<bool(int, nlohmann::json::detail::parse_event_t, nlohmann::json&)> callback = cb;

// 			// nlohmann::json JsonResult = nlohmann::json::parse(nlohmann::json::span_input_adapter<std::string>(stdStr), nullptr, errorHandler, callback);

// 			// return nlohmann::json();

// 			if (JsonResult.is_discarded()) {
// 				UE_LOG(LogTemp, Error, TEXT("JSON parsing failed: %s"), *str);
// 				OutbIsSuccessful = false;
// 				return nlohmann::json();
// 			}
// 			else {
// 				UE_LOG(LogTemp, Warning, TEXT("Wants to ok"));

// 				OutbIsSuccessful = true;
// 				return JsonResult;
// 			}

// 		// JsonResult = nlohmann::json::parse(stdStr, errorHandler);
// 		// JsonResult = nlohmann::json::parse(stdStr, nullptr, errorHandler);
// 		// JsonResult = nlohmann::json::parse(stdStr.begin(), stdStr.end(), nullptr, errorHandler);
// 	}

// 	return nlohmann::json();
// }

// 
// Private
// 
bool UMSGPackUtilitiesBPL::ConvertMsgpackToJsonObject(const TArray<uint8>& InBuffer, std::vector<uint8> OutDataVector, nlohmann::json& OutMsgpackJson)
{
	// Convert UE TArray to std::vector for msgpack conversion
	std::vector<uint8> DataVector(InBuffer.GetData(), InBuffer.GetData() + InBuffer.Num());
	OutDataVector = DataVector;

	if (InBuffer.Num() > 0) {
		// Convert DataVector (array of bytes) to msgpack
		json JsonData = json::from_msgpack(DataVector);

		// Check if JsonData is valid JSON
		if (JsonData.is_null()) {
			UE_LOG(LogTemp, Error, TEXT("Error: Invalid JSON, empty message or null received"));
			return false;
		}

		OutMsgpackJson = JsonData;
		return true;
	}

	UE_LOG(LogTemp, Error, TEXT("Received Empty Buffer"));

	return false;
}

// 
// Public
// 
void UMSGPackUtilitiesBPL::ConvertBufferToString(TArray<uint8> InBuffer, FString& OutString)
{
	OutString = FString::FromHexBlob(InBuffer.GetData(), InBuffer.Num());
}


bool UMSGPackUtilitiesBPL::GetPayloadMsgpackToJsonString(TArray<uint8> InMsgpackValue, FString& OutString)
{
	json JsonData;
	std::vector<uint8> DataVector;
	bool bIsSuccessful = ConvertMsgpackToJsonObject(InMsgpackValue, DataVector, JsonData);

	if (!bIsSuccessful) {
		UE_LOG(LogTemp, Error, TEXT("Error: Invalid JSON, empty message or null received"));
		return false;
	}

	FString JsonString = FString(JsonData.dump().c_str());
	OutString = JsonString;

	return true;
}


bool UMSGPackUtilitiesBPL::GetPayloadMsgpackToJson(TArray<uint8> InMsgpackValue, FJsonObjectWrapper& OutJsonObject)
{
	json JsonData;
	std::vector<uint8> DataVector;
	bool bIsSuccessful = ConvertMsgpackToJsonObject(InMsgpackValue, DataVector, JsonData);

	if (!bIsSuccessful) {
		UE_LOG(LogTemp, Error, TEXT("Failed to convert to Object! or received null"));
		return false;
	}

	FString JsonString = FString(JsonData.dump().c_str());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
	TSharedPtr<FJsonObject> JsonObject;

	// Attempt conversion JsonString to valid UE Json Object
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		UE_LOG(LogTemp, Warning, TEXT("Deserialized Object!"));
		OutJsonObject.JsonObject = JsonObject;

		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("Failed to deserialize - %s"), *JsonString);

	return false;
}

bool UMSGPackUtilitiesBPL::GetPayloadMsgpackToArray(TArray<uint8> InMsgpackValue, FJsonObjectWrapper& OutJsonObject)
{
	json JsonData;
	std::vector<uint8> DataVector;
	bool bIsSuccessful = ConvertMsgpackToJsonObject(InMsgpackValue, DataVector, JsonData);

	if (!bIsSuccessful) {
		UE_LOG(LogTemp, Error, TEXT("Failed to convert to Array! or received null"));
		return false;
	}

	// Wrap into an object as UE does not support top-level arrays
	FString JsonString = FString("{ \"array\": ") + FString(JsonData.dump().c_str()) + FString(" }");
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
	TSharedPtr<FJsonObject> JsonObject;

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject)) {
		UE_LOG(LogTemp, Warning, TEXT("Deserialized Top-level array wrapped in \"array\" object key!"));
		OutJsonObject.JsonObject = JsonObject;
		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("Failed to deserialize - %s"), *JsonString);

	return false;
}
