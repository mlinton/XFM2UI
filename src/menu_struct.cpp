#include "menu_struct.h"
#include "menu_funcs.h"

#define MK_FIELD(title,var,low,high) new menuField<typeof(var)>(var,title,"",0,255,1,0,Param<PRM_##var>::set,enterEvent)

Exit back("<Back");

  // Operator Menu,0,255),
prompt* OPMenu_data[]={
  MK_FIELD("Oscillator Syncronization",OSC_SYNC,0,255), // bitwise setting 13
  MK_FIELD("Oscillator Mode",OSC_MODE,0,255), // 0 or 1 setting 14
  MK_FIELD("Amplitude EG Loop",EG_LOOP,0,255), // bitwise setting 244
  MK_FIELD("DESCRIPTION",EG_LOOP_SEG,0,255), // bitwise setting 245
  &back
};
  // Operator 1 (0),0,255)
prompt* OPSMenu_data[]={
  MK_FIELD("Op 1 Algo",ALGO0,0,255), // bitwise setting
  MK_FIELD("Op 2 Algo",ALGO1,0,255), // bitwise setting
  MK_FIELD("Op 3 Algo",ALGO2,0,255), // bitwise setting
  MK_FIELD("Op 4 Algo",ALGO3,0,255), // bitwise setting
  MK_FIELD("Op 5 Algo",ALGO4,0,255), // bitwise setting
  MK_FIELD("Op 6 Algo",ALGO5,0,255), // bitwise setting
  MK_FIELD("Op 1 FB Level",FEEDBACK0,0,255),
  MK_FIELD("Op 2 FB Level",FEEDBACK1,0,255),
  MK_FIELD("Op 3 FB Level",FEEDBACK2,0,255),
  MK_FIELD("Op 4 FB Level",FEEDBACK3,0,255),
  MK_FIELD("Op 5 FB Level",FEEDBACK4,0,255),
  MK_FIELD("Op 6 FB Level",FEEDBACK5,0,255),
  MK_FIELD("Pitch Ratio",RATIO0,0,255),
  MK_FIELD("Pitch Ratio",RATIO1,0,255),
  MK_FIELD("Pitch Ratio",RATIO2,0,255),
  MK_FIELD("Pitch Ratio",RATIO3,0,255),
  MK_FIELD("Pitch Ratio",RATIO4,0,255),
  MK_FIELD("Pitch Ratio",RATIO5,0,255),
  MK_FIELD("Fine Ratio",RATIO_FINE0,0,255),
  MK_FIELD("Fine Ratio",RATIO_FINE1,0,255),
  MK_FIELD("Fine Ratio",RATIO_FINE2,0,255),
  MK_FIELD("Fine Ratio",RATIO_FINE3,0,255),
  MK_FIELD("Fine Ratio",RATIO_FINE4,0,255),
  MK_FIELD("Fine Ratio",RATIO_FINE5,0,255),
  MK_FIELD("Operator Pitch",FINE0,0,255),
  MK_FIELD("Operator Pitch",FINE1,0,255),
  MK_FIELD("Operator Pitch",FINE2,0,255),
  MK_FIELD("Operator Pitch",FINE3,0,255),
  MK_FIELD("Operator Pitch",FINE4,0,255),
  MK_FIELD("Operator Pitch",FINE5,0,255),
  MK_FIELD("Output Level",LEVEL0,0,255),
  MK_FIELD("Output Level",LEVEL1,0,255),
  MK_FIELD("Output Level",LEVEL2,0,255),
  MK_FIELD("Output Level",LEVEL3,0,255),
  MK_FIELD("Output Level",LEVEL4,0,255),
  MK_FIELD("Output Level",LEVEL5,0,255),
  MK_FIELD("Velo Sens",VEL_SENS0,0,255),
  MK_FIELD("Velo Sens",VEL_SENS1,0,255),
  MK_FIELD("Velo Sens",VEL_SENS2,0,255),
  MK_FIELD("Velo Sens",VEL_SENS3,0,255),
  MK_FIELD("Velo Sens",VEL_SENS4,0,255),
  MK_FIELD("Velo Sens",VEL_SENS5,0,255),
  MK_FIELD("Kbd Break",KEY_BP0,0,255),
  MK_FIELD("Kbd Break",KEY_BP1,0,255),
  MK_FIELD("Kbd Break",KEY_BP2,0,255),
  MK_FIELD("Kbd Break",KEY_BP3,0,255),
  MK_FIELD("Kbd Break",KEY_BP4,0,255),
  MK_FIELD("Kbd Break",KEY_BP5,0,255),
  MK_FIELD("Scale Dep Left",KEY_LDEPTH0,0,255),
  MK_FIELD("Scale Dep Left",KEY_LDEPTH1,0,255),
  MK_FIELD("Scale Dep Left",KEY_LDEPTH2,0,255),
  MK_FIELD("Scale Dep Left",KEY_LDEPTH3,0,255),
  MK_FIELD("Scale Dep Left",KEY_LDEPTH4,0,255),
  MK_FIELD("Scale Dep Left",KEY_LDEPTH5,0,255),
  MK_FIELD("Scale Dep Right",KEY_RDEPTH0,0,255),
  MK_FIELD("Scale Dep Right",KEY_RDEPTH1,0,255),
  MK_FIELD("Scale Dep Right",KEY_RDEPTH2,0,255),
  MK_FIELD("Scale Dep Right",KEY_RDEPTH3,0,255),
  MK_FIELD("Scale Dep Right",KEY_RDEPTH4,0,255),
  MK_FIELD("Scale Dep Right",KEY_RDEPTH5,0,255),
  MK_FIELD("Left Bp Curve",KEY_LCURVE0,1,3),
  MK_FIELD("Left Bp Curve",KEY_LCURVE1,1,3),
  MK_FIELD("Left Bp Curve",KEY_LCURVE2,1,3),
  MK_FIELD("Left Bp Curve",KEY_LCURVE3,1,3),
  MK_FIELD("Left Bp Curve",KEY_LCURVE4,1,3),
  MK_FIELD("Left Bp Curve",KEY_LCURVE5,1,3),
  MK_FIELD("Right Bp Curve",KEY_RCURVE0,1,3),
  MK_FIELD("Right Bp Curve",KEY_RCURVE1,1,3),
  MK_FIELD("Right Bp Curve",KEY_RCURVE2,1,3),
  MK_FIELD("Right Bp Curve",KEY_RCURVE3,1,3),
  MK_FIELD("Right Bp Curve",KEY_RCURVE4,1,3),
  MK_FIELD("Right Bp Curve",KEY_RCURVE5,1,3),
  MK_FIELD("EG2 Lt- Decay 1",L1_0,0,255),
  MK_FIELD("EG2 Lt- Decay 1",L1_1,0,255),
  MK_FIELD("EG2 Lt- Decay 1",L1_2,0,255),
  MK_FIELD("EG2 Lt- Decay 1",L1_3,0,255),
  MK_FIELD("EG2 Lt- Decay 1",L1_4,0,255),
  MK_FIELD("EG2 Lt- Decay 1",L1_5,0,255),
  MK_FIELD("EG3 Lt- Decay 2",L2_0,0,255),
  MK_FIELD("EG3 Lt- Decay 2",L2_1,0,255),
  MK_FIELD("EG3 Lt- Decay 2",L2_2,0,255),
  MK_FIELD("EG3 Lt- Decay 2",L2_3,0,255),
  MK_FIELD("EG3 Lt- Decay 2",L2_4,0,255),
  MK_FIELD("EG3 Lt- Decay 2",L2_5,0,255),
  MK_FIELD("EG4 Lt- Sustain",L3_0,0,255),
  MK_FIELD("EG4 Lt- Sustain",L3_1,0,255),
  MK_FIELD("EG4 Lt- Sustain",L3_2,0,255),
  MK_FIELD("EG4 Lt- Sustain",L3_3,0,255),
  MK_FIELD("EG4 Lt- Sustain",L3_4,0,255),
  MK_FIELD("EG4 Lt- Sustain",L3_5,0,255),
  MK_FIELD("EG3 Lt- Release 1",L4_0,0,255),
  MK_FIELD("EG3 Lt- Release 1",L4_1,0,255),
  MK_FIELD("EG3 Lt- Release 1",L4_2,0,255),
  MK_FIELD("EG3 Lt- Release 1",L4_3,0,255),
  MK_FIELD("EG3 Lt- Release 1",L4_4,0,255),
  MK_FIELD("EG3 Lt- Release 1",L4_5,0,255),
  MK_FIELD("EG2 Rt - Decay 1",R1_0,0,255),
  MK_FIELD("EG2 Rt - Decay 1",R1_1,0,255),
  MK_FIELD("EG2 Rt - Decay 1",R1_2,0,255),
  MK_FIELD("EG2 Rt - Decay 1",R1_3,0,255),
  MK_FIELD("EG2 Rt - Decay 1",R1_4,0,255),
  MK_FIELD("EG2 Rt - Decay 1",R1_5,0,255),
  MK_FIELD("EG3 Rt - Decay 2",R2_0,0,255),
  MK_FIELD("EG3 Rt - Decay 2",R2_1,0,255),
  MK_FIELD("EG3 Rt - Decay 2",R2_2,0,255),
  MK_FIELD("EG3 Rt - Decay 2",R2_3,0,255),
  MK_FIELD("EG3 Rt - Decay 2",R2_4,0,255),
  MK_FIELD("EG3 Rt - Decay 2",R2_5,0,255),
  MK_FIELD("EG4 Rt - Sustain",R3_0,0,255),
  MK_FIELD("EG4 Rt - Sustain",R3_1,0,255),
  MK_FIELD("EG4 Rt - Sustain",R3_2,0,255),
  MK_FIELD("EG4 Rt - Sustain",R3_3,0,255),
  MK_FIELD("EG4 Rt - Sustain",R3_4,0,255),
  MK_FIELD("EG4 Rt - Sustain",R3_5,0,255),
  MK_FIELD("EG5 Rt - Release 1",R4_0,0,255),
  MK_FIELD("EG5 Rt - Release 1",R4_1,0,255),
  MK_FIELD("EG5 Rt - Release 1",R4_2,0,255),
  MK_FIELD("EG5 Rt - Release 1",R4_3,0,255),
  MK_FIELD("EG5 Rt - Release 1",R4_4,0,255),
  MK_FIELD("EG5 Rt - Release 1",R4_5,0,255),
  MK_FIELD("EG1 Lt- Attack",L0_0,0,255),
  MK_FIELD("EG1 Lt- Attack",L0_1,0,255),
  MK_FIELD("EG1 Lt- Attack",L0_2,0,255),
  MK_FIELD("EG1 Lt- Attack",L0_3,0,255),
  MK_FIELD("EG1 Lt- Attack",L0_4,0,255),
  MK_FIELD("EG1 Lt- Attack",L0_5,0,255),
  MK_FIELD("EG1 Rt - Attack",R0_0,0,255),
  MK_FIELD("EG1 Rt - Attack",R0_1,0,255),
  MK_FIELD("EG1 Rt - Attack",R0_2,0,255),
  MK_FIELD("EG1 Rt - Attack",R0_3,0,255),
  MK_FIELD("EG1 Rt - Attack",R0_4,0,255),
  MK_FIELD("EG1 Rt - Attack",R0_5,0,255),
  MK_FIELD("EG6 Lt- Release 2",L5_0,0,255),
  MK_FIELD("EG6 Lt- Release 2",L5_1,0,255),
  MK_FIELD("EG6 Lt- Release 2",L5_2,0,255),
  MK_FIELD("EG6 Lt- Release 2",L5_3,0,255),
  MK_FIELD("EG6 Lt- Release 2",L5_4,0,255),
  MK_FIELD("EG6 Lt- Release 2",L5_5,0,255),
  MK_FIELD("EG6 Rt - Release 2",R5_1,0,255),
  MK_FIELD("EG6 Rt - Release 2",R5_0,0,255),
  MK_FIELD("EG6 Rt - Release 2",R5_2,0,255),
  MK_FIELD("EG6 Rt - Release 2",R5_3,0,255),
  MK_FIELD("EG6 Rt - Release 2",R5_4,0,255),
  MK_FIELD("EG6 Rt - Release 2",R5_5,0,255),
  MK_FIELD("Amp1 LFO",LFO_AMS0,0,255),
  MK_FIELD("Amp2 LFO",LFO_AMS1,0,255),
  MK_FIELD("Amp3 LFO",LFO_AMS2,0,255),
  MK_FIELD("Amp4 LFO",LFO_AMS3,0,255),
  MK_FIELD("Amp5 LFO",LFO_AMS4,0,255),
  MK_FIELD("Amp6 LFO",LFO_AMS5,0,255),
  MK_FIELD("Pitch LFO 1",LFO_PMS0,0,255),
  MK_FIELD("Pitch LFO 2",LFO_PMS1,0,255),
  MK_FIELD("Pitch LFO 3",LFO_PMS2,0,255),
  MK_FIELD("Pitch LFO 4",LFO_PMS3,0,255),
  MK_FIELD("Pitch LFO 5",LFO_PMS4,0,255),
  MK_FIELD("Pitch LFO 6",LFO_PMS5,0,255),
  MK_FIELD("OSC1 Waveform 0",WAVEFORM0,0,7),
  MK_FIELD("OSC1 Waveform 1",WAVEFORM1,0,7),
  MK_FIELD("OSC1 Waveform 2",WAVEFORM2,0,7),
  MK_FIELD("OSC1 Waveform 3",WAVEFORM3,0,7),
  MK_FIELD("OSC1 Waveform 4",WAVEFORM4,0,7),
  MK_FIELD("OSC1 Waveform 5",WAVEFORM5,0,7),
  MK_FIELD("Op1 Level - Left",LEVEL0_L,0,255),
  MK_FIELD("Op1 Level - Right",LEVEL0_R,0,255),
  MK_FIELD("Op2 Level - Left",LEVEL1_L,0,255),
  MK_FIELD("Op2 Level - Right",LEVEL1_R,0,255),
  MK_FIELD("Op3 Level - Left",LEVEL2_L,0,255),
  MK_FIELD("Op3 Level - Right",LEVEL2_R,0,255),
  MK_FIELD("Op4 Level - Left",LEVEL3_L,0,255),
  MK_FIELD("Op4 Level - Right",LEVEL3_R,0,255),
  MK_FIELD("Op5 Level - Left",LEVEL4_L,0,255),
  MK_FIELD("Op5 Level - Right",LEVEL4_R,0,255),
  MK_FIELD("Op6 Level - Left",LEVEL5_L,0,255),
  MK_FIELD("Op6 Level - Right",LEVEL5_R,0,255),
  MK_FIELD("OSC2 Wform 1",WAVEFORM2_0,0,7),
  MK_FIELD("OSC2 Wform 2",WAVEFORM2_1,0,7),
  MK_FIELD("OSC2 Wform 3",WAVEFORM2_2,0,7),
  MK_FIELD("OSC2 Wform 4",WAVEFORM2_3,0,7),
  MK_FIELD("OSC2 Wform 5",WAVEFORM2_4,0,7),
  MK_FIELD("OSC2 Wform 6",WAVEFORM2_5,0,7),
  MK_FIELD("Waveform1 Mode",WMODE0,0,1),
  MK_FIELD("Waveform2 Mode",WMODE1,0,1),
  MK_FIELD("Waveform3 Mode",WMODE2,0,1),
  MK_FIELD("Waveform4 Mode",WMODE3,0,1),
  MK_FIELD("Waveform5 Mode",WMODE4,0,1),
  MK_FIELD("Waveform6 Mode",WMODE5,0,1),
  MK_FIELD("Waveform1 Ratio",WRATIO0,0,255),
  MK_FIELD("Waveform2 Ratio",WRATIO1,0,255),
  MK_FIELD("Waveform3 Ratio",WRATIO2,0,255),
  MK_FIELD("Waveform4 Ratio",WRATIO3,0,255),
  MK_FIELD("Waveform5 Ratio",WRATIO4,0,255),
  MK_FIELD("Waveform6 Ratio",WRATIO5,0,255),
  MK_FIELD("Osc1 Phase",OSC_PHASE0,0,3),
  MK_FIELD("Osc2 Phase",OSC_PHASE1,0,3),
  MK_FIELD("Osc3 Phase",OSC_PHASE2,0,3),
  MK_FIELD("Osc4 Phase",OSC_PHASE3,0,3),
  MK_FIELD("Osc5 Phase",OSC_PHASE4,0,3),
  MK_FIELD("Osc6 Phase",OSC_PHASE5,0,3),
  &back
};
  //Program Menu,0,255),
  prompt* PEGMenu_data[]={
  MK_FIELD("Pitch Range Oct",EG_PITCH_RANGE,0,255),
  MK_FIELD("Midi Pitch Vel",EG_PITCH_RANGE_VELO,0,255),
  MK_FIELD("EG Pitch Rate Key",RATE_KEYP,0,255),
  MK_FIELD("EG - Left Attack",L0_P,0,255),
  MK_FIELD("EG - Right Attack ",R0_P,0,255),
  MK_FIELD("EG - Left Release 2",L5_P,0,255),
  MK_FIELD("EG - Right Release 2 ",R5_P,0,255),
  MK_FIELD("EG - Left Decay ",L1_P,0,255),
  MK_FIELD("EG - Left Decay 2",L2_P,0,255),
  MK_FIELD("EG - Left Sustain",L3_P,0,255),
  MK_FIELD("EG - Left Relase ",L4_P,0,255),
  MK_FIELD("EG - Right Decay ",R1_P,0,255),
  MK_FIELD("EG - Right Decay 2 ",R2_P,0,255),
  MK_FIELD("EG - Right Sustain ",R3_P,0,255),
  MK_FIELD("EG - Right Release ",R4_P,0,255),
  &back
};

