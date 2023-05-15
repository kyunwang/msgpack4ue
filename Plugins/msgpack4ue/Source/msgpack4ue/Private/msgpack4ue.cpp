// Copyright Epic Games, Inc. All Rights Reserved.

#include "msgpack4ue.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "Fmsgpack4ueModule"

void Fmsgpack4ueModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("msgpack4ue")->GetBaseDir();
}

void Fmsgpack4ueModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(Fmsgpack4ueModule, msgpack4ue)
