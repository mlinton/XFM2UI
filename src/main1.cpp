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
  //Maximum depth of the menu system
  #define MAX_DEPTH 4
  // Configure the SSD1306 with U8G2 / I2C
  U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void set_parameter( int param, int value );

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

Exit back("<Back");

// Code to allow for dynamic creation of menu items

#define MK_FIELD(title,var,low,high) new menuField<typeof(var)>(var,title,"",1,255,1,0,Param<PRM_##var,var>::set,enterEvent)

  // Operator Menu,1,255),
prompt* OPMenu_data[]={
  MK_FIELD("DESCRIPTION",OSC_SYNC,1,255),
  MK_FIELD("DESCRIPTION",OSC_MODE,1,255),
  MK_FIELD("DESCRIPTION",EG_LOOP,1,255),
  MK_FIELD("DESCRIPTION",EG_LOOP_SEG,1,255),
  &back
};
  // Operator 1 (0),1,255)
prompt* OPSMenu_data[]={
  MK_FIELD("DESCRIPTION",ALGO0,1,255),
  MK_FIELD("DESCRIPTION",ALGO1,1,255),
  MK_FIELD("DESCRIPTION",ALGO2,1,255),
  MK_FIELD("DESCRIPTION",ALGO3,1,255),
  MK_FIELD("DESCRIPTION",ALGO4,1,255),
  MK_FIELD("DESCRIPTION",ALGO5,1,255),
  MK_FIELD("DESCRIPTION",FEEDBACK0,1,255),
  MK_FIELD("DESCRIPTION",FEEDBACK1,1,255),
  MK_FIELD("DESCRIPTION",FEEDBACK2,1,255),
  MK_FIELD("DESCRIPTION",FEEDBACK3,1,255),
  MK_FIELD("DESCRIPTION",FEEDBACK4,1,255),
  MK_FIELD("DESCRIPTION",FEEDBACK5,1,255),
  MK_FIELD("DESCRIPTION",RATIO0,1,255),
  MK_FIELD("DESCRIPTION",RATIO1,1,255),
  MK_FIELD("DESCRIPTION",RATIO2,1,255),
  MK_FIELD("DESCRIPTION",RATIO3,1,255),
  MK_FIELD("DESCRIPTION",RATIO4,1,255),
  MK_FIELD("DESCRIPTION",RATIO5,1,255),
  MK_FIELD("DESCRIPTION",RATIO_FINE0,1,255),
  MK_FIELD("DESCRIPTION",RATIO_FINE1,1,255),
  MK_FIELD("DESCRIPTION",RATIO_FINE2,1,255),
  MK_FIELD("DESCRIPTION",RATIO_FINE3,1,255),
  MK_FIELD("DESCRIPTION",RATIO_FINE4,1,255),
  MK_FIELD("DESCRIPTION",RATIO_FINE5,1,255),
  MK_FIELD("DESCRIPTION",FINE0,1,255),
  MK_FIELD("DESCRIPTION",FINE1,1,255),
  MK_FIELD("DESCRIPTION",FINE2,1,255),
  MK_FIELD("DESCRIPTION",FINE3,1,255),
  MK_FIELD("DESCRIPTION",FINE4,1,255),
  MK_FIELD("DESCRIPTION",FINE5,1,255),
  MK_FIELD("DESCRIPTION",LEVEL0,1,255),
  MK_FIELD("DESCRIPTION",LEVEL1,1,255),
  MK_FIELD("DESCRIPTION",LEVEL2,1,255),
  MK_FIELD("DESCRIPTION",LEVEL3,1,255),
  MK_FIELD("DESCRIPTION",LEVEL4,1,255),
  MK_FIELD("DESCRIPTION",LEVEL5,1,255),
  MK_FIELD("DESCRIPTION",VEL_SENS0,1,255),
  MK_FIELD("DESCRIPTION",VEL_SENS1,1,255),
  MK_FIELD("DESCRIPTION",VEL_SENS2,1,255),
  MK_FIELD("DESCRIPTION",VEL_SENS3,1,255),
  MK_FIELD("DESCRIPTION",VEL_SENS4,1,255),
  MK_FIELD("DESCRIPTION",VEL_SENS5,1,255),
  MK_FIELD("DESCRIPTION",KEY_BP0,1,255),
  MK_FIELD("DESCRIPTION",KEY_BP1,1,255),
  MK_FIELD("DESCRIPTION",KEY_BP2,1,255),
  MK_FIELD("DESCRIPTION",KEY_BP3,1,255),
  MK_FIELD("DESCRIPTION",KEY_BP4,1,255),
  MK_FIELD("DESCRIPTION",KEY_BP5,1,255),
  MK_FIELD("DESCRIPTION",KEY_LDEPTH0,1,255),
  MK_FIELD("DESCRIPTION",KEY_LDEPTH1,1,255),
  MK_FIELD("DESCRIPTION",KEY_LDEPTH2,1,255),
  MK_FIELD("DESCRIPTION",KEY_LDEPTH3,1,255),
  MK_FIELD("DESCRIPTION",KEY_LDEPTH4,1,255),
  MK_FIELD("DESCRIPTION",KEY_LDEPTH5,1,255),
  MK_FIELD("DESCRIPTION",KEY_RDEPTH0,1,255),
  MK_FIELD("DESCRIPTION",KEY_RDEPTH1,1,255),
  MK_FIELD("DESCRIPTION",KEY_RDEPTH2,1,255),
  MK_FIELD("DESCRIPTION",KEY_RDEPTH3,1,255),
  MK_FIELD("DESCRIPTION",KEY_RDEPTH4,1,255),
  MK_FIELD("DESCRIPTION",KEY_RDEPTH5,1,255),
  MK_FIELD("DESCRIPTION",KEY_LCURVE0,1,255),
  MK_FIELD("DESCRIPTION",KEY_LCURVE1,1,255),
  MK_FIELD("DESCRIPTION",KEY_LCURVE2,1,255),
  MK_FIELD("DESCRIPTION",KEY_LCURVE3,1,255),
  MK_FIELD("DESCRIPTION",KEY_LCURVE4,1,255),
  MK_FIELD("DESCRIPTION",KEY_LCURVE5,1,255),
  MK_FIELD("DESCRIPTION",KEY_RCURVE0,1,255),
  MK_FIELD("DESCRIPTION",KEY_RCURVE1,1,255),
  MK_FIELD("DESCRIPTION",KEY_RCURVE2,1,255),
  MK_FIELD("DESCRIPTION",KEY_RCURVE3,1,255),
  MK_FIELD("DESCRIPTION",KEY_RCURVE4,1,255),
  MK_FIELD("DESCRIPTION",KEY_RCURVE5,1,255),
  MK_FIELD("DESCRIPTION",L1_0,1,255),
  MK_FIELD("DESCRIPTION",L1_1,1,255),
  MK_FIELD("DESCRIPTION",L1_2,1,255),
  MK_FIELD("DESCRIPTION",L1_3,1,255),
  MK_FIELD("DESCRIPTION",L1_4,1,255),
  MK_FIELD("DESCRIPTION",L1_5,1,255),
  MK_FIELD("DESCRIPTION",L2_0,1,255),
  MK_FIELD("DESCRIPTION",L2_1,1,255),
  MK_FIELD("DESCRIPTION",L2_2,1,255),
  MK_FIELD("DESCRIPTION",L2_3,1,255),
  MK_FIELD("DESCRIPTION",L2_4,1,255),
  MK_FIELD("DESCRIPTION",L2_5,1,255),
  MK_FIELD("DESCRIPTION",L3_0,1,255),
  MK_FIELD("DESCRIPTION",L3_1,1,255),
  MK_FIELD("DESCRIPTION",L3_2,1,255),
  MK_FIELD("DESCRIPTION",L3_3,1,255),
  MK_FIELD("DESCRIPTION",L3_4,1,255),
  MK_FIELD("DESCRIPTION",L3_5,1,255),
  MK_FIELD("DESCRIPTION",L4_0,1,255),
  MK_FIELD("DESCRIPTION",L4_1,1,255),
  MK_FIELD("DESCRIPTION",L4_2,1,255),
  MK_FIELD("DESCRIPTION",L4_3,1,255),
  MK_FIELD("DESCRIPTION",L4_4,1,255),
  MK_FIELD("DESCRIPTION",L4_5,1,255),
  MK_FIELD("DESCRIPTION",R1_0,1,255),
  MK_FIELD("DESCRIPTION",R1_1,1,255),
  MK_FIELD("DESCRIPTION",R1_2,1,255),
  MK_FIELD("DESCRIPTION",R1_3,1,255),
  MK_FIELD("DESCRIPTION",R1_4,1,255),
  MK_FIELD("DESCRIPTION",R1_5,1,255),
  MK_FIELD("DESCRIPTION",R2_0,1,255),
  MK_FIELD("DESCRIPTION",R2_1,1,255),
  MK_FIELD("DESCRIPTION",R2_2,1,255),
  MK_FIELD("DESCRIPTION",R2_3,1,255),
  MK_FIELD("DESCRIPTION",R2_4,1,255),
  MK_FIELD("DESCRIPTION",R2_5,1,255),
  MK_FIELD("DESCRIPTION",R3_0,1,255),
  MK_FIELD("DESCRIPTION",R3_1,1,255),
  MK_FIELD("DESCRIPTION",R3_2,1,255),
  MK_FIELD("DESCRIPTION",R3_3,1,255),
  MK_FIELD("DESCRIPTION",R3_4,1,255),
  MK_FIELD("DESCRIPTION",R3_5,1,255),
  MK_FIELD("DESCRIPTION",R4_0,1,255),
  MK_FIELD("DESCRIPTION",R4_1,1,255),
  MK_FIELD("DESCRIPTION",R4_2,1,255),
  MK_FIELD("DESCRIPTION",R4_3,1,255),
  MK_FIELD("DESCRIPTION",R4_4,1,255),
  MK_FIELD("DESCRIPTION",R4_5,1,255),
  MK_FIELD("DESCRIPTION",L0_0,1,255),
  MK_FIELD("DESCRIPTION",L0_1,1,255),
  MK_FIELD("DESCRIPTION",L0_2,1,255),
  MK_FIELD("DESCRIPTION",L0_3,1,255),
  MK_FIELD("DESCRIPTION",L0_4,1,255),
  MK_FIELD("DESCRIPTION",L0_5,1,255),
  MK_FIELD("DESCRIPTION",R0_0,1,255),
  MK_FIELD("DESCRIPTION",R0_1,1,255),
  MK_FIELD("DESCRIPTION",R0_2,1,255),
  MK_FIELD("DESCRIPTION",R0_3,1,255),
  MK_FIELD("DESCRIPTION",R0_4,1,255),
  MK_FIELD("DESCRIPTION",R0_5,1,255),
  MK_FIELD("DESCRIPTION",L5_0,1,255),
  MK_FIELD("DESCRIPTION",L5_1,1,255),
  MK_FIELD("DESCRIPTION",L5_2,1,255),
  MK_FIELD("DESCRIPTION",L5_3,1,255),
  MK_FIELD("DESCRIPTION",L5_4,1,255),
  MK_FIELD("DESCRIPTION",L5_5,1,255),
  MK_FIELD("DESCRIPTION",R5_0,1,255),
  MK_FIELD("DESCRIPTION",R5_1,1,255),
  MK_FIELD("DESCRIPTION",R5_2,1,255),
  MK_FIELD("DESCRIPTION",R5_3,1,255),
  MK_FIELD("DESCRIPTION",R5_4,1,255),
  MK_FIELD("DESCRIPTION",R5_5,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMS0,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMS1,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMS2,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMS3,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMS4,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMS5,1,255),
  MK_FIELD("DESCRIPTION",LFO_PMS0,1,255),
  MK_FIELD("DESCRIPTION",LFO_PMS1,1,255),
  MK_FIELD("DESCRIPTION",LFO_PMS2,1,255),
  MK_FIELD("DESCRIPTION",LFO_PMS3,1,255),
  MK_FIELD("DESCRIPTION",LFO_PMS4,1,255),
  MK_FIELD("DESCRIPTION",LFO_PMS5,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM0,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM1,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM2,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM3,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM4,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM5,1,255),
  MK_FIELD("DESCRIPTION",LEVEL0_L,1,255),
  MK_FIELD("DESCRIPTION",LEVEL0_R,1,255),
  MK_FIELD("DESCRIPTION",LEVEL1_L,1,255),
  MK_FIELD("DESCRIPTION",LEVEL1_R,1,255),
  MK_FIELD("DESCRIPTION",LEVEL2_L,1,255),
  MK_FIELD("DESCRIPTION",LEVEL2_R,1,255),
  MK_FIELD("DESCRIPTION",LEVEL3_L,1,255),
  MK_FIELD("DESCRIPTION",LEVEL3_R,1,255),
  MK_FIELD("DESCRIPTION",LEVEL4_L,1,255),
  MK_FIELD("DESCRIPTION",LEVEL4_R,1,255),
  MK_FIELD("DESCRIPTION",LEVEL5_L,1,255),
  MK_FIELD("DESCRIPTION",LEVEL5_R,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM2_0,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM2_1,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM2_2,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM2_3,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM2_4,1,255),
  MK_FIELD("DESCRIPTION",WAVEFORM2_5,1,255),
  MK_FIELD("DESCRIPTION",WMODE0,1,255),
  MK_FIELD("DESCRIPTION",WMODE1,1,255),
  MK_FIELD("DESCRIPTION",WMODE2,1,255),
  MK_FIELD("DESCRIPTION",WMODE3,1,255),
  MK_FIELD("DESCRIPTION",WMODE4,1,255),
  MK_FIELD("DESCRIPTION",WMODE5,1,255),
  MK_FIELD("DESCRIPTION",WRATIO0,1,255),
  MK_FIELD("DESCRIPTION",WRATIO1,1,255),
  MK_FIELD("DESCRIPTION",WRATIO2,1,255),
  MK_FIELD("DESCRIPTION",WRATIO3,1,255),
  MK_FIELD("DESCRIPTION",WRATIO4,1,255),
  MK_FIELD("DESCRIPTION",WRATIO5,1,255),
  MK_FIELD("DESCRIPTION",OSC_PHASE0,1,255),
  MK_FIELD("DESCRIPTION",OSC_PHASE1,1,255),
  MK_FIELD("DESCRIPTION",OSC_PHASE2,1,255),
  MK_FIELD("DESCRIPTION",OSC_PHASE3,1,255),
  MK_FIELD("DESCRIPTION",OSC_PHASE4,1,255),
  MK_FIELD("DESCRIPTION",OSC_PHASE5,1,255),
  &back
};
  //Program Menu,1,255),
  prompt* PEGMenu_data[]={
  MK_FIELD("DESCRIPTION",EG_PITCH_RANGE,1,255),
  MK_FIELD("DESCRIPTION",EG_PITCH_RANGE_VELO,1,255),
  MK_FIELD("DESCRIPTION",RATE_KEYP,1,255),
  MK_FIELD("DESCRIPTION",L0_P,1,255),
  MK_FIELD("DESCRIPTION",R0_P,1,255),
  MK_FIELD("DESCRIPTION",L5_P,1,255),
  MK_FIELD("DESCRIPTION",R5_P,1,255),
  MK_FIELD("DESCRIPTION",L1_P,1,255),
  MK_FIELD("DESCRIPTION",L2_P,1,255),
  MK_FIELD("DESCRIPTION",L3_P,1,255),
  MK_FIELD("DESCRIPTION",L4_P,1,255),
  MK_FIELD("DESCRIPTION",R1_P,1,255),
  MK_FIELD("DESCRIPTION",R2_P,1,255),
  MK_FIELD("DESCRIPTION",R3_P,1,255),
  MK_FIELD("DESCRIPTION",R4_P,1,255),
  &back
};
  //LFO Menu,1,255),
