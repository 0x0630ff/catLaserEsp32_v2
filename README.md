# The Cat Laser Toy - V2.
The latest attempt and making my cat(s) happy.

### Parts list:
* ESP32 HUZZAH32 Feather - https://www.adafruit.com/product/3405
* 1x Push Button - https://www.adafruit.com/product/367
    * any basic momentary push button switch. 
    * (You can edit the code to work with an spst slide switch too...)
* 1x Joystick - https://www.adafruit.com/product/512
* 1x Laser diode - https://www.adafruit.com/product/1054
* 2x Servos and servo arm kit - https://www.adafruit.com/product/1967

#### Usage:
The push button will turn on the laser and start the auto run mode. <br>
- Auto mode still needs a lot of help... <br>
To use the joystick, press down on the joystick and the D13 led will light up to show that manual mode is active.<br>
Joy stick can then move the servo arm around. <-- This is still a bit off.<br>

#### Plans:
* Incorporate the Blynk library to use remote control via wifi.
* Add bluetooth/ble
* uh...