prompt* LFO_SYNC_values[]={
  new menuValue<typeof(LFO_SYNC)>("Single free",0),
  new menuValue<typeof(LFO_SYNC)>("Single key",1),
  new menuValue<typeof(LFO_SYNC)>("Multi free",2),
  new menuValue<typeof(LFO_SYNC)>("Multi key",3),
  new menuValue<typeof(LFO_SYNC)>("N/A",100)
};
prompt* LFO_WAVE_values[]={
  new menuValue<typeof(LFO_WAVE)>("Triangle",0),
  new menuValue<typeof(LFO_WAVE)>("Square",1),
  new menuValue<typeof(LFO_WAVE)>("Saw Up",2),
  new menuValue<typeof(LFO_WAVE)>("Saw Down",3),
  new menuValue<typeof(LFO_WAVE)>("Sine",4),
  new menuValue<typeof(LFO_WAVE)>("Random",5),
  new menuValue<typeof(LFO_WAVE)>("N/A",100)
};
  //LFO Menu,0,255),
prompt* LFOMenu_data[]={
  MK_FIELD("LFO Effect Applied to Pitch",LFO_PITCH_DEPTH,0,255),
  MK_FIELD("LFO Effect Applied to Amplitude",LFO_AMP_DEPTH,0,255),
  MK_FIELD("LFO Speed",LFO_SPEED,0,255),
  new toggle<typeof(LFO_SYNC)>("Sync: ",LFO_SYNC,sizeof(LFO_SYNC_values)/sizeof(prompt*),LFO_SYNC_values,Param<PRM_LFO_SYNC>::set,enterEvent),
  new toggle<typeof(LFO_WAVE)>("Waveform: ",LFO_WAVE,sizeof(LFO_WAVE_values)/sizeof(prompt*),LFO_WAVE_values,Param<PRM_LFO_WAVE>::set,enterEvent),
  MK_FIELD("Fade",LFO_FADE,0,255),
  &back
};
  //Pitch LFO,0,255),
