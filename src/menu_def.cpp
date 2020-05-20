#include "menu_def.h"
#include "base.h"

#ifdef ARDUINO_LOLIN32
  // ESP32 timer
  void IRAM_ATTR onTimer() {clickEncoder.service();}
  hw_timer_t *timer = NULL;
  portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
#else
  //teensy timer
  void timerIsr() {clickEncoder.service();}
#endif

// rotary encoder pins
#define encA    3
#define encB    4
#define encBtn  5

#define fontX 5
#define fontY 12
#define offsetX 1
#define offsetY 2
#define U8_Width 128
#define U8_Height 64
#define USE_HWI2C

// define menu colors
const colorDef<uint8_t> colors[6] MEMMODE={
  {{0,0},{0,1,1}},//bgColor
  {{1,1},{1,0,0}},//fgColor
  {{1,1},{1,0,0}},//valColor
  {{1,1},{1,0,0}},//unitColor
  {{0,1},{0,0,1}},//cursorColor
  {{1,1},{1,0,0}},//titleColor
};

ClickEncoder clickEncoder(encA,encB,encBtn,4);
ClickEncoderStream encStream(clickEncoder,1);

serialIn serial(Serial);

// MENU_INPUTS(in,&serial);
MENU_INPUTS(in,&encStream,&serial);

MENU_OUTPUTS(out,MAX_DEPTH
  ,U8G2_OUT(u8g2,colors,fontX,fontY,offsetX,offsetY,{0,0,U8_Width/fontX,U8_Height/fontY})
  ,SERIAL_OUT(Serial)
);

// Base navigation object
NAVROOT(nav,mainMenu,MAX_DEPTH,in,out);

result alert(menuOut& o,idleEvent e) {
  if (e==idling) {
    o.setCursor(0,0);
    o.print("alert test");
    o.setCursor(0,1);
    o.print("press [select]");
    o.setCursor(0,2);
    o.print("to continue...");
  }
  return proceed;
}

result doAlert(eventMask e, prompt &item) {
  nav.idleOn(alert);
  return proceed;
}

result idle(menuOut& o,idleEvent e) {
  o.clear();
  switch(e) {
    case idleStart:o.println("suspending menu!");break;
    case idling:o.println("suspended...");break;
    case idleEnd:o.println("resuming menu.");break;
  }
  return proceed;
}
