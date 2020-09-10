#ifndef THECATTOY
#define THECATTOY

#include <Arduino.h>

#include "myLaser.h"
#include "myServo.h"
#include "myButton.h"
#include "mySwitch.h"
#include "myJoystick.h"

// using namespace myServoSetup;
// using namespace myButtonSetup;
// using namespace mySwitchSetup;
// using namespace myJoystickSetup;
// using namespace myLaserSetup;

namespace TheCatToy {

    // define pins
    int SWITCH          =   21;
    int BUTTON          =   21;     // input
    int joyStickX       =   14;     // input
    int joyStickY       =   32;     // input
    int joyStickBTN     =   15;     // input
    int SERVO1          =   33;     // output - bottom servo
    int SERVO2          =   27;     // output - upper servo
    int LASER           =   12;     // output
    int led13           =   13;     // output

    // define the parts of the cat toy.
    // MyButton    button1     (BUTTON);
    MySwitch    switch1     (SWITCH);
    MyServo     servoX      (SERVO1,    70,    110,   random(1,4) / 40.0);
    MyServo     servoY      (SERVO2,    20,    45,    random(1,4) / 40.0);
    MyJoystick  joystick    (joyStickX, joyStickY, joyStickBTN);
    MyLaser     laser       (LASER);

    bool debug = true;

    class CatLaser {

        private:
            String title = "The Cat Toy";
            bool state = false;
            bool manualMode = false;
            bool manualModeState = false;
            bool ledState = false;
        
        public:
            bool running = false;

            CatLaser() {
                pinMode(led13, OUTPUT);
            }

            void run() {
                running = switch1.state();
                if (running) {
                    laser.setState(HIGH);
                    if (manualMode) {
                        int x = map(joystick.x(), 0, 4095, servoX.minimum, servoX.maximum);
                        int y = map(joystick.y(), 0, 4095, servoY.minimum, servoY.maximum);

                        if (debug) {
                            Serial.print("X: ");
                            Serial.print(joystick.x());
                            Serial.print(" | Y: ");
                            Serial.println(joystick.y());
                        }
                        
                        servoX.moveTo(x);
                        servoY.moveTo(y);

                        delay(10);
                    }
                    else {
                        // if (debug) {Serial.println("Auto Mode Running");}
                        this->autoMove();
                    }
                }  
                else if (!running) {
                    laser.setState(LOW);
                    // if (debug) {Serial.println("Not Running... Centered.");}
                    servoX.moveTo(servoX.midpoint);
                    servoY.moveTo(servoY.midpoint);
                }
            }

            void startstop() {
                if ( !this->state & switch1.state() ) {
                    laser.changeState();
                    this->running = !this->running;
                    this->state = true;
                    delay(75);
                } 
                else if ( this->state & !switch1.state() ) {
                    this->state = false;
                }
            }

            void setManualMode() {
                if ( ( !this->manualModeState ) & joystick.getBtnState() ) {
                    this->manualModeState = true;
                    this->manualMode = !this->manualMode;
                    this->ledState = !this->ledState;
                    digitalWrite(led13, this->ledState);
                    delay(75);
                }
                else if ( this->manualModeState & ( !joystick.getBtnState() ) ) {
                    this->manualModeState = false;
                }
            }

            void autoMove() {
                // auto move stuff...
                servoX.checkDirection();
                servoY.checkDirection();

                servoX.angle += (servoX.servoDirection * servoX.rate);
                servoY.angle += (servoY.servoDirection * servoY.rate);

                Serial.print("ServoX: ");
                Serial.print(servoX.angle);
                Serial.print(" - RateX: ");
                Serial.print(servoX.rate);
                Serial.print(" | ServoY: ");
                Serial.print(servoY.angle);
                Serial.print(" - RateY: ");
                Serial.print(servoY.rate);
                Serial.println(".");

                servoX.move();
                servoY.move();

                int diceRollPause = random(0,random(10,25));
                if (diceRollPause == 0){
                    delay(random(125, 2000));
                }

                delay(25);
            }

    };  // end of class CatLaser

}  // end of namespace TheCatToy

#endif