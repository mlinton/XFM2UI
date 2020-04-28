// XFM Menusystem
// Based on Teensy 4.0 with an Adafruit SSD1306 and a Clickable rotary encoder
// Github:
// TODO:

#include <Arduino.h>
#include <menu.h>
#include <menuIO/u8g2Out.h>
#include <menuIO/encoderIn.h>
#include <menuIO/keyIn.h>
#include <menuIO/chainStream.h>
#include <menuIO/serialOut.h>
#include <menuIO/serialIn.h>
#include <Wire.h>

// TODO: Figure out how to best #include "XFM2_params.h"

using namespace Menu;

#define LEDPIN LED_BUILTIN

  // rotary encoder pins
  #define encA    3
  #define encB    4
  #define encBtn  5

  // TODO: define UART pins on the XFM2

  // SSD1306 SCL and SDA
  #define sdl     18
  #define sda     19

  //#define fontName u8g2_font_7x13_mf
  #define fontName u8g2_font_6x10_mf
  #define fontX 5
  #define fontY 12
  #define offsetX 1
  #define offsetY 2
  #define U8_Width 128
  #define U8_Height 64
  #define USE_HWI2C
  U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, sdl, sda);


// define menu colors
const colorDef<uint8_t> colors[6] MEMMODE={
  {{0,0},{0,1,1}},//bgColor
  {{1,1},{1,0,0}},//fgColor
  {{1,1},{1,0,0}},//valColor
  {{1,1},{1,0,0}},//unitColor
  {{0,1},{0,0,1}},//cursorColor
  {{1,1},{1,0,0}},//titleColor
};


MENU(GSsubMenu,"Global Settings",doNothing,noEvent,noStyle
  ,OP("Output Level",doNothing,noEvent)
  ,OP("Layer Mode",doNothing,noEvent)
  ,OP("Midi",doNothing,noEvent)
  ,OP("Performance Controls",doNothing,noEvent)
  ,OP("Tunings",doNothing,noEvent)
  ,EXIT("<Back")
);
MENU(PSsubMenu,"Program Settings",doNothing,noEvent,noStyle
  ,OP("Voice Select",doNothing,noEvent)
  ,OP("Program Load/Save/Select",doNothing,noEvent)
  ,OP("Bend Up/Down",doNothing,noEvent)
  ,OP("Transpose",doNothing,noEvent)
  ,OP("Volume",doNothing,noEvent)
  ,OP("Pan",doNothing,noEvent)
  ,OP("Velocity Offset",doNothing,noEvent)
  ,OP("Legato Mode",doNothing,noEvent)
  ,OP("Portamento Mode",doNothing,noEvent)
  ,OP("Portamento Time",doNothing,noEvent)
  ,EXIT("<Back")
);
MENU(OPsubMenu,"Operators",doNothing,noEvent,noStyle
  ,OP("Oscillators",doNothing,noEvent)
  ,OP("Interconnection",doNothing,noEvent)
  ,OP("Syncronization",doNothing,noEvent)
  ,OP("Pitch Control",doNothing,noEvent)
  ,OP("Operator Level",doNothing,noEvent)
  ,OP("Keyboard Tracking",doNothing,noEvent)
  ,OP("Amplitude EG",doNothing,noEvent)
  ,OP("Sensitivity",doNothing,noEvent)
  ,EXIT("<Back")
);
MENU(VCsubMenu,"Voices",doNothing,noEvent,noStyle
  ,OP("Pitch EG",doNothing,noEvent)
  ,OP("Low Freq Oscillator",doNothing,noEvent)
  ,EXIT("<Back")
);
MENU(MDsubMenu,"Modulators",doNothing,noEvent,noStyle
  ,OP("Pitch",doNothing,noEvent)
  ,OP("Pitch LFO",doNothing,noEvent)
  ,OP("Amplitude LFO",doNothing,noEvent)
  ,OP("Envelope Bias",doNothing,noEvent)
  ,OP("Arpeggiator",doNothing,noEvent)
  ,OP("Tunings",doNothing,noEvent)
  ,EXIT("<Back")
);
MENU(EFsubMenu,"Effects",doNothing,noEvent,noStyle
//,SUBMENU(BitCrusher)
//  ,FIELD(PRM_BITCRUSHER_DEPTH,"Bitcrusher Depth","",1,24,1,1,doNothing,noEvent,noStyle)
  ,OP("Decimator",doNothing,noEvent)
  ,OP("Filter",doNothing,noEvent)
  ,OP("Chorus - Flanger",doNothing,noEvent)
  ,OP("Phaser",doNothing,noEvent)
  ,OP("Amplitude Modulation",doNothing,noEvent)
  ,OP("Delay",doNothing,noEvent)
  ,OP("Effects Routing",doNothing,noEvent)
  ,OP("Global Reverb",doNothing,noEvent)
  ,EXIT("<Back")
);
//MENU(BitCrusher,"Bitcrusher",doNothing,noEvent,noStyle
//  ,FIELD(Param380,"Bit Depth Reduction","#",1,24,1,doNothing,noEvent,noStyle)
//  ,EXIT("<Back")
//);

