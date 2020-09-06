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

            MyServo(int servo) {
                Serial.println(servo);
                this->servoPin = servo;
                this->init();
            }

            void init() {
                servo.attach(this->servoPin, servoMin, servoMax);
                servo.write(servoAngle);
            }

            void move(int angle) {
                checkDirection();
                servo.write(angle);
            }

            void checkDirection() {
                if (servoAngle == 180 || servoAngle == 0) {
                    servoDirection *= -1;
                }
                servoAngle += servoDirection;
            }

    };  // end of class myServos
    
}  // end of namespace myServoSettup

#endif