prompt* PMenu_data[]={
  MK_FIELD("Breath",LFO_PITCH_DEPTH_BREATH,0,255),
  MK_FIELD("Wheel Controller",LFO_PITCH_DEPTH_WHEEL,0,255),
  MK_FIELD("Foot Controller",LFO_PITCH_DEPTH_FOOT,0,255),
  MK_FIELD("Aftertouch",LFO_PITCH_DEPTH_AFTER,0,255),
  &back
};
  //Amp LFO,0,255),
prompt* AMLFOMenu_data[]={
  MK_FIELD("Breath",LFO_AMP_DEPTH_BREATH,0,255),
  MK_FIELD("Wheel Controller",LFO_AMP_DEPTH_WHEEL,0,255),
  MK_FIELD("Foot Controller",LFO_AMP_DEPTH_FOOT,0,255),
  MK_FIELD("Aftertouch",LFO_AMP_DEPTH_AFTER,0,255),
  &back
};
  //Eg bias,0,255),
prompt* EGMenu_data[]={
  MK_FIELD("Aftertouch",VOLUME_DEPTH_AFTER,0,255),
  MK_FIELD("Wheel Controller",VOLUME_DEPTH_WHEEL,0,255),
  MK_FIELD("Breath",VOLUME_DEPTH_BREATH,0,255),
  MK_FIELD("Foot Controller",VOLUME_DEPTH_FOOT,0,255),
  &back
};
  //Pitch Depth,0,255),
