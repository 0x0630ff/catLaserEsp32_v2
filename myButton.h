#ifndef MYBUTTONS
#define MYBUTTONS

#include <Arduino.h>

namespace TheCatToy {

    class MyButton {
        private:
            int buttonPin;
            bool pressed;

        public:
            MyButton(int _button) {
                this->buttonPin = _button;
                pinMode(this->buttonPin, INPUT_PULLUP);
            }

            // read and return button state bool
            bool state() {
                this->pressed = !digitalRead(this->buttonPin);
                return this->pressed;
            }

    };  // end of class MyButton
    
}  // end of namespace myButtonSetup

#endif