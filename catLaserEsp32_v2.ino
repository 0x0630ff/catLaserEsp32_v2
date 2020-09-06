// CAT LASER TOY V2.
// BETTER AND COOLER.
#include <Arduino.h>

#include "TheCatToy.h"

using namespace TheCatToy;
CatLaser catlaser;

void startStop() {
    // Serial.println("Start Stop Interrupt!!!");
    catlaser.startstop();
}

void manualMode() {
    // Serial.println("Manual Mode Interrupt!!!");
    catlaser.setManualMode();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Starting CAT LASER TOY V2!!!!");
    attachInterrupt(21, startStop, CHANGE);
    attachInterrupt(15, manualMode, CHANGE);
}

void loop() {
    catlaser.run();
}
