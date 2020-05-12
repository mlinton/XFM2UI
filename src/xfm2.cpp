#include <Arduino.h>
#include "xfm2.h"

void set_unit( int unit ) {
    // Default to unit 1
    Serial1.write( unit == 2 ? '2' : '1' );
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
void get_parameter( int param, int value ) {
    Serial1.write( 'g' ); // 'g' = Get Parameter

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

// Code for getting all parameters on the XFM2
void get_all_parameter() {
    for (int i = 0; i < 455; i++) {
    // code for retrieving the set of paramters
    }
}

// Code for saving programs on the XFM2
void save_program() {
    // code here
   
}

// Code for loading programs on the XFM2
void load_program() {
    // code here
    // set current_program to 
}