// XFM2UI v0.1
// Based on Teensy 4.0 with an Adafruit SSD1306 and a Clickable rotary encoder
// Github:  https://github.com/marklinton/XFM2UI

#include <Arduino.h>
#include <Wire.h>
#include "base.h"
#include "menu_def.h"

// two serial port setup
// serial - the primary serial port for the output of the menu to the serial console of the arduino
// serial1 - the output for the UART comms with the XFM2 @ 500kbs
int active_unit=2;

void setup() {
  Serial.begin(500000);
  Serial1.begin(500000);
  while(!Serial);
  Serial.println("XFM2UI V0.1");Serial.flush();
  encButton.begin();
  encoder.begin();
  Wire.begin();
  u8g2.begin();
  u8g2.setFont(fontName);
  // Pushbutton on pin 14 for changing unit
  pinMode(14,INPUT_PULLUP);

  get_all_parameter();
  // Get the parameter values from the XFM2

  nav.idleTask=idle; //point a function to be used when menu is suspended
  Serial.println("Setup complete.");Serial.flush();
}

void loop() {

  nav.doInput();

  if (nav.changed(0)) {  //only draw if menu changed for gfx device
    //change checking leaves more time for other tasks
    u8g2.firstPage();
    do nav.doOutput(); while(u8g2.nextPage());
  }
  if (digitalRead(14) == LOW) {
    change_unit();
  }
}


