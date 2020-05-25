// XFM2UI v0.1
// Based on Teensy 4.0 with an Adafruit SSD1306 and a Clickable rotary encoder
// Github:  https://github.com/marklinton/XFM2UI

#include <Arduino.h>
#include <Wire.h>
#include "base.h"
#include "menu_def.h"
#include "tinyTimeUtils.h" //from https://github.com/neu-rah/tinyTimeUtils/blob/master/src/tinyTimeUtils.h
#include <ArduinoJson.h>
using namespace TinyTimeUtils;//for limiting FPS without blocking

// two serial port setup
// serial - the primary serial port for the output of the menu to the serial console of the arduino
// serial1 - the output for the UART comms with the XFM2 @ 500kbs
int active_unit=2;

void setup() {
  #ifdef ARDUINO_LOLIN32
    Serial.begin(115200);//just because i dont have 500000 on platformio monitor
    delay(2000);//so that i can see the boot messages
  #else
    Serial.begin(500000);
  #endif
  Serial1.begin(500000);
  while(!Serial);
  Serial.println("XFM2UI V0.1");Serial.flush();
  #ifdef ARDUINO_LOLIN32
    Wire.begin(SDA,SCL);
  #else
    Wire.begin();
  #endif
  u8g2.begin();
  u8g2.setFont(fontName);
  // // Pushbutton on pin 14 for changing unit
  pinMode(unitPin,INPUT_PULLUP);

  // // Get the parameter values from the XFM2
  // // get bith unit paramns and store them, start with unit 1 then
  // // keep the order so that params[..] will be the same as unit1_params[..]


  #ifndef ARDUINO_LOLIN32
    Serial1.write('2');//select unit 2
    get_all_parameter();
    for(int i=0;i<n_params;i++) unit2_params[i]=params[i];
    Serial1.write('1');//select unit 1
    get_all_parameter();
    for(int i=0;i<n_params;i++) unit1_params[i]=params[i];
  #endif

  nav.idleTask=idle; //point a function to be used when menu is suspended
  Serial.println("Setup complete.");Serial.flush();

  #ifdef ARDUINO_LOLIN32
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 1000, true);
    timerAlarmEnable(timer);
  #else
    //Timer for the ClickEncoder
    Timer1.initialize(1000);
    Timer1.attachInterrupt(timerIsr);
    // enable acceleration for encoder here?
  #endif
// setup for the json parser for presets
StaticJsonDocument<20000> jsonBuffer;

}



void loop() {
  static FPS<menu_fps> menuFps;//limit menu drawing fps (change as needed)

  if(menuFps) {//deal with all complicated stuff to ensure that we never exceeed fps
    nav.doInput();
    if (nav.changed(0)) {  //only draw if menu changed for gfx device
      //change checking leaves more time for other tasks
      u8g2.firstPage();
      do nav.doOutput(); while(u8g2.nextPage());
    }
  }
  if (digitalRead(unitPin) == LOW) {
    change_unit();
    //debounce... ensure we do not get multiple changes due to button contact bounce
    //remove the delay if adding hardware debounce
    delay(10);
  }
}