prompt* LFOMenu_data[]={
  MK_FIELD("DESCRIPTION",LFO_PITCH_DEPTH,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMP_DEPTH,1,255),
  MK_FIELD("DESCRIPTION",LFO_SPEED,1,255),
  MK_FIELD("DESCRIPTION",LFO_SYNC,1,255),
  MK_FIELD("DESCRIPTION",LFO_WAVE,1,255),
  MK_FIELD("DESCRIPTION",LFO_FADE,1,255),
  &back
};
  //Pitch LFO,1,255),
prompt* PMenu_data[]={
  MK_FIELD("DESCRIPTION",LFO_PITCH_DEPTH_BREATH,1,255),
  MK_FIELD("DESCRIPTION",LFO_PITCH_DEPTH_WHEEL,1,255),
  MK_FIELD("DESCRIPTION",LFO_PITCH_DEPTH_FOOT,1,255),
  MK_FIELD("DESCRIPTION",LFO_PITCH_DEPTH_AFTER,1,255),
  &back
};
  //Amp LFO,1,255),
prompt* AMLFOMenu_data[]={
  MK_FIELD("DESCRIPTION",LFO_AMP_DEPTH_BREATH,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMP_DEPTH_WHEEL,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMP_DEPTH_FOOT,1,255),
  MK_FIELD("DESCRIPTION",LFO_AMP_DEPTH_AFTER,1,255),
  &back
};
  //Eg bias,1,255),
