# msgpack4ue - A simple Msgpack decoding plugin for Unreal Engine

> msgpack4ue is a Unreal Engine plugin which enables decoding of msgpack into UE compliant JSON. 

The primary usage of this plugin is to enable consuming msgpack data over MQTT. 

| *The plugin has been developed and built with Unreal Engine 5.1.1*

- [Features](#features)
- [Supported platforms](#supported-platforms)
- [Setup](#setup)
- [Important](#important)


## Features
- Decoding of binary Msgpack (`TArray<uint8>`) into UE compliant JSON

## Supported platforms
Currently tested and confirmed to be working on:

- Windows x64
- Mac OS Ventura

## Setup

- Download the plugin from releases
- Unzip and place into your project's Plugin directory
- Enable the plugin in the Plugins window in the UE Editor
- The plugin contains an example blueprint which can be used to test the plugin namely, `ACT_BasicDecode`

*P.S. Clone the repo for a simple example which uses MQTT implementation*

## Important
At time of writing:
- The MQTT plugin the example uses is the MQTT Plugin from Unreal Engine
- The msgpack type is exptected to be `TArray<uint8>` (As returned by the MQTT Plugin)


## Known Issues

Regarding Epic's MQTT plugin not this plugin:
- On MacOS - Crashes UE editor on exit play/simulate if the MQTT credentials/connection is incorrect/failed


## TODO
- [ ] Add support for encoding JSON into msgpack