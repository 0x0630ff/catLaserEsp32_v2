// CAT LASER TOY V2.
// BETTER AND COOLER.

#include <Arduino.h>
#include "TheCatToy.h"

using namespace TheCatToy;
CatLaser catlaser;

void startStop() {
    // Start Stop Interrupt!!!
    catlaser.startstop();
}

void manualMode() {
    // Manual Mode Interrupt!!!
    catlaser.setManualMode();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Starting CAT LASER TOY V2!!!!");
    attachInterrupt(joyStickBTN, manualMode, CHANGE);
    // uncomment below to use BUTTON instead of SWITCH
    // attachInterrupt(BUTTON, startStop, CHANGE);  
}

void loop() {
    catlaser.run();
}
