#include "xfm2.h"
#include "menu_funcs.h"

using namespace Menu;

// Code for saving programs on the XFM2
result save_program( int ) {
    // code here
    Serial1.write( 'w' ); // 'w' = write active program into eeprom
    Serial1.write( program ); // ACTIVE_PROGRAM
    return quit;
}

// Code for changing programs on the XFM2
result set_program( ) {
    Serial1.write( 'r' ); // 'r' = loads a program from memory
    Serial1.write( program );
    // we need to get all of the parameters to the loaded program ones
    get_all_parameter();
    return quit;
}
