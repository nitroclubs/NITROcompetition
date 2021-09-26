#include <Arduino.h>

// NITROcompetition is a NITRObot librarry, used to communicate with the competition server.
// via an ESP-01 module (flashed and configured with Tasmota firmware) connected to the Arduino Mega on pins 20 and 21.
// NITRObot gets the start signal and sends finish signal to the server (over MQTT protocol) via the ESP-01 WiFi module.
// Download and install the librarry from https://github.com/nitroclubs/NITROcompetition.git
#include <NITROcompetition.h>

// PREREQUISITS:
// ESP-01 module flashed with Tasmota firmware and configured following the instructions on:
// https://nitroclubs.eu/

// CONNECTIONS:
// Connect NITRObot (Arduino Mega) pin 20 to the ESP-01 Tx pin (GPIO 0) - which is set to Relay_i 1 in Tasmota firmware
// Connect NITRObot (Arduino Mega) pin 21 to the ESP-01 Rx pin (GPIO 3) - which is set to Button 2 in Tasmota firmware

// Create an instance of the NITROcompetition class named "competition"
NITROcompetition competition;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT); //Set the pin mode for the builtin LED (pin 13 on Arduino MEGA)
    // If you run this code on the NITRObot, you will not be able to see the builtin LED on the Arduino Mega board,
    // as the NITRObot shield is on top of that part of the Arduino Mega board.
    // Instead you can look a the the blue builtin LED on the ESP-01 module, which will be in synch with the Arduino Mega LED.

    // Initialize the competition class instance:
    competition.begin();
}

void loop()
{
    // You can use this line:
    // if (competition.get_start_signal())
    // which a shorthand and is equal to:
    // if (competition.get_start_signal() == true) which is more readable for begginers
    if (competition.getStartSignal() == true)
    {
        digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
        delay(3600); // wait for 3.6 seconds
        competition.sendFinishSignal();
        digitalWrite(LED_BUILTIN, LOW); // turn the LED off
    }
}