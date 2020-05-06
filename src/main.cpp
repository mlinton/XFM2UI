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
  MK_FIELD("Oscillator Syncronization",OSC_SYNC,1,255), // bitwise setting 13
  MK_FIELD("Oscillator Mode",OSC_MODE,1,255), // 0 or 1 setting 14
  MK_FIELD("Amplitude EG Loop",EG_LOOP,1,255), // bitwise setting 244
  MK_FIELD("DESCRIPTION",EG_LOOP_SEG,1,255), // bitwise setting 245
  &back
};
  // Operator 1 (0),1,255)
prompt* OPSMenu_data[]={
  MK_FIELD("Operator Algorythm 0",ALGO0,1,255), // bitwise setting
  MK_FIELD("Operator Algorythm 1",ALGO1,1,255), // bitwise setting
  MK_FIELD("Operator Algorythm 2",ALGO2,1,255), // bitwise setting
  MK_FIELD("Operator Algorythm 3",ALGO3,1,255), // bitwise setting
  MK_FIELD("Operator Algorythm 4",ALGO4,1,255), // bitwise setting
  MK_FIELD("Operator Algorythm 5",ALGO5,1,255), // bitwise setting
  MK_FIELD("Operator Self-feedback Level",FEEDBACK0,1,255),
  MK_FIELD("Operator Self-feedback Level",FEEDBACK1,1,255),
  MK_FIELD("Operator Self-feedback Level",FEEDBACK2,1,255),
  MK_FIELD("Operator Self-feedback Level",FEEDBACK3,1,255),
  MK_FIELD("Operator Self-feedback Level",FEEDBACK4,1,255),
  MK_FIELD("Operator Self-feedback Level",FEEDBACK5,1,255),
  MK_FIELD("Pitch Ratio",RATIO0,1,255),
  MK_FIELD("Pitch Ratio",RATIO1,1,255),
  MK_FIELD("Pitch Ratio",RATIO2,1,255),
  MK_FIELD("Pitch Ratio",RATIO3,1,255),
  MK_FIELD("Pitch Ratio",RATIO4,1,255),
  MK_FIELD("Pitch Ratio",RATIO5,1,255),
  MK_FIELD("Fine Pitch Ratio",RATIO_FINE0,1,255),
  MK_FIELD("Fine Pitch Ratio",RATIO_FINE1,1,255),
  MK_FIELD("Fine Pitch Ratio",RATIO_FINE2,1,255),
  MK_FIELD("Fine Pitch Ratio",RATIO_FINE3,1,255),
  MK_FIELD("Fine Pitch Ratio",RATIO_FINE4,1,255),
  MK_FIELD("Fine Pitch Ratio",RATIO_FINE5,1,255),
  MK_FIELD("Operator Pitch",FINE0,1,255),
  MK_FIELD("Operator Pitch",FINE1,1,255),
  MK_FIELD("Operator Pitch",FINE2,1,255),
  MK_FIELD("Operator Pitch",FINE3,1,255),
  MK_FIELD("Operator Pitch",FINE4,1,255),
  MK_FIELD("Operator Pitch",FINE5,1,255),
  MK_FIELD("Output Level",LEVEL0,1,255),
  MK_FIELD("Output Level",LEVEL1,1,255),
  MK_FIELD("Output Level",LEVEL2,1,255),
  MK_FIELD("Output Level",LEVEL3,1,255),
  MK_FIELD("Output Level",LEVEL4,1,255),
  MK_FIELD("Output Level",LEVEL5,1,255),
  MK_FIELD("Velocity Sensitivity",VEL_SENS0,1,255),
  MK_FIELD("Velocity Sensitivity",VEL_SENS1,1,255),
  MK_FIELD("Velocity Sensitivity",VEL_SENS2,1,255),
  MK_FIELD("Velocity Sensitivity",VEL_SENS3,1,255),
  MK_FIELD("Velocity Sensitivity",VEL_SENS4,1,255),
  MK_FIELD("Velocity Sensitivity",VEL_SENS5,1,255),
  MK_FIELD("Keyboard Breakpoint",KEY_BP0,1,255),
  MK_FIELD("Keyboard Breakpoint",KEY_BP1,1,255),
  MK_FIELD("Keyboard Breakpoint",KEY_BP2,1,255),
  MK_FIELD("Keyboard Breakpoint",KEY_BP3,1,255),
  MK_FIELD("Keyboard Breakpoint",KEY_BP4,1,255),
  MK_FIELD("Keyboard Breakpoint",KEY_BP5,1,255),
  MK_FIELD("Scaling Depth Left",KEY_LDEPTH0,1,255),
  MK_FIELD("Scaling Depth Left",KEY_LDEPTH1,1,255),
  MK_FIELD("Scaling Depth Left",KEY_LDEPTH2,1,255),
  MK_FIELD("Scaling Depth Left",KEY_LDEPTH3,1,255),
  MK_FIELD("Scaling Depth Left",KEY_LDEPTH4,1,255),
  MK_FIELD("Scaling Depth Left",KEY_LDEPTH5,1,255),
  MK_FIELD("Scaling Depth Right",KEY_RDEPTH0,1,255),
  MK_FIELD("Scaling Depth Right",KEY_RDEPTH1,1,255),
  MK_FIELD("Scaling Depth Right",KEY_RDEPTH2,1,255),
  MK_FIELD("Scaling Depth Right",KEY_RDEPTH3,1,255),
  MK_FIELD("Scaling Depth Right",KEY_RDEPTH4,1,255),
  MK_FIELD("Scaling Depth Right",KEY_RDEPTH5,1,255),
  MK_FIELD("Left Breakpoint Curve",KEY_LCURVE0,1,3),
  MK_FIELD("Left Breakpoint Curve",KEY_LCURVE1,1,3),
  MK_FIELD("Left Breakpoint Curve",KEY_LCURVE2,1,3),
  MK_FIELD("Left Breakpoint Curve",KEY_LCURVE3,1,3),
  MK_FIELD("Left Breakpoint Curve",KEY_LCURVE4,1,3),
  MK_FIELD("Left Breakpoint Curve",KEY_LCURVE5,1,3),
  MK_FIELD("Right Breakpoint Curve",KEY_RCURVE0,1,3),
  MK_FIELD("Right Breakpoint Curve",KEY_RCURVE1,1,3),
  MK_FIELD("Right Breakpoint Curve",KEY_RCURVE2,1,3),
  MK_FIELD("Right Breakpoint Curve",KEY_RCURVE3,1,3),
  MK_FIELD("Right Breakpoint Curve",KEY_RCURVE4,1,3),
  MK_FIELD("Right Breakpoint Curve",KEY_RCURVE5,1,3),
  MK_FIELD("EG Level Left - Decay 1",L1_0,1,255),
  MK_FIELD("EG Level Left - Decay 1",L1_1,1,255),
  MK_FIELD("EG Level Left - Decay 1",L1_2,1,255),
  MK_FIELD("EG Level Left - Decay 1",L1_3,1,255),
  MK_FIELD("EG Level Left - Decay 1",L1_4,1,255),
  MK_FIELD("EG Level Left - Decay 1",L1_5,1,255),
  MK_FIELD("EG Level Left - Decay 2",L2_0,1,255),
  MK_FIELD("EG Level Left - Decay 2",L2_1,1,255),
  MK_FIELD("EG Level Left - Decay 2",L2_2,1,255),
  MK_FIELD("EG Level Left - Decay 2",L2_3,1,255),
  MK_FIELD("EG Level Left - Decay 2",L2_4,1,255),
  MK_FIELD("EG Level Left - Decay 2",L2_5,1,255),
  MK_FIELD("EG Level Left - Sustain",L3_0,1,255),
  MK_FIELD("EG Level Left - Sustain",L3_1,1,255),
  MK_FIELD("EG Level Left - Sustain",L3_2,1,255),
  MK_FIELD("EG Level Left - Sustain",L3_3,1,255),
  MK_FIELD("EG Level Left - Sustain",L3_4,1,255),
  MK_FIELD("EG Level Left - Sustain",L3_5,1,255),
  MK_FIELD("EG Level Left - Release 1",L4_0,1,255),
  MK_FIELD("EG Level Left - Release 1",L4_1,1,255),
  MK_FIELD("EG Level Left - Release 1",L4_2,1,255),
  MK_FIELD("EG Level Left - Release 1",L4_3,1,255),
  MK_FIELD("EG Level Left - Release 1",L4_4,1,255),
  MK_FIELD("EG Level Left - Release 1",L4_5,1,255),
  MK_FIELD("EG Level Right - Decay 1",R1_0,1,255),
  MK_FIELD("EG Level Right - Decay 1",R1_1,1,255),
  MK_FIELD("EG Level Right - Decay 1",R1_2,1,255),
  MK_FIELD("EG Level Right - Decay 1",R1_3,1,255),
  MK_FIELD("EG Level Right - Decay 1",R1_4,1,255),
  MK_FIELD("EG Level Right - Decay 1",R1_5,1,255),
  MK_FIELD("EG Level Right - Decay 2",R2_0,1,255),
  MK_FIELD("EG Level Right - Decay 2",R2_1,1,255),
  MK_FIELD("EG Level Right - Decay 2",R2_2,1,255),
  MK_FIELD("EG Level Right - Decay 2",R2_3,1,255),
  MK_FIELD("EG Level Right - Decay 2",R2_4,1,255),
  MK_FIELD("EG Level Right - Decay 2",R2_5,1,255),
  MK_FIELD("EG Level Right - Sustain",R3_0,1,255),
  MK_FIELD("EG Level Right - Sustain",R3_1,1,255),
  MK_FIELD("EG Level Right - Sustain",R3_2,1,255),
  MK_FIELD("EG Level Right - Sustain",R3_3,1,255),
  MK_FIELD("EG Level Right - Sustain",R3_4,1,255),
  MK_FIELD("EG Level Right - Sustain",R3_5,1,255),
  MK_FIELD("EG Level Right - Release 1",R4_0,1,255),
  MK_FIELD("EG Level Right - Release 1",R4_1,1,255),
  MK_FIELD("EG Level Right - Release 1",R4_2,1,255),
  MK_FIELD("EG Level Right - Release 1",R4_3,1,255),
  MK_FIELD("EG Level Right - Release 1",R4_4,1,255),
  MK_FIELD("EG Level Right - Release 1",R4_5,1,255),
  MK_FIELD("EG Level Left - Attack",L0_0,1,255),
  MK_FIELD("EG Level Left - Attack",L0_1,1,255),
  MK_FIELD("EG Level Left - Attack",L0_2,1,255),
  MK_FIELD("EG Level Left - Attack",L0_3,1,255),
  MK_FIELD("EG Level Left - Attack",L0_4,1,255),
  MK_FIELD("EG Level Left - Attack",L0_5,1,255),
  MK_FIELD("EG Level Right - Attack",R0_0,1,255),
  MK_FIELD("EG Level Right - Attack",R0_1,1,255),
  MK_FIELD("EG Level Right - Attack",R0_2,1,255),
  MK_FIELD("EG Level Right - Attack",R0_3,1,255),
  MK_FIELD("EG Level Right - Attack",R0_4,1,255),
  MK_FIELD("EG Level Right - Attack",R0_5,1,255),
  MK_FIELD("EG Level Left - Release 2",L5_0,1,255),
  MK_FIELD("EG Level Left - Release 2",L5_1,1,255),
  MK_FIELD("EG Level Left - Release 2",L5_2,1,255),
  MK_FIELD("EG Level Left - Release 2",L5_3,1,255),
  MK_FIELD("EG Level Left - Release 2",L5_4,1,255),
  MK_FIELD("EG Level Left - Release 2",L5_5,1,255),
  MK_FIELD("EG Level Right - Release 2",R5_1,1,255),
  MK_FIELD("EG Level Right - Release 2",R5_0,1,255),
  MK_FIELD("EG Level Right - Release 2",R5_2,1,255),
  MK_FIELD("EG Level Right - Release 2",R5_3,1,255),
  MK_FIELD("EG Level Right - Release 2",R5_4,1,255),
  MK_FIELD("EG Level Right - Release 2",R5_5,1,255),
  MK_FIELD("Amplitude LFO",LFO_AMS0,1,255),
  MK_FIELD("Amplitude LFO",LFO_AMS1,1,255),
  MK_FIELD("Amplitude LFO",LFO_AMS2,1,255),
  MK_FIELD("Amplitude LFO",LFO_AMS3,1,255),
  MK_FIELD("Amplitude LFO",LFO_AMS4,1,255),
  MK_FIELD("Amplitude LFO",LFO_AMS5,1,255),
  MK_FIELD("Pitch LFO",LFO_PMS0,1,255),
  MK_FIELD("Pitch LFO",LFO_PMS1,1,255),
  MK_FIELD("Pitch LFO",LFO_PMS2,1,255),
  MK_FIELD("Pitch LFO",LFO_PMS3,1,255),
  MK_FIELD("Pitch LFO",LFO_PMS4,1,255),
  MK_FIELD("Pitch LFO",LFO_PMS5,1,255),
  MK_FIELD("OSC1 Waveform",WAVEFORM0,0,7),
  MK_FIELD("OSC1 Waveform",WAVEFORM1,0,7),
  MK_FIELD("OSC1 Waveform",WAVEFORM2,0,7),
  MK_FIELD("OSC1 Waveform",WAVEFORM3,0,7),
  MK_FIELD("OSC1 Waveform",WAVEFORM4,0,7),
  MK_FIELD("OSC1 Waveform",WAVEFORM5,0,7),
  MK_FIELD("Operator Level - Left",LEVEL0_L,1,255),
  MK_FIELD("Operator Level - Right",LEVEL0_R,1,255),
  MK_FIELD("Operator Level - Left",LEVEL1_L,1,255),
  MK_FIELD("Operator Level - Right",LEVEL1_R,1,255),
  MK_FIELD("Operator Level - Left",LEVEL2_L,1,255),
  MK_FIELD("Operator Level - Right",LEVEL2_R,1,255),
  MK_FIELD("Operator Level - Left",LEVEL3_L,1,255),
  MK_FIELD("Operator Level - Right",LEVEL3_R,1,255),
  MK_FIELD("Operator Level - Left",LEVEL4_L,1,255),
  MK_FIELD("Operator Level - Right",LEVEL4_R,1,255),
  MK_FIELD("Operator Level - Left",LEVEL5_L,1,255),
  MK_FIELD("Operator Level - Right",LEVEL5_R,1,255),
  MK_FIELD("OSC2 Waveform",WAVEFORM2_0,0,7),
  MK_FIELD("OSC2 Waveform",WAVEFORM2_1,0,7),
  MK_FIELD("OSC2 Waveform",WAVEFORM2_2,0,7),
  MK_FIELD("OSC2 Waveform",WAVEFORM2_3,0,7),
  MK_FIELD("OSC2 Waveform",WAVEFORM2_4,0,7),
  MK_FIELD("OSC2 Waveform",WAVEFORM2_5,0,7),
  MK_FIELD("Waveform Mode",WMODE0,0,1),
  MK_FIELD("Waveform Mode",WMODE1,0,1),
  MK_FIELD("Waveform Mode",WMODE2,0,1),
  MK_FIELD("Waveform Mode",WMODE3,0,1),
  MK_FIELD("Waveform Mode",WMODE4,0,1),
  MK_FIELD("Waveform Mode",WMODE5,0,1),
  MK_FIELD("Waveform Ratio",WRATIO0,0,255),
  MK_FIELD("Waveform Ratio",WRATIO1,0,255),
  MK_FIELD("Waveform Ratio",WRATIO2,0,255),
  MK_FIELD("Waveform Ratio",WRATIO3,0,255),
  MK_FIELD("Waveform Ratio",WRATIO4,0,255),
  MK_FIELD("Waveform Ratio",WRATIO5,0,255),
  MK_FIELD("Oscillator Phase",OSC_PHASE0,0,3),
  MK_FIELD("Oscillator Phase",OSC_PHASE1,0,3),
  MK_FIELD("Oscillator Phase",OSC_PHASE2,0,3),
  MK_FIELD("Oscillator Phase",OSC_PHASE3,0,3),
  MK_FIELD("Oscillator Phase",OSC_PHASE4,0,3),
  MK_FIELD("Oscillator Phase",OSC_PHASE5,0,3),
  &back
};
  //Program Menu,1,255),
  prompt* PEGMenu_data[]={
  MK_FIELD("Pitch Range in Octaves",EG_PITCH_RANGE,1,255),
  MK_FIELD("Midi Pitch Velocity",EG_PITCH_RANGE_VELO,1,255),
  MK_FIELD("EG Pitch Rate Key",RATE_KEYP,1,255),
  MK_FIELD("EG - Left Attack",L0_P,1,255),
  MK_FIELD("EG - Right Attack ",R0_P,1,255),
  MK_FIELD("EG - Left Release 2",L5_P,1,255),
  MK_FIELD("EG - Right Release 2 ",R5_P,1,255),
  MK_FIELD("EG - Left Decay ",L1_P,1,255),
  MK_FIELD("EG - Left Decay 2",L2_P,1,255),
  MK_FIELD("EG - Left Sustain",L3_P,1,255),
  MK_FIELD("EG - Left Relase ",L4_P,1,255),
  MK_FIELD("EG - Right Decay ",R1_P,1,255),
  MK_FIELD("EG - Right Decay 2 ",R2_P,1,255),
  MK_FIELD("EG - Right Sustain ",R3_P,1,255),
  MK_FIELD("EG - Right Release ",R4_P,1,255),
  &back
};
  //LFO Menu,1,255),
