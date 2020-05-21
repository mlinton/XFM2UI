/* -*- C++ -*- */
#pragma once

//AM4 menu IO definitions
//https://github.com/neu-rah/ArduinoMenu

#include <menuIO/u8g2Out.h>
// #include <menuIO/encoderIn.h>
#ifndef ARDUINO_LOLIN32
  #include <TimerOne.h>
#endif
#include "ClickEncoder.h"
#include <menuIO/clickEncoderIn.h>
#include <menuIO/keyIn.h>
#include <menuIO/chainStream.h>
#include <menuIO/serialOut.h>
#include <menuIO/serialIn.h>
#include "menu_struct.h"

using namespace Menu;
//#define fontName u8g2_font_7x13_mf
#define fontName u8g2_font_6x10_mf
#define MAX_DEPTH 4
constexpr int menu_fps=120;//limit menu draw FPS

// Menu input encoder
#ifdef ARDUINO_LOLIN32
  void IRAM_ATTR onTimer();
  extern hw_timer_t *timer;
#else
  void timerIsr();
#endif
extern ClickEncoder clickEncoder;

extern Menu::navRoot nav;

result alert(menuOut& o,idleEvent e);
result doAlert(eventMask e, prompt &item);
result idle(menuOut& o,idleEvent e);
