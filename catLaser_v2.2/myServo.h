// To controll all my servos.
#ifndef MYSERVOS
#define MYSERVOS

#include <Arduino.h>
#include <ESP32Servo.h>

namespace TheCatToy {

    class MyServo {
        private:
            int servoMin = 500;
            int servoMax = 2500;
            int servoPin;
            
        public:
            Servo servo;

            int speeds[12] = {
                5,  10,
                15, 20,
                25, 30,
                35, 40,
                45, 50,
                55, 60
            };

            float angle;
            float servoDirection = 1;
            int minAngle;
            int maxAngle;
            int range;
            int midpoint;
            int maxSpeed= speeds[0];        // lower number means less wait time
            int minSpeed = speeds[11];      // lower number means less wait time
            int moveTimer = 0;
            // float rateFactor = 1.0;
            float speed = this->speeds[random(0,12)];
            float rate = 1.0;

            MyServo(int _servo, int _min=0, int _max=180) {
                this->servoPin = _servo;
                this->minAngle = _min;
                this->maxAngle = _max;
                this->range = _max - _min;
                this->midpoint = this->minAngle + (this->range / 2);
                this->angle = this->midpoint;
                this->init();
            }

            void init() {
                this->servo.attach(this->servoPin, this->servoMin, this->servoMax);
                this->servo.write(this->midpoint);
            }
            
            void move() {
                if (this->angle < this->maxAngle && this->angle > this->minAngle){
                    this->checkDirection();
                    this->servo.write(this->angle);
                }
                else {
                    this->servoDirection *= -1;
                }
            }

            void moveTo(int _angle) {
                if (_angle <= this->maxAngle && _angle >= this->minAngle){
                    this->checkDirection();
                    this->servo.write(_angle);
                }
                else {
                    this->servoDirection *= -1;
                }
            }

            void makeMove() {
                this->checkDirection();
                this->increment();
                this->move();
                this->resetTimer();
            }

            void increment() {
                this->angle += (this->servoDirection * this->rate);
            }

            void checkDirection() {
                if (this->angle == this->maxAngle || this->angle == this->minAngle) {
                    this->servoDirection *= -1;
                }
                this->angle += this->servoDirection;
            }

            void resetTimer() {
                this->moveTimer = millis() + this->speed;
            }

            // void setServo(float _angle) {
            //     this->angle = _angle;
            //     this->checkDirection();
            //     this->move();
            // }

            void randomizeSpeed() {
                this->speed = ( random( this->maxSpeed,this->minSpeed) * ( this->rate) );
            }

    };  // end of class myServos
    
}  // end of namespace myServoSettup

#endif