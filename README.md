# ESP32-S3-RBG-Web-Controller

## INTRODUCTION
-This project controls an RGB LED using ESP32-S3 in WiFi AP mode.
Users can connect to the hotspot and control the LED through a web page.

## Features

- WiFi hotspot (AP mode)
- Web-based control interface
- RGB LED color switching
- No internet required

## Hardware

- ESP32-S3 development board
- Built-in RGB LED (WS2812)

## How to Use

1. Upload the code to ESP32-S3
2. Connect to WiFi: ESP32-S3
3. Open browser and go to: 192.168.4.1
4. Click buttons to control RGB LED

## Problems & Solutions

- LED not lighting → changed GPIO pin
- Wrong colors → adjusted RGB order (NEO_GRB)
- Serial port disappearing → reselect port

## Future Improvements

- Add color picker
- Add brightness control
- Improve UI design
