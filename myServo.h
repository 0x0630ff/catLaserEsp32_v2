// To controll all my servos.
#ifndef MYSERVOS
#define MYSERVOS

#include <Arduino.h>
#include <ESP32Servo.h>

namespace myServoSetup {

    class MyServo {
        private:
            int servoMin = 500;
            int servoMax = 2500;
            int servoPin;
            
        public:
            Servo servo;
            int angle = 90;
            int servoDirection = 1;
            int minimum;
            int maximum;
            int range;
            int midpoint;

            MyServo(int _servo, int _min = 0, int _max = 180) {
                Serial.println(_servo);
                this->servoPin = _servo;
                this->minimum = _min;
                this->maximum = _max;
                this->range = _max - _min;
                this->midpoint = (this->range / 2) + _min;
                this->init();
            }

            void init() {
                servo.attach(this->servoPin, this->servoMin, this->servoMax);
                servo.write(this->midpoint);
            }

            void move(int _angle) {
                checkDirection();
                servo.write(_angle);
            }

            void checkDirection() {
                if (this->angle == this->maximum || this->angle == this->minimum) {
                    this->servoDirection *= -1;
                }
                this->angle += this->servoDirection;
            }

            void writeMicroseconds(int ms) {
                servo.writeMicroseconds(ms);
            }

    };  // end of class myServos
    
}  // end of namespace myServoSettup

#endif