prompt* LFOMenu_data[]={
  MK_FIELD("LFO Effect Applied to Pitch",LFO_PITCH_DEPTH,1,255),
  MK_FIELD("LFO Effect Applied to Amplitude",LFO_AMP_DEPTH,1,255),
  MK_FIELD("LFO Speed",LFO_SPEED,1,255),
  MK_FIELD("Sync",LFO_SYNC,0,3), //Single - Free Running, Single - Key Sync, Multi - Free running, Multi - Key Sync
  MK_FIELD("LFO Waveform",LFO_WAVE,0,5), //Triangle, Square, Saw up, Saw Down, Sine, Random
  MK_FIELD("Fade",LFO_FADE,0,255),
  &back
};
  //Pitch LFO,1,255),
prompt* PMenu_data[]={
  MK_FIELD("Breath",LFO_PITCH_DEPTH_BREATH,1,255),
  MK_FIELD("Wheel Controller",LFO_PITCH_DEPTH_WHEEL,1,255),
  MK_FIELD("Foot Controller",LFO_PITCH_DEPTH_FOOT,1,255),
  MK_FIELD("Aftertouch",LFO_PITCH_DEPTH_AFTER,1,255),
  &back
};
  //Amp LFO,1,255),
prompt* AMLFOMenu_data[]={
  MK_FIELD("Breath",LFO_AMP_DEPTH_BREATH,1,255),
  MK_FIELD("Wheel Controller",LFO_AMP_DEPTH_WHEEL,1,255),
  MK_FIELD("Foot Controller",LFO_AMP_DEPTH_FOOT,1,255),
  MK_FIELD("Aftertouch",LFO_AMP_DEPTH_AFTER,1,255),
  &back
};
  //Eg bias,1,255),
