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
    * (this all could be fixed by adjusting the servo arms alignment.. im being lazy though)...
- Get the timers to work.
    * Servos are moving too fast. (or too slow or even not at all...)
- Get auto mode to work...

#### Plans:
- Add dual core usage for the ESP32's two cores.
- Incorporate the Blynk library to use remote control via wifi.
- Add bluetooth/ble
- Add more buttons or switches to change to different running modes.
- Make a second one for my other cat!
- uh...

#### Parts list:
- ESP32 HUZZAH32 Feather - https://www.adafruit.com/product/3405
    * Chosen for wifi/bluetooth connectivity and it's dual core support.
    * Other boards can be used if necesary. (Untested, code writen for esp32)
- 1x Laser diode - https://www.adafruit.com/product/1054
    * Connected to pin 12 on ESP32 Feather Huzzah32
- 1x Push Button - https://www.adafruit.com/product/367
    * Connected to pin 21.
    * any basic momentary push button switch. 
    * (You can edit the code to work with an spst slide switch too...)
- 1x SPST Switch - https://www.adafruit.com/product/805
    * current version uses a switch instead of a button. less hassle, no debounce to deal with.
- 1x Joystick - https://www.adafruit.com/product/512
    * X stick connected to pin 14
    * Y stick connected to pin 32
    * Joystick button switch connected to pin 15
    * Any joy stick with a center button press
- 2x Servos and servo arm kit (Mini Pan-Tilt Kit) - https://www.adafruit.com/product/1967
    * Bottom servo (Horizontal movement) connected to pin 33
    * Top servo (Vertical movement) connected to pin 27
    * You could use your own 2 servo set up as well.
- Bread board.
    * Use a longer breadboard to mount the mini pan tilt kit to the breadboard with header pins or any other method.
- Wires...
    * I prefer wires cut to the proper length to avoid the servos catching them and pulling them out of place. (It also looks better)

Total cost for parts is about $55-$65 or so depending on what you already have or need.
