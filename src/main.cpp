// XFM2UI v0.1
// Based on Teensy 4.0 with an Adafruit SSD1306 and a Clickable rotary encoder
// Github:  https://github.com/marklinton/XFM2UI

#include <Arduino.h>
#include <Wire.h>
#include "base.h"
#include "menu_def.h"
#include "tinyTimeUtils.h" //from https://github.com/neu-rah/tinyTimeUtils/blob/master/src/tinyTimeUtils.h

using namespace TinyTimeUtils;//for limiting FPS without blocking

// two serial port setup
// serial - the primary serial port for the output of the menu to the serial console of the arduino
// serial1 - the output for the UART comms with the XFM2 @ 500kbs
int active_unit=2;

void setup() {
  Serial.begin(500000);
  Serial1.begin(500000);
  while(!Serial);
  Serial.println("XFM2UI V0.1");Serial.flush();
  Wire.begin();
  u8g2.begin();
  u8g2.setFont(fontName);
  // Pushbutton on pin 14 for changing unit
  pinMode(unitPin,INPUT_PULLUP);

  // Get the parameter values from the XFM2
  // get bith unit paramns and store them, start with unit 1 then
  //keep th eorder so that params[..] will be the same as unit1_params[..]
  Serial1.write('2');//select unit 2
  get_all_parameter();
  for(int i=0;i<n_params;i++) unit2_params[i]=params[i];
  Serial1.write('1');//select unit 1
  get_all_parameter();
  for(int i=0;i<n_params;i++) unit1_params[i]=params[i];

  nav.idleTask=idle; //point a function to be used when menu is suspended
  Serial.println("Setup complete.");Serial.flush();
  
  //Timer for the ClickEncoder
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
  Serial.print(LEGATO);
  Serial.print(OUTPUT_LEVEL);
  Serial.print(PORTA_MODE);
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
