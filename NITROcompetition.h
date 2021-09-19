#ifndef NITROcompetition_h
#define NITROcompetition_h
#include <Arduino.h>

// PREREQUISITS:
// ESP-01 module flashed witth Tasmota firmware and configured following the instructions on:
// https://nitroclubs.eu/
// CONNECTIONS:
// Connect NITRObot (Arduino Mega) pin 20 to the ESP-01 Tx pin (GPIO 0) - which is set to Relay_i 1 in Tasmota firmware
// Connect NITRObot (Arduino Mega) pin 21 to the ESP-01 Rx pin (GPIO 3) - which is set to Button 2 in Tasmota firmware

class NITROcompetition
{
protected:
private:
    static NITROcompetition * instance_; // poiter to the class instance
    int esp_to_mega_pin_ = 20; //Connected to ESP-01 Tx (GPIO 0) - Tasmota-Relay_i 1
    int mega_to_esp_pin_ = 21; //Connected to ESP-01 Rx (GPIO 3) - Tasmota-Button 2
    volatile int start_signal_received_;
    static void esp_to_mega_isr();
    void handleInterrupt ();
public:
    NITROcompetition();
    void begin ();
    bool getStartSignal();
    void sendFinishSignal();
};

#endif // end of #ifndef NITROcompetition_h