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
            int servoAngle = 90;
            int servoDirection = 1;
            int minimum;
            int maximum;
            int range;
            int midpoint;

            MyServo(int servo, int _min = 0, int _max = 180) {
                Serial.println(servo);
                this->servoPin = servo;
                this->minimum = _min;
                this->maximum = _max;
                this->range = _max - _min;
                this->midpoint = (this->range / 2) + _min;
                this->init();
            }

            void init() {
                servo.attach(this->servoPin, servoMax, servoMin);
                servo.write(this->midpoint);
            }

            void move(int angle) {
                checkDirection();
                servo.write(angle);
            }

            void checkDirection() {
                if (servoAngle == this->maximum || servoAngle == this->minimum) {
                    servoDirection *= -1;
                }
                servoAngle += servoDirection;
            }

            void writeMicroseconds(int ms) {
                servo.writeMicroseconds(ms);
            }

    };  // end of class myServos
    
}  // end of namespace myServoSettup

#endif