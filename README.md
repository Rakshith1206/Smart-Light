
# Smart Street Light Controller

This repository contains code for a smart street light controller using ESP8266 NodeMCU and ThingSpeak for IoT integration.

## Description

The smart street light controller is designed to activate street lights based on ambient light conditions and human presence. It utilizes PIR sensors to detect motion and ThingSpeak for real-time data exchange and remote monitoring. The system aims to reduce power consumption by activating street lights only when necessary.

## How to Run

To run this code, follow these steps:

1. **Hardware Setup**: Connect the ESP8266 NodeMCU board to your computer via USB. Ensure that the required LEDs and PIR sensors are properly connected to the GPIO pins of the NodeMCU board.

2. **Software Setup**:
    - Install the Arduino IDE from [here](https://www.arduino.cc/en/software).
    - Install the ESP8266 board manager in the Arduino IDE. Go to File -> Preferences, and in the "Additional Board Manager URLs" field, add the following URL: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`. Then, go to Tools -> Board -> Boards Manager, search for "esp8266" and install the package.
    - Install the required libraries:
        - ESP8266WiFi
        - WiFiClient
        - ThingSpeak

3. **ThingSpeak Setup**:
    - Sign up for a ThingSpeak account at [https://thingspeak.com/](https://thingspeak.com/).
    - Create a new channel and note down the Channel ID, Write API Key, and Read API Key.

4. **Code Modification**:
    - Open the `StreetLightController.ino` file in the Arduino IDE.
    - Replace the placeholders in the code (Wi-Fi SSID, password, ThingSpeak channel number, API keys) with your actual credentials and information.

5. **Upload Code**:
    - Select the appropriate board from Tools -> Board -> NodeMCU 1.0 (ESP-12E Module).
    - Click on the "Upload" button to compile and upload the code to the NodeMCU board.

6. **Monitor Output**:
    - Open the Serial Monitor in the Arduino IDE (Tools -> Serial Monitor) to monitor the output and debug if necessary.

7. **Deploy**: 
    - Once uploaded, the NodeMCU will run the code and control the street lights based on the presence detected by the PIR sensors and the data received from ThingSpeak.

## ThingSpeak

ThingSpeak is an IoT analytics platform service that allows you to aggregate, visualize, and analyze live data streams in the cloud. You can sign in to ThingSpeak using your account credentials and create channels to collect data from IoT devices. The provided API keys enable communication between your ESP8266 device and ThingSpeak servers for real-time data exchange and monitoring.

## Requirements

- ESP8266 NodeMCU board
- LEDs
- PIR sensors
- Arduino IDE
- ESP8266 board manager
- ESP8266WiFi library
- WiFiClient library
- ThingSpeak library
