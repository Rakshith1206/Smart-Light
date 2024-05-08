#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "Beast Gogeta"; // Replace with your Wi-Fi SSID
const char* password = "instagram"; // Replace with your Wi-Fi password

WiFiClient client;

unsigned long myChannelNumber = 2285389; // ThingSpeak channel number
const char * myWriteAPIKey = "XCZL7HQUFCL9FRDR"; // ThingSpeak write API key
const char * myReadAPIKey = "LJ24LIGM1ARTNVPL"; // ThingSpeak read API key

int led1 = D3; // GPIO pin for LED

void setup() {
    Serial.begin(9600); // Initialize serial communication
    pinMode(led1, OUTPUT); // Set LED pin as output
    WiFi.begin(ssid, password); // Connect to Wi-Fi network
    ThingSpeak.begin(client); // Initialize ThingSpeak client
}

void loop() {
    int s1 = digitalRead(D7); // Read digital value from IR sensor
    if (s1 == 0) {
        digitalWrite(led1, LOW); // Turn off LED if sensor detects no motion
    } else {
        digitalWrite(led1, HIGH); // Turn on LED if sensor detects motion
    }

    // Upload sensor data to ThingSpeak
    ThingSpeak.writeField(myChannelNumber, 2, s1, myWriteAPIKey); // Upload IR sensor data
    ThingSpeak.writeField(myChannelNumber, 5, led1, myWriteAPIKey); // Upload LED state

    // Read LED state from ThingSpeak and control LED accordingly
    int led_1 = ThingSpeak.readIntField(myChannelNumber, 5, myReadAPIKey);
    if (led_1 == 1) {
        digitalWrite(led1, HIGH); // Turn on LED if commanded by ThingSpeak
    } else {
        digitalWrite(led1, LOW); // Turn off LED if commanded by ThingSpeak
    }
}
