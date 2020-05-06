// XFM2 UI v0.1
// Based on Teensy 4.0 with an Adafruit SSD1306 and a Clickable rotary encoder
// Github:  https://github.com/marklinton/XFM2UI

#include <Arduino.h>
#include <menu.h>
#include <menuIO/u8g2Out.h>
#include <menuIO/encoderIn.h>
#include "ClickEncoder.h"
#include <menuIO/clickEncoderIn.h>
#include <menuIO/keyIn.h>
#include <menuIO/chainStream.h>
#include <menuIO/serialOut.h>
#include <menuIO/serialIn.h>
#include <Wire.h>
#include "XFM2_params.h"

using namespace Menu;

#define LEDPIN LED_BUILTIN

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
  U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// define startup XFM2 Paramters
int AM_Depth = 0;
int AM_Speed = 0;
int AM_Range = 0;

// define menu colors
const colorDef<uint8_t> colors[6] MEMMODE={
  {{0,0},{0,1,1}},//bgColor
  {{1,1},{1,0,0}},//fgColor
  {{1,1},{1,0,0}},//valColor
  {{1,1},{1,0,0}},//unitColor
  {{0,1},{0,0,1}},//cursorColor
  {{1,1},{1,0,0}},//titleColor
};

MENU(AMsubMenu,"Amplitude Modulation",doNothing,noEvent,noStyle
  ,FIELD(AM_Depth,"AM Depth","",1,255,1,1,doNothing,noEvent,noStyle)
  ,FIELD(AM_Speed,"AM Speed","",1,255,1,1,doNothing,noEvent,noStyle)
  ,FIELD(AM_Range,"AM Range","",0,255,1,1,doNothing,noEvent,noStyle)
  ,EXIT("<Back")
);
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
  ,OP("BitCrusher",doNothing,noEvent)
  ,OP("Decimator",doNothing,noEvent)
  ,OP("Filter",doNothing,noEvent)
  ,OP("Chorus - Flanger",doNothing,noEvent)
  ,OP("Phaser",doNothing,noEvent)
  ,SUBMENU(AMsubMenu)
  ,OP("Delay",doNothing,noEvent)
  ,OP("Effects Routing",doNothing,noEvent)
  ,OP("Global Reverb",doNothing,noEvent)
  ,EXIT("<Back")
);

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
keyMap encBtn_map[]={{-encBtn,defaultNavCodes[enterCmd].ch}}; //negative pin numbers use internal pull-up, this is on when low
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
//XFM2 paramter setting - From Rene's code

void set_unit( int unit ) {
    // Default to unit 1
    Serial1.write( unit == 2 ? '2' : '1' );
}

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

// two serial port setup
// serial - the primary serial port for the output of the menu
// serial1 - the output for the UART comms with the XFM2

void setup() {
  Serial.begin(500000);
  Serial1.begin(500000);
  pinMode( LED_BUILTIN, OUTPUT );
  while(!Serial);
  Serial.println("XFM2 UI V1.0");Serial.flush();
  encButton.begin();
  encoder.begin();
  Wire.begin();
  u8g2.begin();
  u8g2.setFont(fontName);

  nav.idleTask=idle; //point a function to be used when menu is suspended
  Serial.println("Setup complete.");Serial.flush();
}

void loop() {

  // Statics
  // This section needs to be updated with code to change multiple parameters based on the selected values
    static int in0;
    static int v0;
    static int v1;
    static int v2;
    static int avg0;
    static int avg1;
    static int avg2;
    static int last0 = 2000;
    static int last1 = 2000;
    static int last2 = 2000;

    // Read value from menu variable
    v0 = AM_Range;
    v1 = AM_Speed;
    v2 = AM_Depth;

    // Smooth value cheaper than a cap
    avg0 += ( v0 - avg0 ) / 2;
    avg1 += ( v1 - avg1 ) / 2;
    avg2 += ( v2 - avg2 ) / 2;

    // 10-bit -> 8-bit
    int a0 = avg0 >> 2; 
    int a1 = avg1 >> 2; 
    int a2 = avg2 >> 2; 
    
    // New value? send it to XFM2
    if(( a0 != last0 ) || ( a1 != last1) || (a2 != last2)) {
        // Set this message to be sent to XFM2 unit 1 (change to '2' to send to the second unit)
        set_unit( 1 );
        
        // Send parameter AM DEPTH (#332) with value 255
        // NOTE: This first message is just needed to ensure the next parameter effect is heard
        set_parameter( PRM_AM_DEPTH, a2 );
        set_parameter( PRM_AM_SPEED, a1 );

        // Send parameter AM SPEED RANGE (#331) with the read value
        set_parameter( PRM_AM_RANGE, a0 );
        Serial.println(a2);
        // Flash some light as to assert dominance
        digitalWrite( LED_BUILTIN, HIGH );
        digitalWrite( LED_BUILTIN, LOW );

    }
    last0 = a0;
    last1 = a1;
    last2 = a2;

  nav.doInput();

  if (nav.changed(0)) {  //only draw if menu changed for gfx device
    //change checking leaves more time for other tasks
    u8g2.firstPage();
    do nav.doOutput(); while(u8g2.nextPage());
  }
}