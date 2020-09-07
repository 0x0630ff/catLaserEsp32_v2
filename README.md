# The Cat Laser Toy - V2.
The latest attempt and making my cat(s) happy.

#

#### Project In Progress.
- Pardon while the kinks and bugs are slowly squashed.

#### Usage:
- The push button will turn on the laser and start the auto run mode. 
    * Auto mode still needs a lot of help... 
- To use the joystick, press down on the joystick and the D13 led will light up to show that manual mode is active. 
- Joy stick can then move the servo arm around. <-- This is still a bit off. 

#### To Do:
- Fix the servo angle values. 
    * 0 degrees on bottom servo should be pointing left
    * 180 pointing right
    * 90 straight ahead.
- Get the timers to work.
    * Servos are moving too fast. (or too slow or even not at all...)
- Get auto mode to work...

#### Plans:
- Add dual core usage for the ESP32's two cores.
- Incorporate the Blynk library to use remote control via wifi.
- Add bluetooth/ble
- uh...

#### Parts list:
- ESP32 HUZZAH32 Feather - https://www.adafruit.com/product/3405
- 1x Push Button - https://www.adafruit.com/product/367
    * any basic momentary push button switch. 
    * (You can edit the code to work with an spst slide switch too...)
- 1x Joystick - https://www.adafruit.com/product/512
    * Any joy stick with a center button press
- 1x Laser diode - https://www.adafruit.com/product/1054
- 2x Servos and servo arm kit (Mini Pan-Tilt Kit) - https://www.adafruit.com/product/1967
    * You could use your own 2 servo set up as well.