prompt* EGMenu_data[]={
  MK_FIELD("DESCRIPTION",VOLUME_DEPTH_AFTER,1,255),
  MK_FIELD("DESCRIPTION",VOLUME_DEPTH_WHEEL,1,255),
  MK_FIELD("DESCRIPTION",VOLUME_DEPTH_BREATH,1,255),
  MK_FIELD("DESCRIPTION",VOLUME_DEPTH_FOOT,1,255),
  &back
};
  //Pitch Depth,1,255),
prompt* PLFOMenu_data[]={
  MK_FIELD("DESCRIPTION",PITCH_DEPTH_AFTER,1,255),
  MK_FIELD("DESCRIPTION",PITCH_DEPTH_BREATH,1,255),
  MK_FIELD("DESCRIPTION",PITCH_DEPTH_FOOT,1,255),
  MK_FIELD("DESCRIPTION",PITCH_DEPTH_RND,1,255),
  &back
};
  //Other,1,255),
prompt* OTHERMenu_data[]={
  MK_FIELD("DESCRIPTION",BEND_RANGE_UP,1,255),
  MK_FIELD("DESCRIPTION",BEND_RANGE_DN,1,255),
  MK_FIELD("DESCRIPTION",TRANSPOSE,1,255),
  MK_FIELD("DESCRIPTION",VOLUME,1,255),
  MK_FIELD("DESCRIPTION",PAN,1,255),
  MK_FIELD("DESCRIPTION",LEGATO,1,255),
  MK_FIELD("DESCRIPTION",PORTA_MODE,1,255),
  MK_FIELD("DESCRIPTION",PORTA_TIME,1,255),
  MK_FIELD("DESCRIPTION",VELO_OFFSET,1,255),
  MK_FIELD("DESCRIPTION",VELO_CURVE,1,255),
  MK_FIELD("DESCRIPTION",EG_RESTART,1,255),
  MK_FIELD("DESCRIPTION",TUNING,1,255),
  MK_FIELD("DESCRIPTION",OUTPUT_LEVEL,1,255),
  &back
};
  //Delay ,1,255),
