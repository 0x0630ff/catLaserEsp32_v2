#ifndef MYJOYSTICK
#define MYJOYSTICK

#include <Arduino.h>

namespace myJoystickSetup {
    class MyJoystick {
        private:
            int pinX;
            int pinY;
            int pinBTN;

        public:

            struct Values {
                int xVal;
                int yVal;
                int btnState;
            } state;

            // Values ;

            MyJoystick(int x, int y, int btn) {
                this->pinX      = x;
                this->pinY      = y;
                this->pinBTN    = btn;
                pinMode(this->pinX, INPUT);
                pinMode(this->pinY, INPUT);
                pinMode(this->pinBTN, INPUT_PULLUP);
            }

            Values read() {
                state.xVal      = map(analogRead(this->pinX), 0, 4095, 1000, 0);
                state.yVal      = map(analogRead(this->pinY), 0, 4095, 1000, 0);
                state.btnState  = !digitalRead(this->pinBTN);
                return state;
            }

            int x() {
                Values val = read();
                return val.xVal;
            }

            int y() {
                Values val = read();
                return val.yVal;
            }

            int getBtnState() {
                return !digitalRead(this->pinBTN);
            }

    };  // end of class MyJoystick

}  // end of namespace myJoystickSetup

#endif