prompt* EGMenu_data[]={
  MK_FIELD("Aftertouch",VOLUME_DEPTH_AFTER,1,255),
  MK_FIELD("Wheel Controller",VOLUME_DEPTH_WHEEL,1,255),
  MK_FIELD("Breath",VOLUME_DEPTH_BREATH,1,255),
  MK_FIELD("Foot Controller",VOLUME_DEPTH_FOOT,1,255),
  &back
};
  //Pitch Depth,1,255),
prompt* PLFOMenu_data[]={
  MK_FIELD("Aftertouch",PITCH_DEPTH_AFTER,1,255),
  MK_FIELD("Breath",PITCH_DEPTH_BREATH,1,255),
  MK_FIELD("Foot Controller",PITCH_DEPTH_FOOT,1,255),
  MK_FIELD("Random",PITCH_DEPTH_RND,1,255),
  &back
};
  //Other,1,255),
prompt* OTHERMenu_data[]={
  MK_FIELD("Pitch Bend Range Up",BEND_RANGE_UP,1,255),
  MK_FIELD("Pitch Bend Range Down",BEND_RANGE_DN,1,255),
  MK_FIELD("Transpose",TRANSPOSE,1,255),  //Center value is 24
  MK_FIELD("Overall Voice Mix Volume",VOLUME,1,255),
  MK_FIELD("Voice Mix Pan",PAN,1,255),
  MK_FIELD("Legato Mode",LEGATO,0,1), // Polyphonic or Monophonic
  MK_FIELD("Portamento Mode",PORTA_MODE,0,3), // 0 off, 1 Always, 2 Fingered
  MK_FIELD("Portamento Time",PORTA_TIME,1,255),
  MK_FIELD("Velocity Offset",VELO_OFFSET,1,255),
  MK_FIELD("Velocity Curve",VELO_CURVE,1,255),
  MK_FIELD("Envelope Generator Restart",EG_RESTART,1,255),
  MK_FIELD("Selected Tuning",TUNING,1,255), // list is a list from the tuning file scl
  MK_FIELD("Overall Output Level",OUTPUT_LEVEL,0,3),  // output gain setting.  0 - none, 1 - 3db, 2 - 6db, 3 - 9db
  &back
};
  //Delay ,1,255),
