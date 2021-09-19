#include <Arduino.h>
#include "NITROcompetition.h"

// PREREQUISITS:
// ESP-01 module flashed with Tasmota firmware and configured following the instructions on:
// https://nitroclubs.eu/
// CONNECTIONS:
// Connect NITRObot (Arduino Mega) pin 20 to the ESP-01 Tx pin (GPIO 0) - which is set to Relay_i 1 in Tasmota firmware
// Connect NITRObot (Arduino Mega) pin 21 to the ESP-01 Rx pin (GPIO 3) - which is set to Button 2 in Tasmota firmware


NITROcompetition::NITROcompetition()
{
    start_signal_received_ = false;
}

void NITROcompetition::begin()
{
    pinMode(esp_to_mega_pin_, INPUT_PULLUP);
    pinMode(mega_to_esp_pin_, OUTPUT);
    digitalWrite(mega_to_esp_pin_, HIGH);
    attachInterrupt((esp_to_mega_pin_), esp_to_mega_isr, FALLING);
    instance_ = this;
}

// ISR glue routine
void NITROcompetition::esp_to_mega_isr()
{
    instance_->handleInterrupt();
} // end of NITROcompetition::esp_to_mega_isr

// For use by ISR glue routine
NITROcompetition *NITROcompetition::instance_;

void NITROcompetition::handleInterrupt()
{
    start_signal_received_ = true;
} // end of NITROcompetition::handleInterrupt

bool NITROcompetition::getStartSignal()
{
    return start_signal_received_;
} // end of NITROcompetition::getStartSignal

void NITROcompetition::sendFinishSignal()
{
    start_signal_received_ = false;
    digitalWrite(mega_to_esp_pin_, LOW);
} // end of NITROcompetition::sendFinishSignal
