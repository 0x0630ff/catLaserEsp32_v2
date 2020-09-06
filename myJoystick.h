#ifndef MYJOYSTICK
#define MYJOYSTICK

#include <Arduino.h>

namespace myJoystickSetup {

    struct Values {
        int xVal;
        int yVal;
        int btnState;
    };

    class MyJoystick {
        private:
            int pinX;
            int pinY;
            int pinBTN;

        public:
            Values state;

            MyJoystick(int x, int y, int btn) {
                this->pinX      = x;
                this->pinY      = y;
                this->pinBTN    = btn;
                pinMode(this->pinX, INPUT);
                pinMode(this->pinY, INPUT);
                pinMode(this->pinBTN, INPUT_PULLUP);
            }

            Values read() {
                state.xVal      = map(analogRead(this->pinX), 0, 1027, 0, 100);
                state.yVal      = map(analogRead(this->pinY), 0, 1027, 0, 100);
                state.btnState  = !digitalRead(this->pinBTN);
                return state;
            }

            int x() {
                read();
                return state.xVal;
            }

            int y() {
                read();
                return state.yVal;
            }

            int getBtnState() {
                return !digitalRead(this->pinBTN);
            }

    };  // end of class MyJoystick

}  // end of namespace myJoystickSetup

#endif