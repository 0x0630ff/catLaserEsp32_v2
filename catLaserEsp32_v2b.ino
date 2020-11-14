// CAT LASER TOY V2b.
// BETTER AND COOLER.

#include <Arduino.h>
#include "TheCatToy.h"

using namespace TheCatToy;
CatLaser catlaser;


void startStop() {
    catlaser.startstop();
}

void pressedButtonStateA() {
    catlaser.buttonStateA();
}

void pressedButtonStateB() {
    catlaser.buttonStateB();
}

void pressedButtonStateC() {
    catlaser.buttonStateC();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Starting CAT LASER TOY V" + catToyVersionNumber + "!!!!");

    // attachInterrupt(digitalPinToInterrupt(SWITCH), startStop, CHANGE);
    attachInterrupt(digitalPinToInterrupt(BUTTON_A), pressedButtonStateA, CHANGE);
    attachInterrupt(digitalPinToInterrupt(BUTTON_B), pressedButtonStateB, CHANGE);
    attachInterrupt(digitalPinToInterrupt(BUTTON_C), pressedButtonStateC, CHANGE);

    catlaser.init();
}

void loop() {
    catlaser.run();
}