prompt* DLYMenu_data[]={
  MK_FIELD("Dry Level",SDLY_DRY,1,255),
  MK_FIELD("Wet Level",SDLY_WET,1,255),
  MK_FIELD("Mode",SDLY_MODE,0,2), // 0 - Stereo, 1 - Cross, 2 - Ping Pong
  MK_FIELD("Time",SDLY_TIME,1,255), // 0 tracks with the TEMPO setting
  MK_FIELD("Feedback",SDLY_FEEDBACK,1,255),
  MK_FIELD("Low Pass Filter",SDLY_FEEDLO,1,255),
  MK_FIELD("High Pass Filter",SDLY_FEEDHI,1,255),
  MK_FIELD("Delay Tempo BPM (50-255)",SDLY_TEMPO,50,255),
  MK_FIELD("Tempo Multiplier",SDLY_NUM,1,255),
  MK_FIELD("Tempo Divider",SDLY_DEN,1,255),
  &back
};
//Phaser,1,255),
prompt* PHMenu_data[]={
  MK_FIELD("Dry Level",PHASER_DRY,1,255),
  MK_FIELD("Wet Level",PHASER_WET,1,255),
  MK_FIELD("Mode",PHASER_MODE,0,2), // 0 - Mono, 1 - Stereo, 2 - Cross
  MK_FIELD("Depth",PHASER_DEPTH,1,255),
  MK_FIELD("Speed",PHASER_SPEED,1,255),
  MK_FIELD("Feedback",PHASER_FEEDBACK,1,255),
  MK_FIELD("Offset",PHASER_OFFSET,1,255),
  MK_FIELD("Stages 4 - 12",PHASER_STAGES,4,12),  // not sure of the range here
  MK_FIELD("Left/Right Phase",PHASER_PHASE,1,255), // 128 is middle
  MK_FIELD("Waveform",PHASER_WAVEFORM,1,255),
  &back
};
//Amplitude Modulation,1,255),
prompt* AMMenu_data[]={
  MK_FIELD("Speed",AM_SPEED,1,255),
  MK_FIELD("Range",AM_RANGE,1,255),
  MK_FIELD("Depth",AM_DEPTH,1,255),
  MK_FIELD("Left/Right Phase",AM_PHASE,1,255), //128 is the middle
  &back
};
//Waveshaper,1,255),
prompt* WSMenu_data[]={
  MK_FIELD("Dry Level",WAVESHAPER_DRY,1,255),
  MK_FIELD("Wet Level",WAVESHAPER_WET,1,255),
  MK_FIELD("Pre-Gain",WAVESHAPER_GAIN_PRE,1,255),
  MK_FIELD("Post-Gain",WAVESHAPER_GAIN_POST,1,255),
  MK_FIELD("Shape",WAVESHAPER_SHAPE,1,255),
  &back
};
//Chorus Menu,1,255),
prompt* CHORUSMenu_data[]={
  MK_FIELD("Dry Level",CHORUS_DRY,1,255),
  MK_FIELD("Wet Level",CHORUS_WET,1,255),
  MK_FIELD("Mode",CHORUS_MODE,0,3), // 0 - Long Chorus, 1 - Short Chorus, 2 - Long Flanger, 3 - Short Flanger
  MK_FIELD("Speed",CHORUS_SPEED,1,255),
  MK_FIELD("Depth",CHORUS_DEPTH,1,255),
  MK_FIELD("Feedback",CHORUS_FEEDBACK,1,255),
  MK_FIELD("Left/Right Phase",CHORUS_PHASE,1,255), //128 is the middle
  &back
};
//Other Effects Menu,1,255),
prompt* OEMenu_data[]={
  MK_FIELD("Decimator Depth",DECIMATOR_DEPTH,1,255),
  MK_FIELD("Bitcrusher Depth",BITCRUSHER_DEPTH,1,255),
  MK_FIELD("Lo-Pass Filter Cutoff",FILTER_LO,1,255),
  MK_FIELD("High-Pass Filter Cutoff",FILTER_HI,1,255),
  &back
};
//Global Reverb,1,255),
prompt* RVBMenu_data[]={
  MK_FIELD("Dry Level",REVERB_DRY,1,255),
  MK_FIELD("Wet Level",REVERB_WET,1,255),
  MK_FIELD("Mode",REVERB_MODE,0,1), // 0 - Plate, 1 - Hall
  MK_FIELD("Decay Time",REVERB_DECAY,1,255),
  MK_FIELD("HiFreq Dampening",REVERB_DAMP,1,255),
  &back
};
//Unknown,1,255),
prompt* UNKNMenu_data[]={
  MK_FIELD("PRM_REVERB_D0",REVERB_D0,1,255),
  MK_FIELD("PRM_REVERB_D1",REVERB_D1,1,255),
  MK_FIELD("PRM_REVERB_D2",REVERB_D2,1,255),
  MK_FIELD("PRM_FIR_IMPULSE",FIR_IMPULSE,1,255),
  &back
};
//FX Routing,1,255),
prompt* FXRMenu_data[]={
  MK_FIELD("Effects Routing",FX_ROUTING,0,1), // Bitcrusher → Decimator → Filter → Chorus → Phaser → AM → Delay or  1 = Bitcrusher → Decimator → Filter → Delay → Chorus → Phaser → AM
  &back
};
//Performance Controls,1,255),
prompt* PERFMenu_data[]={
  MK_FIELD("Set Performance Control 70",CONTROL_1H,1,255), // These are strange
  MK_FIELD("Set Performance Control 70",CONTROL_1L,1,255),
  MK_FIELD("Set Performance Control 71",CONTROL_2H,1,255),
  MK_FIELD("Set Performance Control 71",CONTROL_2L,1,255),
  MK_FIELD("Set Performance Control 72",CONTROL_3H,1,255),
  MK_FIELD("Set Performance Control 72",CONTROL_3L,1,255),
  MK_FIELD("Set Performance Control 73",CONTROL_4H,1,255),
  MK_FIELD("Set Performance Control 73",CONTROL_4L,1,255),
  &back
};
//Arpeggiator,1,255),
prompt* ARPMenu_data[]={
  MK_FIELD("Arpeggiator Mode",ARP_MODE,0,5), // 0 = off, 1 = Up, 2 = Down, 3 = Up/Down, 4 = As played, 5 = Random
  MK_FIELD("ARP Tempo",ARP_TEMPO,0,255), // 0 = MIDI Clock Tempo, 50-255 is the range
  MK_FIELD("APR Tempo (fine)",ARP_TEMPO_FINE,1,255),
  MK_FIELD("Division",ARP_DIVISION,1,255),
  MK_FIELD("Octaves",ARP_OCTAVES,1,255),
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