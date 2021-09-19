
NITROcompetition is a NITRObot library, used to communicate with the competition server for online/ offite international NITROclubs competitions.

NITRObot gets start signal and sends finish signal to the server (over MQTT protocol) via ESP-01 WiFi module (flashed and configured with Tasmota firmware). 

PREREQUISITS:

ESP-01 module flashed with Tasmota firmware and configured following the instructions on:
https://nitroclubs.eu/

 CONNECTIONS:

Connect NITRObot (Arduino Mega) pin 20 to the ESP-01 Tx pin (GPIO 0) - which is set to Relay_i 1 in Tasmota firmware

Connect NITRObot (Arduino Mega) pin 21 to the ESP-01 Rx pin (GPIO 3) - which is set to Button 2 in Tasmota firmware