prompt* DLYMenu_data[]={
  MK_FIELD("DESCRIPTION",SDLY_DRY,1,255),
  MK_FIELD("DESCRIPTION",SDLY_WET,1,255),
  MK_FIELD("DESCRIPTION",SDLY_MODE,1,255),
  MK_FIELD("DESCRIPTION",SDLY_TIME,1,255),
  MK_FIELD("DESCRIPTION",SDLY_FEEDBACK,1,255),
  MK_FIELD("DESCRIPTION",SDLY_FEEDLO,1,255),
  MK_FIELD("DESCRIPTION",SDLY_FEEDHI,1,255),
  MK_FIELD("DESCRIPTION",SDLY_TEMPO,1,255),
  MK_FIELD("DESCRIPTION",SDLY_NUM,1,255),
  MK_FIELD("DESCRIPTION",SDLY_DEN,1,255),
  &back
};
//Phaser,1,255),
prompt* PHMenu_data[]={
  MK_FIELD("DESCRIPTION",PHASER_DRY,1,255),
  MK_FIELD("DESCRIPTION",PHASER_WET,1,255),
  MK_FIELD("DESCRIPTION",PHASER_MODE,1,255),
  MK_FIELD("DESCRIPTION",PHASER_DEPTH,1,255),
  MK_FIELD("DESCRIPTION",PHASER_SPEED,1,255),
  MK_FIELD("DESCRIPTION",PHASER_FEEDBACK,1,255),
  MK_FIELD("DESCRIPTION",PHASER_OFFSET,1,255),
  MK_FIELD("DESCRIPTION",PHASER_STAGES,1,255),
  MK_FIELD("DESCRIPTION",PHASER_PHASE,1,255),
  MK_FIELD("DESCRIPTION",PHASER_WAVEFORM,1,255),
  &back
};
//Amplitude Modulation,1,255),
prompt* AMMenu_data[]={
  MK_FIELD("DESCRIPTION",AM_SPEED,1,255),
  MK_FIELD("DESCRIPTION",AM_RANGE,1,255),
  MK_FIELD("DESCRIPTION",AM_DEPTH,1,255),
  MK_FIELD("DESCRIPTION",AM_PHASE,1,255),
  &back
};
//Waveshaper,1,255),
prompt* WSMenu_data[]={
  MK_FIELD("DESCRIPTION",WAVESHAPER_DRY,1,255),
  MK_FIELD("DESCRIPTION",WAVESHAPER_WET,1,255),
  MK_FIELD("DESCRIPTION",WAVESHAPER_GAIN_PRE,1,255),
  MK_FIELD("DESCRIPTION",WAVESHAPER_GAIN_POST,1,255),
  MK_FIELD("DESCRIPTION",WAVESHAPER_SHAPE,1,255),
  &back
};
//Chorus Menu,1,255),
prompt* CHORUSMenu_data[]={
  MK_FIELD("DESCRIPTION",CHORUS_DRY,1,255),
  MK_FIELD("DESCRIPTION",CHORUS_WET,1,255),
  MK_FIELD("DESCRIPTION",CHORUS_MODE,1,255),
  MK_FIELD("DESCRIPTION",CHORUS_SPEED,1,255),
  MK_FIELD("DESCRIPTION",CHORUS_DEPTH,1,255),
  MK_FIELD("DESCRIPTION",CHORUS_FEEDBACK,1,255),
  MK_FIELD("DESCRIPTION",CHORUS_PHASE,1,255),
  &back
};
//Other Effects Menu,1,255),
prompt* OEMenu_data[]={
  MK_FIELD("DESCRIPTION",DECIMATOR_DEPTH,1,255),
  MK_FIELD("DESCRIPTION",BITCRUSHER_DEPTH,1,255),
  MK_FIELD("DESCRIPTION",FILTER_LO,1,255),
  MK_FIELD("DESCRIPTION",FILTER_HI,1,255),
  &back
};
//Global Reverb,1,255),
prompt* RVBMenu_data[]={
  MK_FIELD("DESCRIPTION",REVERB_DRY,1,255),
  MK_FIELD("DESCRIPTION",REVERB_WET,1,255),
  MK_FIELD("DESCRIPTION",REVERB_MODE,1,255),
  MK_FIELD("DESCRIPTION",REVERB_DECAY,1,255),
  MK_FIELD("DESCRIPTION",REVERB_DAMP,1,255),
  &back
};
//Unknown,1,255),
prompt* UNKNMenu_data[]={
  MK_FIELD("DESCRIPTION",REVERB_D0,1,255),
  MK_FIELD("DESCRIPTION",REVERB_D1,1,255),
  MK_FIELD("DESCRIPTION",REVERB_D2,1,255),
  MK_FIELD("DESCRIPTION",FIR_IMPULSE,1,255),
  &back
};
//FX Routing,1,255),
prompt* FXRMenu_data[]={
  MK_FIELD("DESCRIPTION",FX_ROUTING,1,255),
  &back
};
//Performance Controls,1,255),
prompt* PERFMenu_data[]={
  MK_FIELD("DESCRIPTION",CONTROL_1H,1,255),
  MK_FIELD("DESCRIPTION",CONTROL_1L,1,255),
  MK_FIELD("DESCRIPTION",CONTROL_2H,1,255),
  MK_FIELD("DESCRIPTION",CONTROL_2L,1,255),
  MK_FIELD("DESCRIPTION",CONTROL_3H,1,255),
  MK_FIELD("DESCRIPTION",CONTROL_3L,1,255),
  MK_FIELD("DESCRIPTION",CONTROL_4H,1,255),
  MK_FIELD("DESCRIPTION",CONTROL_4L,1,255),
  &back
};
//Arpeggiator,1,255),
prompt* ARPMenu_data[]={
  MK_FIELD("DESCRIPTION",ARP_MODE,1,255),
  MK_FIELD("DESCRIPTION",ARP_TEMPO,1,255),
  MK_FIELD("DESCRIPTION",ARP_TEMPO_FINE,1,255),
  MK_FIELD("DESCRIPTION",ARP_DIVISION,1,255),
  MK_FIELD("DESCRIPTION",ARP_OCTAVES,1,255),
  &back
};