prompt* PLFOMenu_data[]={
  MK_FIELD("Aftertouch",PITCH_DEPTH_AFTER,0,255),
  MK_FIELD("Breath",PITCH_DEPTH_BREATH,0,255),
  MK_FIELD("Foot Controller",PITCH_DEPTH_FOOT,0,255),
  MK_FIELD("Random",PITCH_DEPTH_RND,0,255),
  &back
};
  //Other,0,255),

prompt* LEGATO_values[]={
  new menuValue<typeof(LEGATO)>("Polyphonic",0),
  new menuValue<typeof(LEGATO)>("Monophonic",1),
  new menuValue<typeof(LEGATO)>("N/A",255)
};
prompt* PORTA_MODE_values[]={
  new menuValue<typeof(PORTA_MODE)>("Off",0),
  new menuValue<typeof(PORTA_MODE)>("Always",1),
  new menuValue<typeof(PORTA_MODE)>("Fingered",2),
  new menuValue<typeof(PORTA_MODE)>("N/A",255)
};
prompt* GAIN_LEVEL_values[]={
  new menuValue<typeof(GAIN_LEVEL)>("Default",0),
  new menuValue<typeof(GAIN_LEVEL)>("+3db",1),
  new menuValue<typeof(GAIN_LEVEL)>("+6db",2),
  new menuValue<typeof(GAIN_LEVEL)>("+9db",3)
};

