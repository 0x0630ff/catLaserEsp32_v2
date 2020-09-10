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
            float angle;
            float servoDirection = 1;
            float rate;
            int minimum;
            int maximum;
            int range;
            int midpoint;
            float rateFactor = 0.2;

            MyServo(int _servo, int _min = 0, int _max = 180, int _rate=1) {
                Serial.println(_servo);
                this->servoPin = _servo;
                this->minimum = _min;
                this->maximum = _max;
                this->range = _max - _min;
                this->rate = _rate * this->rateFactor;
                this->midpoint = this->minimum + (this->range / 2);
                this->angle = this->midpoint;
                this->init();
            }

            void init() {
                this->servo.attach(this->servoPin, this->servoMin, this->servoMax);
                this->servo.write(this->midpoint);
            }
            
            void move() {
                if (this->angle <= this->maximum && this->angle >= this->minimum){
                    this->checkDirection();
                    this->servo.write(this->angle);
                }
                else {
                    this->servoDirection *= -1;
                }
            }

            void moveTo(int _angle) {
                if (_angle <= this->maximum && _angle >= this->minimum){
                    this->checkDirection();
                    this->servo.write(_angle);
                }
                else {
                    this->servoDirection *= -1;
                }
            }

            void checkDirection() {
                if (this->angle == this->maximum || this->angle == this->minimum) {
                    this->servoDirection *= -1;
                }
                this->angle += this->servoDirection;
            }

            void writeMicroseconds(int ms) {
                this->servo.writeMicroseconds(ms);
            }

            void setServo(float _angle) {
                this->angle = _angle;
                this->checkDirection();
                this->move();
            }

    };  // end of class myServos
    
}  // end of namespace myServoSettup

#endif