#ifndef THECATTOY
#define THECATTOY

#include <Arduino.h>

#include "myLaser.h"
#include "myServo.h"
#include "myButton.h"
#include "mySwitch.h"
#include "myDisplay.h"

namespace TheCatToy {
    String catToyVersionNumber = "2.2"
    // define pins
    int SWITCH          =   21;     // input (Start/Stop)
    int BUTTON_A        =   15;     // input
    int BUTTON_B        =   32;     // input
    int BUTTON_C        =   14;     // input
    int SERVO1          =   33;     // output - bottom servo
    int SERVO2          =   27;     // output - upper servo
    int LASER           =   12;     // output
    int led13           =   13;     // output

    // define the parts of the cat toy.
    MyDisplay   display;
    MyButton    buttonA     (BUTTON_A);
    MyButton    buttonB     (BUTTON_B);
    MyButton    buttonC     (BUTTON_C);
    // MyButton    switch1(SWITCH);  // using this if buttons are used ...
    MySwitch    switch1(SWITCH);  // use this if switch is better.
    MyServo     servoX(SERVO1,    40,    130);
    MyServo     servoY(SERVO2,    20,    55);
    MyLaser     laser(LASER);

    bool debug = false;
    bool napStats = true;

    class CatLaser {
        private:
            String title = "The Cat Toy " + catToyVersionNumber;
            bool state = false;
            int mode = 0;
            bool running = false;
            bool pressedA = false;
            bool pressedB = false;
            bool pressedC = false;
            bool randomize = false;
            bool TakeNap = false;
            int PawsTimer = 0;  //Ha! Its a PawsTimer! Get it?
        
        public:
            CatLaser() {
                pinMode(led13, OUTPUT);
            }

            void init() {
                display.init();
                display.showOpener();
                if (debug) {
                    Serial.print("ServoX speed: ");
                    Serial.print(servoX.speed);
                    Serial.print(" ServoY speed: ");
                    Serial.println(servoY.speed);
                }
                delay(2000);
            }

            void run() {
                this->running = switch1.state();
                // this->checkNapTimer();
                if ((this->running) & (!this->TakeNap)) {
                    laser.setState(HIGH);
                    this->autoMove();
                    this->rollDice();
                }  
                else if ((this->running) & (this->TakeNap)) {
                    // this is what to do while a nap is taken.
                }
                else if (!this->running) {
                    laser.setState(LOW);
                    servoX.moveTo(servoX.midpoint);
                    servoY.moveTo(servoY.midpoint);
                }
                display.updateStats(this->running, this->mode);
                delay(10);
            }
            
            void startstop() {
                if ( !this->state & switch1.state() ) {
                    laser.changeState();
                    this->running = !this->running;
                    this->state = true;
                    delay(125);
                } 
                else if ( this->state & !switch1.state() ) {
                    this->state = false;
                }
            }

            void buttonStateA() {
                if ( (this->mode < 2) & (!this->pressedA) ) {
                    this->pressedA = true;
                    this->mode++;
                }
                else if ( (this->pressedA) & (!buttonA.state() ) ) {
                    this->pressedA = false;
                }
            }

            void buttonStateB() {
                if ( (this->mode > 0) & (!this->pressedB) ) {
                    this->pressedB = true;
                    this->mode--;
                }
                else if ( (this->pressedB) & (!buttonB.state() ) ) {
                    this->pressedB = false;
                }
            }

            void buttonStateC() {
                if (!this->pressedC) {
                    this->pressedC = true;
                    Serial.println("Figure out what to do w/ button C...");
                }
                else if ( (this->pressedC) & (!buttonC.state() ) ) {
                    this->pressedC = false;
                }
            }

            void rollDice() {
                int diceRoll = random(0, random(10,100));
                if (diceRoll == 0) { 
                    this->PawsTimer = random(250, 1500);
                    if (napStats) {
                        Serial.println(" ");
                        Serial.print(" (^ↀ.ↀ^ )~  Nap Time: ");
                        Serial.println(this->PawsTimer);
                        Serial.println("      |\\      _,,,---,,");
                        Serial.println("ZZZzz /,`.-'`'    -.  ;-;;,_");
                        Serial.println("     |,4-  ) )-,_. ,\\ (  `'-'");
                        Serial.println("    '---''(_/--'  `-'\\_)");
                    }
                    delay(PawsTimer);
                }
            }

            void checkNapTimer() {
                int now = millis();
                if (this->PawsTimer >= now) {
                    Serial.println("Taking Nap.");
                    this->TakeNap = true;
                }
                else if (this->PawsTimer < now) {
                    this->rollDice();
                    this->TakeNap = false;
                }
            }

            void checkMoveTimers(MyServo *servo) {
                if (servo->moveTimer <= millis()) {
                    servo->makeMove();
                }
            }

            void autoMove() {
                // auto move stuff...
                this->checkMoveTimers(&servoX);  // move servoX...
                this->checkMoveTimers(&servoY);  // move servoY...

                if (this->randomize) {
                    servoX.randomizeSpeed();
                    servoY.randomizeSpeed();
                }

                if (debug) {
                    Serial.print("Servo X angle: ");
                    Serial.print(servoX.angle);
                    Serial.print(" - speed: ");
                    Serial.print(servoX.speed);
                    Serial.print(" | Servo Y angle: ");
                    Serial.print(servoY.angle);
                    Serial.print(" - speed: ");
                    Serial.print(servoY.speed);
                    Serial.println(".");
                }
            }

    };  // end of class CatLaser

}  // end of namespace TheCatToy

#endif
