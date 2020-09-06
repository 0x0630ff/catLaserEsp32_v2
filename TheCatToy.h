#ifndef THECATTOY
#define THECATTOY

#include <Arduino.h>

#include "myLaser.h"
#include "myServo.h"
#include "myButton.h"
#include "myJoystick.h"

using namespace myServoSetup;
using namespace myButtonSetup;
using namespace myJoystickSetup;
using namespace myLaserSetup;

// define pins
#define BUTTON          21     // input
#define joyStickX       14     // input
#define joyStickY       32     // input
#define joyStickBTN     15     // input
#define SERVO1          33     // output - bottom servo
#define SERVO2          27     // output - upper servo
#define LASER           12     // output
#define led13           13     // output

MyButton    button1     (BUTTON);
MyServo     servo1      (SERVO1);
MyServo     servo2      (SERVO2);
MyJoystick  joystick    (joyStickX, joyStickY, joyStickBTN);
MyLaser     laser       (LASER);

namespace TheCatToy {

    class CatLaser {
        
        private:
            String title = "The Cat Toy";
            bool state = false;
            bool manualMode = false;
            bool mmState = false;
            bool ledState = false;
        
        public:
            bool running = false;

            CatLaser() {
                pinMode(led13, OUTPUT);
            }

            void run() {
                if (running) {
                    if (manualMode) {
                        int x = map(joystick.x(), 0, 180, 0, 1027);
                        int y = map(joystick.y(), 0, 180, 0, 1027);
                        servo1.move(x);
                        servo2.move(y);
                    }
                    else {
                        autoMove(random(5,25));
                    }
                }
            }

            void startstop() {
                if ( !state & button1.state() ) {
                    laser.changeState();
                    running = !running;
                    state = true;
                    delay(75);
                } 
                else if ( state & !button1.state() ) {
                    state = false;
                }
            }

            void setManualMode() {
                if ( ( !mmState ) & joystick.getBtnState() ) {
                    mmState = true;
                    manualMode = !manualMode;
                    ledState = !ledState;
                    digitalWrite(led13, ledState);
                    delay(75);
                }
                else if ( mmState & ( !joystick.getBtnState() ) ) {
                    mmState = false;
                }
            }

            void autoMove(int rate) {
                // auto move stuff...
            }

    };  // end of class CatLaser

}  // end of namespace TheCatToy

#endif