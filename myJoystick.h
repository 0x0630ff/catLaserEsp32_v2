#ifndef MYJOYSTICK
#define MYJOYSTICK

#include <Arduino.h>

// pinMode(joyStickBTN, INPUT);
// pinMode(joyStickX, INPUT);
// pinMode(joyStickY, INPUT);

namespace myJoystickSetup {

    class MyJoystick {
        private:
            int pinX;
            int pinY;
            int pinBTN;

            struct Values {
                int xVal;
                int yVal;
                int btnVal;
            };

        public:
            MyJoystick(int x, int y, int btn) {
                this->pinX = x;
                this->pinY = y;
                this->pinBTN = btn;
            }

            Values read() {
                int xVal = analogRead(pinX);
                int yVal = analogRead(pinY);
                int btnState = digitalRead(pinBTN);
                return {xVal, yVal, btnState};
            }

    };  // end of class MyJoystick

}  // end of namespace myJoystickSetup

#endif