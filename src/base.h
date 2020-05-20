/* -*- C++ -*- */
#pragma once

//XFM2 parameter setting - From Rene's code
#include "xfm2.h"

//graphics lib
#include <U8g2lib.h>

//init base hardware (SSD1306 OLED display in this case)
#ifdef ARDUINO_LOLIN32
  #define SDA 5
  #define SCL 4
  extern U8G2_SSD1306_128X64_VCOMH0_F_HW_I2C u8g2;//allow contrast change
#else
  extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
#endif

constexpr int unitPin=14;//change unit pin