menuNode AMMenu("Amplitude Modulation",sizeof(AMMenu_data)/sizeof(prompt*),AMMenu_data);
menuNode ARPMenu("Arpeggiator",sizeof(ARPMenu_data)/sizeof(prompt*),ARPMenu_data);
menuNode PERFMenu("Performance Settings",sizeof(PERFMenu_data)/sizeof(prompt*),PERFMenu_data);
menuNode UNKNMenu("Unknown Settings",sizeof(UNKNMenu_data)/sizeof(prompt*),UNKNMenu_data);
menuNode RVBMenu("Reverb",sizeof(RVBMenu_data)/sizeof(prompt*),RVBMenu_data);
menuNode CHORUSMenu("Chorus",sizeof(CHORUSMenu_data)/sizeof(prompt*),CHORUSMenu_data);
menuNode WSMenu("Waveshaper",sizeof(WSMenu_data)/sizeof(prompt*),WSMenu_data);
menuNode PHMenu("Phaser",sizeof(PHMenu_data)/sizeof(prompt*),PHMenu_data);
menuNode DLYMenu("Delay",sizeof(DLYMenu_data)/sizeof(prompt*),DLYMenu_data);
menuNode OTHERmenu("Other",sizeof(OTHERMenu_data)/sizeof(prompt*),OTHERMenu_data);
menuNode PLFOMenu("Pitch",sizeof(PLFOMenu_data)/sizeof(prompt*),PLFOMenu_data);
menuNode EGMenu("Envelope Bias",sizeof(EGMenu_data)/sizeof(prompt*),EGMenu_data);
menuNode AMLFOMenu("AMP LFO",sizeof(AMLFOMenu_data)/sizeof(prompt*),AMLFOMenu_data);
menuNode PMMenu("Pitch LFO",sizeof(PMenu_data)/sizeof(prompt*),PMenu_data);
menuNode LFOMenu("LFO",sizeof(LFOMenu_data)/sizeof(prompt*),LFOMenu_data);
menuNode PEGMenu("Pitch Envelope Generator",sizeof(PEGMenu_data)/sizeof(prompt*),PEGMenu_data);
menuNode OPMenu("Operator",sizeof(OPMenu_data)/sizeof(prompt*),OPMenu_data);
menuNode OPSMenu("Operator Settings",sizeof(OPSMenu_data)/sizeof(prompt*),OPSMenu_data);
menuNode OEMenu("Other Effects",sizeof(OEMenu_data)/sizeof(prompt*),OEMenu_data);

