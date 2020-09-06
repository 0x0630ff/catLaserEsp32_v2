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
#define LASER           13     // output - also D13 LED.

MyButton button1(BUTTON);
MyJoystick joystick(joyStickX, joyStickY, joyStickBTN);
MyServo servo1(SERVO1);
MyServo servo2(SERVO2);
MyLaser laser(LASER);

// attachInterrupt( digitalPinToInterrupt(button1.buttonPin), laser.changeState, FALLING );

namespace TheCatToy {

    class CatLaser {
        private:
            String title = "The Cat Toy";
        
        public:
            bool running = false;

            void startstop() {
                running = !running;
                laser.changeState();
            }

            void run() {
                if (button1.state() & !running) {
                    startstop();
                } 
                else if (button1.state() & running) {
                    startstop();
                }

                if (running) {
                    Serial.println("RUNNING");
                    // replace this with other function to start servos etc.
                    servo1.move(servo1.servoAngle);  //  <---- this has to go!
                } 
                else {
                    // laser should be off
                }

                delay(5);
            }

    };

}

#endif