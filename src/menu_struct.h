/* -*- C++ -*- */
#pragma once

//AM4 menu structure definition
//https://github.com/neu-rah/ArduinoMenu

#include <menu.h>
#include "XFM2_vars.h"
#include "xfm2.h"

template<int param,int& value>
struct Param {
  static result set() {
    Serial.print("updating param ");
    Serial.print(param);
    Serial.print(" to ");
    Serial.println(value);
    ::set_parameter(param,value);
    return proceed;
  }
};

extern menuNode mainMenu;
//add other menus here if you need to refer to them outside menu_struct.cpp
