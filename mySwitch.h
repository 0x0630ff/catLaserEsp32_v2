#ifndef MYSWITCH
#define MYSWITCH

#include <Arduino.h>

namespace TheCatToy {

    class MySwitch {
        private:
            int switchPin;
            bool on;

        public:
            MySwitch(int _switchPin) {
                this->switchPin = _switchPin;
                pinMode(this->switchPin, INPUT_PULLUP);
            }

            // read and return button state bool
            bool state() {
                this->on = digitalRead(this->switchPin);
                return this->on;
            }

    };  // end of class MyButton
    
}  // end of namespace myButtonSetup

#endif