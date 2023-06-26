# msgpack4ue - A simple Msgpack decoding plugin for Unreal Engine

> msgpack4ue is a Unreal Engine plugin which enables decoding of msgpack into UE compliant JSON and primitives. 

The primary usage of this plugin is to enable consuming msgpack data over MQTT.  
- [Tasks board](https://github.com/users/kyunwang/projects/1/views/1)

| *The plugin has been developed and built with Unreal Engine 5.1.1*

- [Features](#features)
- [Supported platforms](#supported-platforms)
- [Setup](#setup)
- [Limitations](#limitations)
- [Links](#links)

## Features
- Decoding of msgpack format (`TArray<uint8>`) into
  - UE Json
  - Top-level array (wrapped in `{ "array": [...] }`)
  - Empty/Null (Caught as failed)
  - ~~Primitives (String, Integer, Floats, Booleans)~~ - Soon
<!-- - Encoding UE JSON into msgpack format  -->

## Supported platforms
Currently tested and confirmed to be working on:

- Windows x64
- Mac OS Ventura (Apple Silicon)

## Setup
- Download the plugin from [releases](https://github.com/kyunwang/msgpack4ue/releases)
- Unzip and place into your project's Plugin directory
- Enable the plugin in the Plugins window in the UE Editor
- The plugin contains an example blueprint which can be used to test the plugin namely, `ACT_BasicDecode`

*P.S. Clone the repo for an example the plugin and MQTT. Code in BP ACT_MsgpackWithMQTT_Example*

## Limitations
- Input must be `TArray<uint8>`
- Input must be valid JSON
<!-- - or a pimitive type -->
At time of writing:


<!-- ## Known Issues

Regarding Epic's MQTT plugin not this plugin:
- On MacOS - Crashes UE editor on exit play/simulate if the MQTT credentials/connection is incorrect/failed -->

## Links
- [Msgpack](https://msgpack.org/)