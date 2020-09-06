#ifndef MYLASER
#define MYLASER

#include <Arduino.h>

namespace myLaserSetup {

    class MyLaser {
        private:
            int laserPin;
            bool laserState;
        
        public:
            MyLaser(int pin) {
                this->laserPin = pin;
                pinMode(this->laserPin, OUTPUT);
                this->setState(LOW);
            }

            bool getState() {
                return this->laserState;
            }

            void changeState() {
                this->laserState = !this->laserState;
                this->setState(this->laserState);
            }

            void setState(bool state) {
                this->laserState = state;
                digitalWrite(this->laserPin, state);
            }

    };  // end of class MyLaser

}  // end of namespace myLaserSetup

#endif