prompt* OTHERMenu_data[]={
  MK_FIELD("Pitch Bend Range Up",BEND_RANGE_UP,0,255),
  MK_FIELD("Pitch Bend Range Down",BEND_RANGE_DN,0,255),
  MK_FIELD("Transpose",TRANSPOSE,0,255),  //Center value is 24
  MK_FIELD("Overall Voice Mix Volume",VOLUME,0,255),
  MK_FIELD("Voice Mix Pan",PAN,0,255),
  // MK_FIELD("Legato Mode",LEGATO,0,1), // Polyphonic or Monophonic
  new toggle<typeof(LEGATO)>("Legato Mode: ",LEGATO,sizeof(LEGATO_values)/sizeof(prompt*),LEGATO_values,Param<PRM_LEGATO>::set,enterEvent),
  // MK_FIELD("Portamento Mode",PORTA_MODE,0,3), // 0 off, 1 Always, 2 Fingered
  new toggle<typeof(PORTA_MODE)>("Porta Mode: ",PORTA_MODE,sizeof(PORTA_MODE_values)/sizeof(prompt*),PORTA_MODE_values,Param<PRM_PORTA_MODE>::set,enterEvent),
  MK_FIELD("Portamento Time",PORTA_TIME,0,255),
  MK_FIELD("Velocity Offset",VELO_OFFSET,0,255),
  MK_FIELD("Velocity Curve",VELO_CURVE,0,255),
  MK_FIELD("Envelope Generator Restart",EG_RESTART,0,255),
  MK_FIELD("Selected Tuning",TUNING,0,255), // list is a list from the tuning file scl
  MK_FIELD("Output Lvl",OUTPUT_LEVEL,0,255),
  // MK_FIELD("Overall Output Level",OUTPUT_LEVEL,0,3),  // output gain setting.  0 - none, 1 - 3db, 2 - 6db, 3 - 9db
  new toggle<typeof(GAIN_LEVEL)>("Gain Lvl: ",GAIN_LEVEL,sizeof(GAIN_LEVEL_values)/sizeof(prompt*),GAIN_LEVEL_values,Param<PRM_GAIN_LEVEL>::set,enterEvent),
  &back
};

