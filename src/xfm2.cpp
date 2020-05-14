#include <Arduino.h>
#include "xfm2.h"
#include "XFM2_vars.h"

void change_unit() {
    // Default to unit 1
    if (active_unit == 1) {
        active_unit = 2;
    } else {
        active_unit = 1;
    }
    Serial1.write(active_unit);
    // Serial.print("Active Unit Changed:");
    // Serial.println(active_unit);
    delay(100);
    }

// Code for setting the parameter on the XFM2
void set_parameter( int param, int value ) {
    Serial1.write( 's' ); // 's' = Set Parameter

    if( param > 255 ) {
        // Parameters above 255 have a two-byte format: b1 = 255, b2 = x-256
        Serial1.write( 255 );
        Serial1.write( param - 256  );
        Serial1.write( value );
    }
    else {
        Serial1.write( param );
        Serial1.write( value );
    }
}

// Code for getting a selected parameter on the XFM2
int get_parameter( int param) {
    Serial1.write( 'g' ); // 'g' = Get Parameter
    if( param > 255 ) {
        // Parameters above 255 have a two-byte format: b1 = 255, b2 = x-256
        Serial1.write( 255 );
        Serial1.write( param - 256  );
    } else Serial1.write( param );
    while(!Serial1.available());//wait for it
    return Serial1.read();
}

// Code for getting all parameters on the XFM2
void get_all_parameter() {
  Serial1.write( '2' );
  for (int i = 0; i < n_params; i++)
     params[i]=get_parameter(i);
 }

// Code for saving programs on the XFM2
void save_program( int ) {
    // code here
    Serial1.write( 'w' ); // 'w' = write active program into eeprom
    Serial1.write( 2 ); // ACTIVE_PROGRAM
}

// Code for loading programs on the XFM2
void load_program() {
    // code here
    Serial1.write( 'r' ); // 'r' = loads a program from memory
    Serial1.write( 2 ); // ACTIVE_PROGRAM
    // we need to set all of the parameters to the loaded program ones
    for (int i = 0; i < n_params; i++) {
    // code for retrieving the set of paramters
    }
}
