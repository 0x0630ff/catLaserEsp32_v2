// CAT LASER TOY V2.
// BETTER AND COOLER.
#include <Arduino.h>

#include "TheCatToy.h"
using namespace TheCatToy;
CatLaser catlaser;

void setup() {
    Serial.begin(115200);
    Serial.println("Starting CAT LASER TOY V2!!!!");
}

void loop() {
    catlaser.run();
}
