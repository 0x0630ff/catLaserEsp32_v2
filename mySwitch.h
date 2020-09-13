#ifndef MYSWITCH
#define MYSWITCH

#include <Arduino.h>

namespace TheCatToy {

    class MySwitch {
        private:
            int switchPin;
            int ledPin;
            bool on;

        public:
            MySwitch(int _switchPin, int _ledPin = 4) {
                this->switchPin = _switchPin;
                this->ledPin = _ledPin;
                pinMode(this->switchPin, INPUT_PULLUP);
                pinMode(this->ledPin, OUTPUT);
            }

            // read and return button state bool
            bool state() {
                this->on = digitalRead(this->switchPin);
                digitalWrite(this->ledPin, !this->on);
                return this->on;
            }

    };  // end of class MyButton
    
}  // end of namespace myButtonSetup

#endif