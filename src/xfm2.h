/* -*- C++ -*- */
#pragma once

//XFM2 parameter setting - From Rene's code

// Code for setting the unit which is active
void change_unit();
// Code for setting the parameter on the XFM2
void set_parameter( int param, int value );
// Code for getting a selected parameter on the XFM2
int get_parameter( int param);
// Code for getting all parameters on the XFM2
void get_all_parameter();

void save_program();
void set_program( int program);