prompt* SDLY_MODE_values[]={
  new menuValue<typeof(SDLY_MODE)>("Stereo",0),
  new menuValue<typeof(SDLY_MODE)>("Cross",1),
  new menuValue<typeof(SDLY_MODE)>("Ping Pong",2)
};
  //Delay ,0,255),
prompt* DLYMenu_data[]={
  MK_FIELD("Dry Level",SDLY_DRY,0,255),
  MK_FIELD("Wet Level",SDLY_WET,0,255),
  // MK_FIELD("Mode",SDLY_MODE,0,2), // 0 - Stereo, 1 - Cross, 2 - Ping Pong
  new toggle<typeof(SDLY_MODE)>("Mode: ",SDLY_MODE,sizeof(SDLY_MODE_values)/sizeof(prompt*),SDLY_MODE_values,Param<PRM_SDLY_MODE>::set,enterEvent),
  MK_FIELD("Time",SDLY_TIME,0,255), // 0 tracks with the TEMPO setting
  MK_FIELD("Feedback",SDLY_FEEDBACK,0,255),
  MK_FIELD("Low Pass Filter",SDLY_FEEDLO,0,255),
  MK_FIELD("High Pass Filter",SDLY_FEEDHI,0,255),
  MK_FIELD("Delay Tempo BPM (50-255)",SDLY_TEMPO,50,255),
  MK_FIELD("Tempo Multiplier",SDLY_NUM,0,255),
  MK_FIELD("Tempo Divider",SDLY_DEN,0,255),
  &back
};
prompt* PHASER_MODE_values[]={
  new menuValue<typeof(PHASER_MODE)>("Mono",0),
  new menuValue<typeof(PHASER_MODE)>("Stereo",1),
  new menuValue<typeof(PHASER_MODE)>("Cross",2)
};
//Phaser,0,255),
prompt* PHMenu_data[]={
  MK_FIELD("Dry Level",PHASER_DRY,0,255),
  MK_FIELD("Wet Level",PHASER_WET,0,255),
  // MK_FIELD("Mode",PHASER_MODE,0,2), // 0 - Mono, 1 - Stereo, 2 - Cross
  new toggle<typeof(PHASER_MODE)>("Mode: ",PHASER_MODE,sizeof(PHASER_MODE_values)/sizeof(prompt*),PHASER_MODE_values,Param<PRM_PHASER_MODE>::set,enterEvent),
  MK_FIELD("Depth",PHASER_DEPTH,0,255),
  MK_FIELD("Speed",PHASER_SPEED,0,255),
  MK_FIELD("Feedback",PHASER_FEEDBACK,0,255),
  MK_FIELD("Offset",PHASER_OFFSET,0,255),
  MK_FIELD("Stages 4 - 12",PHASER_STAGES,4,12),  // not sure of the range here
  MK_FIELD("Left/Right Phase",PHASER_PHASE,0,255), // 128 is middle
  MK_FIELD("Waveform",PHASER_WAVEFORM,0,255),
  &back
};
//Amplitude Modulation,0,255),
prompt* AMMenu_data[]={
  MK_FIELD("Speed",AM_SPEED,0,255),
  MK_FIELD("Range",AM_RANGE,0,255),
  MK_FIELD("Depth",AM_DEPTH,0,255),
  MK_FIELD("Left/Right Phase",AM_PHASE,0,255), //128 is the middle
  &back
};
//Waveshaper,0,255),
prompt* WSMenu_data[]={
  MK_FIELD("Dry Level",WAVESHAPER_DRY,0,255),
  MK_FIELD("Wet Level",WAVESHAPER_WET,0,255),
  MK_FIELD("Pre-Gain",WAVESHAPER_GAIN_PRE,0,255),
  MK_FIELD("Post-Gain",WAVESHAPER_GAIN_POST,0,255),
  MK_FIELD("Shape",WAVESHAPER_SHAPE,0,255),
  &back
};
prompt* CHORUS_MODE_values[]={
  new menuValue<typeof(CHORUS_MODE)>("Long",0),
  new menuValue<typeof(CHORUS_MODE)>("Short",1),
  new menuValue<typeof(CHORUS_MODE)>("Long Flange",2),
  new menuValue<typeof(CHORUS_MODE)>("Short Flange",3)
};
//Chorus Menu,0,255),
prompt* CHORUSMenu_data[]={
  MK_FIELD("Dry Level",CHORUS_DRY,0,255),
  MK_FIELD("Wet Level",CHORUS_WET,0,255),
  //MK_FIELD("Mode",CHORUS_MODE,0,3), // 0 - Long Chorus, 1 - Short Chorus, 2 - Long Flanger, 3 - Short Flanger
  new toggle<typeof(CHORUS_MODE)>("Mode: ",CHORUS_MODE,sizeof(CHORUS_MODE_values)/sizeof(prompt*),CHORUS_MODE_values,Param<PRM_CHORUS_MODE>::set,enterEvent),
  MK_FIELD("Speed",CHORUS_SPEED,0,255),
  MK_FIELD("Depth",CHORUS_DEPTH,0,255),
  MK_FIELD("Feedback",CHORUS_FEEDBACK,0,255),
  MK_FIELD("Left/Right Phase",CHORUS_PHASE,0,255), //128 is the middle
  &back
};
//Other Effects Menu,0,255),
prompt* OEMenu_data[]={
  MK_FIELD("Decimator Depth",DECIMATOR_DEPTH,0,255),
  MK_FIELD("Bitcrusher Depth",BITCRUSHER_DEPTH,0,255),
  MK_FIELD("Lo-Pass Filter Cutoff",FILTER_LO,0,255),
  MK_FIELD("High-Pass Filter Cutoff",FILTER_HI,0,255),
  &back
};
prompt* REVERB_MODE_values[]={
  new menuValue<typeof(REVERB_MODE)>("Plate",0),
  new menuValue<typeof(REVERB_MODE)>("Hall",1)
};
//Global Reverb,0,255),
prompt* RVBMenu_data[]={
  MK_FIELD("Dry Level",REVERB_DRY,0,255),
  MK_FIELD("Wet Level",REVERB_WET,0,255),
  // MK_FIELD("Mode",REVERB_MODE,0,1), // 0 - Plate, 1 - Hall
  new toggle<typeof(REVERB_MODE)>("Mode: ",REVERB_MODE,sizeof(REVERB_MODE_values)/sizeof(prompt*),REVERB_MODE_values,Param<PRM_REVERB_MODE>::set,enterEvent),
  MK_FIELD("Decay Time",REVERB_DECAY,0,255),
  MK_FIELD("HiFreq Dampening",REVERB_DAMP,0,255),
  &back
};
//Unknown,0,255),
prompt* UNKNMenu_data[]={
  MK_FIELD("PRM_REVERB_D0",REVERB_D0,0,255),
  MK_FIELD("PRM_REVERB_D1",REVERB_D1,0,255),
  MK_FIELD("PRM_REVERB_D2",REVERB_D2,0,255),
  MK_FIELD("PRM_FIR_IMPULSE",FIR_IMPULSE,0,255),
  &back
};
prompt* FX_ROUTING_values[]={
  new menuValue<typeof(FX_ROUTING)>("B-D-F-C-P-A-D",0),
  new menuValue<typeof(FX_ROUTING)>("B-D-F-D-C-P-A",1)
};
//FX Routing,0,255),
prompt* FXRMenu_data[]={
  // MK_FIELD("Effects Routing",FX_ROUTING,0,1), // Bitcrusher → Decimator → Filter → Chorus → Phaser → AM → Delay or  1 = Bitcrusher → Decimator → Filter → Delay → Chorus → Phaser → AM
  new toggle<typeof(FX_ROUTING)>("Mode: ",FX_ROUTING,sizeof(FX_ROUTING_values)/sizeof(prompt*),FX_ROUTING_values,Param<PRM_FX_ROUTING>::set,enterEvent),
  &back
};
//Performance Controls,0,255),
prompt* PERFMenu_data[]={
  MK_FIELD("Set CC 70",CONTROL_1H,0,255), // These are strange
  MK_FIELD("Set CC 70",CONTROL_1L,0,255),
  MK_FIELD("Set CC 71",CONTROL_2H,0,255),
  MK_FIELD("Set CC 71",CONTROL_2L,0,255),
  MK_FIELD("Set CC 72",CONTROL_3H,0,255),
  MK_FIELD("Set CC 72",CONTROL_3L,0,255),
  MK_FIELD("Set CC 73",CONTROL_4H,0,255),
  MK_FIELD("Set CC 73",CONTROL_4L,0,255),
  &back
};
prompt* ARP_MODE_values[]={
  new menuValue<typeof(ARP_MODE)>("OFF",0),
  new menuValue<typeof(ARP_MODE)>("UP",1),
  new menuValue<typeof(ARP_MODE)>("Down",2),
  new menuValue<typeof(ARP_MODE)>("Up/Down",3),
  new menuValue<typeof(ARP_MODE)>("As Played",4),
  new menuValue<typeof(ARP_MODE)>("Random",5)
};
//Arpeggiator,0,255),
prompt* ARPMenu_data[]={
  // MK_FIELD("Arpeggiator Mode",ARP_MODE,0,5), // 0 = off, 1 = Up, 2 = Down, 3 = Up/Down, 4 = As played, 5 = Random
  new toggle<typeof(ARP_MODE)>("Mode: ",ARP_MODE,sizeof(ARP_MODE_values)/sizeof(prompt*),ARP_MODE_values,Param<PRM_ARP_MODE>::set,enterEvent),
  MK_FIELD("ARP Tempo",ARP_TEMPO,0,255), // 0 = MIDI Clock Tempo, 50-255 is the range
  MK_FIELD("APR Tempo (fine)",ARP_TEMPO_FINE,0,255),
  MK_FIELD("Division",ARP_DIVISION,0,255),
  MK_FIELD("Octaves",ARP_OCTAVES,0,255),
  &back
};

//Presets,0,255),
prompt* PRESMenu_data[]={
  // new menuField<decltype(program)>(program,"Program","#",0,127,1,0,get_program,enterEvent,noStyle),
  &back
};

menuNode PRESMenu("Preset Menu",sizeof(PRESMenu_data)/sizeof(prompt*),PRESMenu_data);
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

prompt* mainMenu_data[]={&oprMenu,&PRESMenu,&progMenu,&modMenu,&effMenu,&back};
menuNode mainMenu("XFM2UI",sizeof(mainMenu_data)/sizeof(prompt*),mainMenu_data);