uint16_t hrs=0;
uint16_t mins=0;

//define a pad style menu (single line menu)
//here with a set of fields to enter a date in YYYY/MM/DD format
altMENU(menu,timeMenu,"Time",doNothing,noEvent,noStyle,(systemStyles)(_asPad|Menu::_menuData|Menu::_canNav|_parentDraw)
  ,FIELD(hrs,"",":",0,11,1,0,doNothing,noEvent,noStyle)
  ,FIELD(mins,"","",0,59,10,1,doNothing,noEvent,wrapStyle)
);

char* constMEM hexDigit MEMMODE="0123456789ABCDEF";
char* constMEM hexNr[] MEMMODE={"0","x",hexDigit,hexDigit};
char buf1[]="0x11";

MENU(mainMenu,"XFM2 UI V0.1",doNothing,noEvent,noStyle
  ,SUBMENU(GSsubMenu)
  ,SUBMENU(PSsubMenu)
  ,SUBMENU(OPsubMenu)
  ,SUBMENU(VCsubMenu)
  ,SUBMENU(MDsubMenu)
  ,SUBMENU(EFsubMenu)
  ,EXIT("<Exit")
);

#define MAX_DEPTH 3

encoderIn<encA,encB> encoder;//simple quad encoder driver
encoderInStream<encA,encB> encStream(encoder,4);// simple quad encoder fake Stream

//a keyboard with only one key as the encoder button
keyMap encBtn_map[]={{-encBtn,defaultNavCodes[enterCmd].ch}};//negative pin numbers use internal pull-up, this is on when low
keyIn<1> encButton(encBtn_map);//1 is the number of keys

menuIn* inputsList[]={&encButton};
// chainStream<2> in(inputsList);//1 is the number of inputs

serialIn serial(Serial);
// MENU_INPUTS(in,&serial);
MENU_INPUTS(in,&encStream,&encButton,&serial);

MENU_OUTPUTS(out,MAX_DEPTH
  ,U8G2_OUT(u8g2,colors,fontX,fontY,offsetX,offsetY,{0,0,U8_Width/fontX,U8_Height/fontY})
  ,SERIAL_OUT(Serial)
);

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

//when menu is suspended
result idle(menuOut& o,idleEvent e) {
  o.clear();
  switch(e) {
    case idleStart:o.println("suspending menu!");break;
    case idling:o.println("suspended...");break;
    case idleEnd:o.println("resuming menu.");break;
  }
  return proceed;
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("XFM2 UI Test");Serial.flush();
  encButton.begin();
  encoder.begin();
  Wire.begin();
  u8g2.begin();
  u8g2.setFont(fontName);
  // u8g2.setBitmapMode(0);

  // disable second option
  // mainMenu[1].enabled=disabledStatus;
  nav.idleTask=idle;//point a function to be used when menu is suspended
  Serial.println("setup done.");Serial.flush();
}

void loop() {
  nav.doInput();
  // digitalWrite(LEDPIN, ledCtrl);
  if (nav.changed(0)) {//only draw if menu changed for gfx device
    //change checking leaves more time for other tasks
    u8g2.firstPage();
    do nav.doOutput(); while(u8g2.nextPage());
  }
  delay(10);//simulate other tasks delay
}