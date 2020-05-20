/* -*- C++ -*- */
#pragma once

//AM4 menu IO definitions
//https://github.com/neu-rah/ArduinoMenu

#include <menuIO/u8g2Out.h>
// #include <menuIO/encoderIn.h>
#include <TimerOne.h>
#include "ClickEncoder.h"
#include <menuIO/clickEncoderIn.h>
#include <menuIO/keyIn.h>
#include <menuIO/chainStream.h>
#include <menuIO/serialOut.h>
#include <menuIO/serialIn.h>
#include "menu_struct.h"

using namespace Menu;

constexpr int menu_fps=20;//limit menu draw FPS

// rotary encoder pins
#define encA    3
#define encB    4
#define encBtn  5

//#define fontName u8g2_font_7x13_mf
#define fontName u8g2_font_6x10_mf
#define fontX 5
#define fontY 12
#define offsetX 1
#define offsetY 2
#define U8_Width 128
#define U8_Height 64
#define USE_HWI2C
//Maximum depth of the menu system
#define MAX_DEPTH 4
// Configure the SSD1306 with U8G2 / I2C

// define menu colors
const colorDef<uint8_t> colors[6] MEMMODE={
  {{0,0},{0,1,1}},//bgColor
  {{1,1},{1,0,0}},//fgColor
  {{1,1},{1,0,0}},//valColor
  {{1,1},{1,0,0}},//unitColor
  {{0,1},{0,0,1}},//cursorColor
  {{1,1},{1,0,0}},//titleColor
};

// Menu input encoder
ClickEncoder clickEncoder(encA,encB,encBtn,4);
ClickEncoderStream encStream(clickEncoder,1);
void timerIsr() {clickEncoder.service();}

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
