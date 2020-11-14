#ifndef MYDISPLAY
#define MYDISPLAY

#include <Arduino.h>

// #include <SPI.h>
#include <Wire.h>
// #include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// String catAscii = "\n      |\\      _,,,---,,\nZZZzz /,`.-'`'    -.  ;-;;,_\n     |,4-  ) )-,_. ,\\ (  `'-'\n    '---''(_/--'  `-'\\_)";

namespace TheCatToy {

    class MyDisplay {
        public:
            int ScreenWidth = 128;
            int ScreenHeight = 32;
            Adafruit_SSD1306 oled = Adafruit_SSD1306(this->ScreenWidth, this->ScreenHeight, &Wire);

            void init() {
                oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
                oled.setTextSize(1);
                oled.setTextColor(SSD1306_WHITE);
            }

            void showOpener() {
                oled.clearDisplay();
                oled.setCursor(0,0);
                oled.println("  The CatToy v2b");
                oled.println(" ");
                oled.println("    =(^Q.Q^= )~");
                oled.println(" ");
                oled.display();
            }

            void updateStats(bool _runningState, int _mode) {
                String MODES[] = {"SLOW", "MEDIUM", "FAST"};

                String state = "Stopped";
                String mode = MODES[_mode];

                if (_runningState) {
                    state = "Running";
                }

                String output1 = String("> " + state);
                String output2 = String("Mode:" + mode);

                oled.clearDisplay();
                oled.setCursor(0,0);
                oled.println(output1);
                oled.setCursor(0,10);
                oled.println(output2);
                oled.display();
            }

    };  // end of class MyDisplay

}  // end of namespace TheCatToy

#endif