prompt* oprMenu_data[]={&OPMenu,&OPSMenu,&back};
menuNode oprMenu("Operators",sizeof(oprMenu_data)/sizeof(prompt*),oprMenu_data);

prompt* modMenu_data[]={&PLFOMenu,&AMLFOMenu,&EGMenu,&PMMenu,&back};
menuNode modMenu("Modulations",sizeof(modMenu_data)/sizeof(prompt*),modMenu_data);

prompt* effMenu_data[]={&OEMenu,&CHORUSMenu,&PHMenu,&AMMenu,&DLYMenu,&RVBMenu,&back};
menuNode effMenu("Effects",sizeof(effMenu_data)/sizeof(prompt*),effMenu_data);

prompt* progMenu_data[]={&PEGMenu,&LFOMenu,&OTHERmenu,&modMenu,&ARPMenu,&PERFMenu,&back};
menuNode progMenu("Programs",sizeof(progMenu_data)/sizeof(prompt*),progMenu_data);

prompt* mainMenu_data[]={&oprMenu,&progMenu,&modMenu,&effMenu,&back};
menuNode mainMenu("XFM2 UI Main Menu",sizeof(mainMenu_data)/sizeof(prompt*),mainMenu_data);


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
encoderIn<encA,encB> encoder;//simple quad encoder driver
encoderInStream<encA,encB> encStream(encoder,4);// simple quad encoder fake Stream

//a keyboard with only one key as the encoder button
keyMap encBtn_map[]={{-encBtn,defaultNavCodes[enterCmd].ch}}; //negative pin numbers use internal pull-up, this is on when low
keyIn<1> encButton(encBtn_map);//1 is the number of keys
// menuIn* inputsList[]={&encButton};
serialIn serial(Serial);

// MENU_INPUTS(in,&serial);
MENU_INPUTS(in,&encStream,&encButton,&serial);

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
//XFM2 paramter setting - From Rene's code

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

 nav.doInput();

  if (nav.changed(0)) {  //only draw if menu changed for gfx device
    //change checking leaves more time for other tasks
  u8g2.firstPage();
  do nav.doOutput(); while(u8g2.nextPage());
  }
}
