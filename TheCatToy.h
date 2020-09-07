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
MyServo     servoX      (SERVO1);
MyServo     servoY      (SERVO2, 45, 135);
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
            unsigned long prevTime = millis();
        
        public:
            bool running = false;

            CatLaser() {
                pinMode(led13, OUTPUT);
                servo.write(90);
            }

            void run() {
                if (running) {
                    if (manualMode) {
                        int x = map(joystick.x(), 0, 1027, servoX.minimum, servoX.maximum);
                        int y = map(joystick.y(), 0, 1027, servoY.minimum, servoY.maximum);

                        Serial.print("X: ");
                        Serial.print(x);
                        Serial.print(" | Y: ");
                        Serial.println(y);

                        servoX.move(x);
                        servoY.move(y);
                    }
                    else {
                        autoMove(random(5,25));
                    }
                }  
                else {
                    servoX.move(servoX.midpoint);
                    servoY.move(servoY.midpoint);
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
                // use sin wave to oscilate between servo min and max.

                // servoX.servoAngle = servoX.servoAngle * (millis() - prevTime);
                // servoX.move(servoX.servoAngle);

                // servoY.servoAngle = servoY.servoAngle * (millis() - prevTime);
                // servoY.move(servoY.servoAngle);

                Serial.println("STARTING TEST");

                for (int pos=1; pos<179; pos++) {
                    Serial.println(pos);
                    servoX.servo.write(pos);
                    delay(500);
                }

                delay(3500);


                // int radX = servoX.servoAngle * 0.0174532 + servoX.servoDirection;
                // servoX.move(radX);

                // int radY = servoY.servoAngle * 0.0174532 + servoY.servoDirection;
                // servoY.move(radY);



            }

    };  // end of class CatLaser

}  // end of namespace TheCatToy

#endif