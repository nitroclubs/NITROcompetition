#include <Arduino.h>

// NITROcompetition is a NITRObot library, used to communicate with the competition server.
// via an ESP-01 module (flashed and configured with Tasmota firmware) connected to the Arduino Mega on pins 20 and 21.
// NITRObot gets the start signal and sends finish signal to the server (over MQTT protocol) via the ESP-01 WiFi module.
// Download and install the library from https://github.com/nitroclubs
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
    // Initialize the competition class instance:
    competition.begin();
    /*
    Your setup code goes here
    */
}

void loop()
{
    // You can use this line:
    // if (competition.get_start_signal())
    // which a shorthand and is equal to:
    // if (competition.get_start_signal() == true) which is more readable for begginers
    if (competition.getStartSignal() == true)
    {
        /*
         Your robot code goes here...
         It will be executed when the NITROcompetition librarry gets the start signal from the server
        */


        // When your code detects the finish line,
        // execute this function:
        competition.sendFinishSignal();
        // This will send the finish signal to the server and send competition.getStartSignal() to false, 
        // so your code inside the if statement will stop executing  
    }
}