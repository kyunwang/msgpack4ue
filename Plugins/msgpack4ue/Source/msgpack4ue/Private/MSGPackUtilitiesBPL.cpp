// Fill out your copyright notice in the Description page of Project Settings.

#include "MSGPackUtilitiesBPL.h"
// import missing header
// #include "JsonUtilities.h"
#include "JsonObjectWrapper.h"
#include "Templates/SharedPointer.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"



bool UMSGPackUtilitiesBPL::GetPayloadMsgpackToJson(TArray<uint8> InMsgpackValue, FJsonObjectWrapper& OutJsonObject)
{
	// 1. Decode binary msgpack to msgpack
	// 2. Attempt conversion to JSON then convert to JSON string
	// 3. Attempt to deserialize JSON string to FJsonObject to support UE typesystem
	std::vector<uint8> DataVector(InMsgpackValue.GetData(), InMsgpackValue.GetData() + InMsgpackValue.Num());
	json JsonData = json::from_msgpack(DataVector);
	FString JsonString = FString(JsonData.dump().c_str());

	TSharedPtr<FJsonObject> JsonObject;

	// Returns bool - assign to JsonObject to check if successful
	if (FJsonSerializer::Deserialize(TJsonReaderFactory<TCHAR>::Create(JsonString), JsonObject))
	{
		OutJsonObject.JsonObject = JsonObject;
		return true;
	}


	return false;
}
