#ifndef MYBUTTONS
#define MYBUTTONS

#include <Arduino.h>

namespace myButtonSetup {

    class MyButton {
        private:
            bool pressed;

        public:
            static int buttonPin;

            // Button Constructor.
            MyButton(int _button) {
                this->buttonPin = _button;
                pinMode(this->buttonPin, INPUT_PULLUP);
                // attachInterrupt(digitalPinToInterrupt(button)), changeStateInterrupt, CHANGE);
            }

            void changeStateInterrupt() {
                this->state();
            }
            
            // read and return button state bool
            bool state() {
                this->pressed = !digitalRead(this->buttonPin);
                return this->pressed;
            }

    };
    
}

#endif