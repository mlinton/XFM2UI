//  This file should really contain the definitions for each parameter
//  for each param
//      set param(name, description, range, value)
//      e.g. set param(PRM_ALGO0,"Algorythm 0", 0-255, 0)
//  This will allow for recall and setting of the paramters and display within a menu system
//      create_menu(param)
//  Need some way of defining a nested menu structure or references to the ordering of the menu items

// struct XFM_params {
//     string name;
//     int param_num;
//     int param_value;
// }

// Define other values (globals)
// #define MIDI_Channel_0              * 10 // 0 (omni) or 1 - 16
// #define MIDI_Channel_1              * 11 // 0 (omni) or 1 - 16
// #define LAYER_MODE                  * 12 // 0 Off or 1 On
#define PRM_ALGO0                   001 // binary based on LSB
#define PRM_ALGO1                   002 // binary based on LSB
#define PRM_ALGO2                   003 // binary based on LSB
#define PRM_ALGO3                   004 // binary based on LSB
#define PRM_ALGO4                   005 // binary based on LSB
#define PRM_ALGO5                   006 // binary based on LSB
#define PRM_FEEDBACK0               007
#define PRM_FEEDBACK1               008
#define PRM_FEEDBACK2               009
#define PRM_FEEDBACK3               010
#define PRM_FEEDBACK4               011
#define PRM_FEEDBACK5               012
#define PRM_OSC_SYNC                013 // bitwise parameter to set each operator to free-run (0) or note-on (1)
#define PRM_OSC_MODE                014 // binary based on LSB
#define PRM_RATIO0                  015
#define PRM_RATIO1                  016
#define PRM_RATIO2                  017
#define PRM_RATIO3                  018
#define PRM_RATIO4                  019
#define PRM_RATIO5                  020
#define PRM_RATIO_FINE0             021
#define PRM_RATIO_FINE1             022
#define PRM_RATIO_FINE2             023
#define PRM_RATIO_FINE3             024
#define PRM_RATIO_FINE4             025
#define PRM_RATIO_FINE5             026
#define PRM_FINE0                   027
#define PRM_FINE1                   028
#define PRM_FINE2                   029
#define PRM_FINE3                   030
#define PRM_FINE4                   031
#define PRM_FINE5                   032
#define PRM_LEVEL0                  033
#define PRM_LEVEL1                  034
#define PRM_LEVEL2                  035
#define PRM_LEVEL3                  036
#define PRM_LEVEL4                  037
#define PRM_LEVEL5                  038
#define PRM_VEL_SENS0               039
#define PRM_VEL_SENS1               040
#define PRM_VEL_SENS2               041
#define PRM_VEL_SENS3               042
#define PRM_VEL_SENS4               043
#define PRM_VEL_SENS5               044
#define PRM_KEY_BP0                 045
#define PRM_KEY_BP1                 046
#define PRM_KEY_BP2                 047
#define PRM_KEY_BP3                 048
#define PRM_KEY_BP4                 049
#define PRM_KEY_BP5                 050
#define PRM_KEY_LDEPTH0             051
#define PRM_KEY_LDEPTH1             052
#define PRM_KEY_LDEPTH2             053
#define PRM_KEY_LDEPTH3             054
#define PRM_KEY_LDEPTH4             055
#define PRM_KEY_LDEPTH5             056
#define PRM_KEY_RDEPTH0             057
#define PRM_KEY_RDEPTH1             058
#define PRM_KEY_RDEPTH2             059
#define PRM_KEY_RDEPTH3             060
#define PRM_KEY_RDEPTH4             061
#define PRM_KEY_RDEPTH5             062
#define PRM_KEY_LCURVE0             063 // 0 - 3
#define PRM_KEY_LCURVE1             064 // 0 - 3
#define PRM_KEY_LCURVE2             065 // 0 - 3
#define PRM_KEY_LCURVE3             066 // 0 - 3
#define PRM_KEY_LCURVE4             067 // 0 - 3
#define PRM_KEY_LCURVE5             068 // 0 - 3
#define PRM_KEY_RCURVE0             069 // 0 - 3
#define PRM_KEY_RCURVE1             070 // 0 - 3
#define PRM_KEY_RCURVE2             071 // 0 - 3
#define PRM_KEY_RCURVE3             072 // 0 - 3
#define PRM_KEY_RCURVE4             073 // 0 - 3
#define PRM_KEY_RCURVE5             074 // 0 - 3
#define PRM_L1_0                    075
#define PRM_L1_1                    076
#define PRM_L1_2                    077
#define PRM_L1_3                    078
#define PRM_L1_4                    079
#define PRM_L1_5                    080
#define PRM_L2_0                    082
#define PRM_L2_1                    083
#define PRM_L2_2                    084
#define PRM_L2_3                    085
#define PRM_L2_4                    086
#define PRM_L2_5                    087
#define PRM_L3_0                    089
#define PRM_L3_1                    090
#define PRM_L3_2                    091
#define PRM_L3_3                    092
#define PRM_L3_4                    093
#define PRM_L3_5                    094
#define PRM_L4_0                    096
#define PRM_L4_1                    097
#define PRM_L4_2                    098
#define PRM_L4_3                    099
#define PRM_L4_4                    100
#define PRM_L4_5                    101
#define PRM_R1_0                    103
#define PRM_R1_1                    104
#define PRM_R1_2                    105
#define PRM_R1_3                    106
#define PRM_R1_4                    107
#define PRM_R1_5                    108
#define PRM_R2_0                    110
#define PRM_R2_1                    111
#define PRM_R2_2                    112
#define PRM_R2_3                    113
#define PRM_R2_4                    114
#define PRM_R2_5                    115
#define PRM_R3_0                    117
#define PRM_R3_1                    118
#define PRM_R3_2                    119
#define PRM_R3_3                    120
#define PRM_R3_4                    121
#define PRM_R3_5                    122
#define PRM_R4_0                    124
#define PRM_R4_1                    125
#define PRM_R4_2                    126
#define PRM_R4_3                    127
#define PRM_R4_4                    128
#define PRM_R4_5                    129
#define PRM_L1_P                    130
#define PRM_L2_P                    131
#define PRM_L3_P                    132
#define PRM_L4_P                    133
#define PRM_R1_P                    134
#define PRM_R2_P                    135
#define PRM_R3_P                    136
#define PRM_R4_P                    137
#define PRM_EG_PITCH_RANGE          138
#define PRM_EG_PITCH_RANGE_VELO     139
#define PRM_RATE_KEY0               140
#define PRM_RATE_KEY1               141
#define PRM_RATE_KEY2               142
#define PRM_RATE_KEY3               143
#define PRM_RATE_KEY4               144
#define PRM_RATE_KEY5               145
#define PRM_RATE_KEYP               146
#define PRM_LFO_PITCH_DEPTH         149
#define PRM_LFO_AMP_DEPTH           150
#define PRM_LFO_SPEED               151
#define PRM_LFO_SYNC                152 // 0 - 3 (single, free running), single, Key sync, Multi, Free running, Multi, Key sync
#define PRM_LFO_WAVE                153 // 0 - 5 (Triangle, Square, Saw up, Saw Down, Sine, Random)
#define PRM_LFO_FADE                154
#define PRM_LFO_PITCH_DEPTH_WHEEL   155
#define PRM_LFO_AMP_DEPTH_WHEEL     156
#define PRM_LFO_PITCH_DEPTH_AFTER   157
#define PRM_LFO_AMP_DEPTH_AFTER     158
#define PRM_LFO_AMS0                159
#define PRM_LFO_AMS1                160
#define PRM_LFO_AMS2                161
#define PRM_LFO_AMS3                162
#define PRM_LFO_AMS4                163
#define PRM_LFO_AMS5                164
#define PRM_BEND_RANGE_UP           172
#define PRM_BEND_RANGE_DN           173
#define PRM_TRANSPOSE               174 // center value is 24 (no transpose)
#define PRM_VOLUME                  180
#define PRM_L0_0                    181
#define PRM_L0_1                    182
#define PRM_L0_2                    183
#define PRM_L0_3                    184
#define PRM_L0_4                    185
#define PRM_L0_5                    186
#define PRM_R0_0                    187
#define PRM_R0_1                    188
#define PRM_R0_2                    189
#define PRM_R0_3                    190
#define PRM_R0_4                    191
#define PRM_R0_5                    192
#define PRM_L5_0                    193
#define PRM_L5_1                    194
#define PRM_L5_2                    195
#define PRM_L5_3                    196
#define PRM_L5_4                    197
#define PRM_L5_5                    198
#define PRM_R5_0                    199
#define PRM_R5_1                    200
#define PRM_R5_2                    201
#define PRM_R5_3                    202
#define PRM_R5_4                    203
#define PRM_R5_5                    204
#define PRM_L0_P                    205
#define PRM_R0_P                    206
#define PRM_L5_P                    207
#define PRM_R5_P                    208
#define PRM_LFO_PITCH_DEPTH_BREATH  209
#define PRM_LFO_AMP_DEPTH_BREATH    210
#define PRM_LFO_PITCH_DEPTH_FOOT    211
#define PRM_LFO_AMP_DEPTH_FOOT      212
#define PRM_VOLUME_DEPTH_AFTER      213
#define PRM_VOLUME_DEPTH_WHEEL      214
#define PRM_VOLUME_DEPTH_BREATH     215
#define PRM_VOLUME_DEPTH_FOOT       216
#define PRM_PITCH_DEPTH_AFTER       217
#define PRM_PITCH_DEPTH_BREATH      218
#define PRM_PITCH_DEPTH_FOOT        219
#define PRM_PITCH_DEPTH_RND         220
#define PRM_PAN                     221
#define PRM_LFO_PMS0                222
#define PRM_LFO_PMS1                223
#define PRM_LFO_PMS2                224
#define PRM_LFO_PMS3                225
#define PRM_LFO_PMS4                226
#define PRM_LFO_PMS5                227
#define PRM_LEGATO                  228 // 0 - 1 (Polyphonic 0 or Monophonic Legato (1))
#define PRM_PORTA_MODE              229 // 0 - 2 (0 off, 1 always, 2 fingered)
#define PRM_PORTA_TIME              230
#define PRM_WAVEFORM0               236 // 0 - 7
#define PRM_WAVEFORM1               237 // 0 - 7
#define PRM_WAVEFORM2               238 // 0 - 7
#define PRM_WAVEFORM3               239 // 0 - 7
#define PRM_WAVEFORM4               240 // 0 - 7
#define PRM_WAVEFORM5               241 // 0 - 7
#define PRM_VELO_OFFSET             242
#define PRM_VELO_CURVE              243
#define PRM_EG_LOOP                 244 // bitwise
#define PRM_EG_LOOP_SEG             245 // bitwise
#define PRM_EG_RESTART              246
#define PRM_TUNING                  251
#define PRM_LEVEL0_L                256
#define PRM_LEVEL0_R                257
#define PRM_LEVEL1_L                258
#define PRM_LEVEL1_R                259
#define PRM_LEVEL2_L                260
#define PRM_LEVEL2_R                261
#define PRM_LEVEL3_L                262
#define PRM_LEVEL3_R                263
#define PRM_LEVEL4_L                264
#define PRM_LEVEL4_R                265
#define PRM_LEVEL5_L                266
#define PRM_LEVEL5_R                267
#define PRM_WAVEFORM2_0             268 // 0 - 7
#define PRM_WAVEFORM2_1             269 // 0 - 7
#define PRM_WAVEFORM2_2             270 // 0 - 7
#define PRM_WAVEFORM2_3             271 // 0 - 7
#define PRM_WAVEFORM2_4             272 // 0 - 7
#define PRM_WAVEFORM2_5             273 // 0 - 7
#define PRM_WMODE0                  274 // 0 - 1
#define PRM_WMODE1                  275 // 0 - 1
#define PRM_WMODE2                  276 // 0 - 1
#define PRM_WMODE3                  277 // 0 - 1
#define PRM_WMODE4                  278 // 0 - 1
#define PRM_WMODE5                  279 // 0 - 1
#define PRM_WRATIO0                 280
#define PRM_WRATIO1                 281
#define PRM_WRATIO2                 282
#define PRM_WRATIO3                 283
#define PRM_WRATIO4                 284
#define PRM_WRATIO5                 285
#define PRM_OSC_PHASE0              286 // 0 - 3 (0 / 90 / 180 / 270)
#define PRM_OSC_PHASE1              287 // 0 - 3 (0 / 90 / 180 / 270)
#define PRM_OSC_PHASE2              288 // 0 - 3 (0 / 90 / 180 / 270)
#define PRM_OSC_PHASE3              289 // 0 - 3 (0 / 90 / 180 / 270)
#define PRM_OSC_PHASE4              290 // 0 - 3 (0 / 90 / 180 / 270)
#define PRM_OSC_PHASE5              291 // 0 - 3 (0 / 90 / 180 / 270)
#define PRM_SDLY_DRY                300
#define PRM_SDLY_WET                301
#define PRM_SDLY_MODE               302 // 0 - 3 Stereo, Cross, Bounce
#define PRM_SDLY_TIME               303
#define PRM_SDLY_FEEDBACK           304
#define PRM_SDLY_FEEDLO             305
#define PRM_SDLY_FEEDHI             306
#define PRM_SDLY_TEMPO              307 // 0 midi, 50-255
#define PRM_SDLY_NUM                308
#define PRM_SDLY_DEN                309
#define PRM_PHASER_DRY              310
#define PRM_PHASER_WET              311
#define PRM_PHASER_MODE             312 // 0 - 2 (Mono, Stereo, Cross)
#define PRM_PHASER_DEPTH            313
#define PRM_PHASER_SPEED            314
#define PRM_PHASER_FEEDBACK         315
#define PRM_PHASER_OFFSET           316
#define PRM_PHASER_STAGES           317 // 4-12?
#define PRM_PHASER_PHASE            318
#define PRM_PHASER_WAVEFORM         319
#define PRM_FILTER_LO               320
#define PRM_FILTER_HI               321
#define PRM_AM_SPEED                330
#define PRM_AM_RANGE                331
#define PRM_AM_DEPTH                332
#define PRM_AM_PHASE                333
#define PRM_FIR_IMPULSE             340
#define PRM_WAVESHAPER_DRY          350
#define PRM_WAVESHAPER_WET          351
#define PRM_WAVESHAPER_GAIN_PRE     352
#define PRM_WAVESHAPER_GAIN_POST    353
#define PRM_WAVESHAPER_SHAPE        354
#define PRM_CHORUS_DRY              360
#define PRM_CHORUS_WET              361
#define PRM_CHORUS_MODE             362 // 0 - 3 (Chorus long, Chorus Short, Flanger Long, Flanger Short)
#define PRM_CHORUS_SPEED            363
#define PRM_CHORUS_DEPTH            364
#define PRM_CHORUS_FEEDBACK         365
#define PRM_CHORUS_PHASE            366
#define PRM_DECIMATOR_DEPTH         370
#define PRM_BITCRUSHER_DEPTH        380 // 0 - 24 (bits to reduce)
#define PRM_REVERB_DRY              390
#define PRM_REVERB_WET              391
#define PRM_REVERB_MODE             392 // 0 - 1 Plate or Hall
#define PRM_REVERB_DECAY            393
#define PRM_REVERB_DAMP             394
#define PRM_REVERB_D0               395
#define PRM_REVERB_D1               396
#define PRM_REVERB_D2               397
#define PRM_FX_ROUTING              410 // 0 or 1
#define PRM_OUTPUT_LEVEL            411
#define PRM_CONTROL_1H              420
#define PRM_CONTROL_1L              421
#define PRM_CONTROL_2H              422
#define PRM_CONTROL_2L              423
#define PRM_CONTROL_3H              424
#define PRM_CONTROL_3L              425
#define PRM_CONTROL_4H              426
#define PRM_CONTROL_4L              427
#define PRM_ARP_MODE                450 // 0 - 5 (Off, Up, Down, Up/Down, As Played, Random)
#define PRM_ARP_TEMPO               451 // 0 is midi sync, 50-255
#define PRM_ARP_TEMPO_FINE          452
#define PRM_ARP_DIVISION            453
#define PRM_ARP_OCTAVES             454

// Define integers for all of the internal Paramters

int ALGO0 = 0;
int ALGO1 = 0;
int ALGO2 = 0;
int ALGO3 = 0;
int ALGO4 = 0;
int ALGO5 = 0;
int FEEDBACK0 = 0;
int FEEDBACK1 = 0;
int FEEDBACK2 = 0;
int FEEDBACK3 = 0;
int FEEDBACK4 = 0;
int FEEDBACK5 = 0;
int OSC_SYNC = 0;
int OSC_MODE = 0;
int RATIO0 = 0;
int RATIO1 = 0;
int RATIO2 = 0;
int RATIO3 = 0;
int RATIO4 = 0;
int RATIO5 = 0;
int RATIO_FINE0 = 0;
int RATIO_FINE1 = 0;
int RATIO_FINE2 = 0;
int RATIO_FINE3 = 0;
int RATIO_FINE4 = 0;
int RATIO_FINE5 = 0;
int FINE0 = 0;
int FINE1 = 0;
int FINE2 = 0;
int FINE3 = 0;
int FINE4 = 0;
int FINE5 = 0;
int LEVEL0 = 0;
int LEVEL1 = 0;
int LEVEL2 = 0;
int LEVEL3 = 0;
int LEVEL4 = 0;
int LEVEL5 = 0;
int VEL_SENS0 = 0;
int VEL_SENS1 = 0;
int VEL_SENS2 = 0;
int VEL_SENS3 = 0;
int VEL_SENS4 = 0;
int VEL_SENS5 = 0;
int KEY_BP0 = 0;
int KEY_BP1 = 0;
int KEY_BP2 = 0;
int KEY_BP3 = 0;
int KEY_BP4 = 0;
int KEY_BP5 = 0;
int KEY_LDEPTH0 = 0;
int KEY_LDEPTH1 = 0;
int KEY_LDEPTH2 = 0;
int KEY_LDEPTH3 = 0;
int KEY_LDEPTH4 = 0;
int KEY_LDEPTH5 = 0;
int KEY_RDEPTH0 = 0;
int KEY_RDEPTH1 = 0;
int KEY_RDEPTH2 = 0;
int KEY_RDEPTH3 = 0;
int KEY_RDEPTH4 = 0;
int KEY_RDEPTH5 = 0;
int KEY_LCURVE0 = 0;
int KEY_LCURVE1 = 0;
int KEY_LCURVE2 = 0;
int KEY_LCURVE3 = 0;
int KEY_LCURVE4 = 0;
int KEY_LCURVE5 = 0;
int KEY_RCURVE0 = 0;
int KEY_RCURVE1 = 0;
int KEY_RCURVE2 = 0;
int KEY_RCURVE3 = 0;
int KEY_RCURVE4 = 0;
int KEY_RCURVE5 = 0;
int L1_0 = 0;
int L1_1 = 0;
int L1_2 = 0;
int L1_3 = 0;
int L1_4 = 0;
int L1_5 = 0;
int L2_0 = 0;
int L2_1 = 0;
int L2_2 = 0;
int L2_3 = 0;
int L2_4 = 0;
int L2_5 = 0;
int L3_0 = 0;
int L3_1 = 0;
int L3_2 = 0;
int L3_3 = 0;
int L3_4 = 0;
int L3_5 = 0;
int L4_0 = 0;
int L4_1 = 0;
int L4_2 = 0;
int L4_3 = 0;
int L4_4 = 0;
int L4_5 = 0;
int R1_0 = 0;
int R1_1 = 0;
int R1_2 = 0;
int R1_3 = 0;
int R1_4 = 0;
int R1_5 = 0;
int R2_0 = 0;
int R2_1 = 0;
int R2_2 = 0;
int R2_3 = 0;
int R2_4 = 0;
int R2_5 = 0;
int R3_0 = 0;
int R3_1 = 0;
int R3_2 = 0;
int R3_3 = 0;
int R3_4 = 0;
int R3_5 = 0;
int R4_0 = 0;
int R4_1 = 0;
int R4_2 = 0;
int R4_3 = 0;
int R4_4 = 0;
int R4_5 = 0;
int L1_P = 0;
int L2_P = 0;
int L3_P = 0;
int L4_P = 0;
int R1_P = 0;
int R2_P = 0;
int R3_P = 0;
int R4_P = 0;
int EG_PITCH_RANGE = 0;
int EG_PITCH_RANGE_VELO = 0;
int RATE_KEY0 = 0;
int RATE_KEY1 = 0;
int RATE_KEY2 = 0;
int RATE_KEY3 = 0;
int RATE_KEY4 = 0;
int RATE_KEY5 = 0;
int RATE_KEYP = 0;
int LFO_PITCH_DEPTH = 0;
int LFO_AMP_DEPTH = 0;
int LFO_SPEED = 0;
int LFO_SYNC = 0;
int LFO_WAVE = 0;
int LFO_FADE = 0;
int LFO_PITCH_DEPTH_WHEEL = 0;
int LFO_AMP_DEPTH_WHEEL = 0;
int LFO_PITCH_DEPTH_AFTER = 0;
int LFO_AMP_DEPTH_AFTER = 0;
int LFO_AMS0 = 0;
int LFO_AMS1 = 0;
int LFO_AMS2 = 0;
int LFO_AMS3 = 0;
int LFO_AMS4 = 0;
int LFO_AMS5 = 0;
int BEND_RANGE_UP = 0;
int BEND_RANGE_DN = 0;
int TRANSPOSE = 0;
int VOLUME = 0;
int L0_0 = 0;
int L0_1 = 0;
int L0_2 = 0;
int L0_3 = 0;
int L0_4 = 0;
int L0_5 = 0;
int R0_0 = 0;
int R0_1 = 0;
int R0_2 = 0;
int R0_3 = 0;
int R0_4 = 0;
int R0_5 = 0;
int L5_0 = 0;
int L5_1 = 0;
int L5_2 = 0;
int L5_3 = 0;
int L5_4 = 0;
int L5_5 = 0;
int R5_0 = 0;
int R5_1 = 0;
int R5_2 = 0;
int R5_3 = 0;
int R5_4 = 0;
int R5_5 = 0;
int L0_P = 0;
int R0_P = 0;
int L5_P = 0;
int R5_P = 0;
int LFO_PITCH_DEPTH_BREATH = 0;
int LFO_AMP_DEPTH_BREATH = 0;
int LFO_PITCH_DEPTH_FOOT = 0;
int LFO_AMP_DEPTH_FOOT = 0;
int VOLUME_DEPTH_AFTER = 0;
int VOLUME_DEPTH_WHEEL = 0;
int VOLUME_DEPTH_BREATH = 0;
int VOLUME_DEPTH_FOOT = 0;
int PITCH_DEPTH_AFTER = 0;
int PITCH_DEPTH_BREATH = 0;
int PITCH_DEPTH_FOOT = 0;
int PITCH_DEPTH_RND = 0;
int PAN = 0;
int LFO_PMS0 = 0;
int LFO_PMS1 = 0;
int LFO_PMS2 = 0;
int LFO_PMS3 = 0;
int LFO_PMS4 = 0;
int LFO_PMS5 = 0;
int LEGATO = 0;
int PORTA_MODE = 0;
int PORTA_TIME = 0;
int WAVEFORM0 = 0;
int WAVEFORM1 = 0;
int WAVEFORM2 = 0;
int WAVEFORM3 = 0;
int WAVEFORM4 = 0;
int WAVEFORM5 = 0;
int VELO_OFFSET = 0;
int VELO_CURVE = 0;
int EG_LOOP = 0;
int EG_LOOP_SEG = 0;
int EG_RESTART = 0;
int TUNING = 0;
int LEVEL0_L = 0;
int LEVEL0_R = 0;
int LEVEL1_L = 0;
int LEVEL1_R = 0;
int LEVEL2_L = 0;
int LEVEL2_R = 0;
int LEVEL3_L = 0;
int LEVEL3_R = 0;
int LEVEL4_L = 0;
int LEVEL4_R = 0;
int LEVEL5_L = 0;
int LEVEL5_R = 0;
int WAVEFORM2_0 = 0;
int WAVEFORM2_1 = 0;
int WAVEFORM2_2 = 0;
int WAVEFORM2_3 = 0;
int WAVEFORM2_4 = 0;
int WAVEFORM2_5 = 0;
int WMODE0 = 0;
int WMODE1 = 0;
int WMODE2 = 0;
int WMODE3 = 0;
int WMODE4 = 0;
int WMODE5 = 0;
int WRATIO0 = 0;
int WRATIO1 = 0;
int WRATIO2 = 0;
int WRATIO3 = 0;
int WRATIO4 = 0;
int WRATIO5 = 0;
int OSC_PHASE0 = 0;
int OSC_PHASE1 = 0;
int OSC_PHASE2 = 0;
int OSC_PHASE3 = 0;
int OSC_PHASE4 = 0;
int OSC_PHASE5 = 0;
int SDLY_DRY = 0;
int SDLY_WET = 0;
int SDLY_MODE = 0;
int SDLY_TIME = 0;
int SDLY_FEEDBACK = 0;
int SDLY_FEEDLO = 0;
int SDLY_FEEDHI = 0;
int SDLY_TEMPO = 0;
int SDLY_NUM = 0;
int SDLY_DEN = 0;
int PHASER_DRY = 0;
int PHASER_WET = 0;
int PHASER_MODE = 0;
int PHASER_DEPTH = 0;
int PHASER_SPEED = 0;
int PHASER_FEEDBACK = 0;
int PHASER_OFFSET = 0;
int PHASER_STAGES = 0;
int PHASER_PHASE = 0;
int PHASER_WAVEFORM = 0;
int FILTER_LO = 0;
int FILTER_HI = 0;
int AM_SPEED = 0;
int AM_RANGE = 0;
int AM_DEPTH = 0;
int AM_PHASE = 0;
int FIR_IMPULSE = 0;
int WAVESHAPER_DRY = 0;
int WAVESHAPER_WET = 0;
int WAVESHAPER_GAIN_PRE = 0;
int WAVESHAPER_GAIN_POST = 0;
int WAVESHAPER_SHAPE = 0;
int CHORUS_DRY = 0;
int CHORUS_WET = 0;
int CHORUS_MODE = 0;
int CHORUS_SPEED = 0;
int CHORUS_DEPTH = 0;
int CHORUS_FEEDBACK = 0;
int CHORUS_PHASE = 0;
int DECIMATOR_DEPTH = 0;
int BITCRUSHER_DEPTH = 0;
int REVERB_DRY = 0;
int REVERB_WET = 0;
int REVERB_MODE = 0;
int REVERB_DECAY = 0;
int REVERB_DAMP = 0;
int REVERB_D0 = 0;
int REVERB_D1 = 0;
int REVERB_D2 = 0;
int FX_ROUTING = 0;
int OUTPUT_LEVEL = 0;
int CONTROL_1H = 0;
int CONTROL_1L = 0;
int CONTROL_2H = 0;
int CONTROL_2L = 0;
int CONTROL_3H = 0;
int CONTROL_3L = 0;
int CONTROL_4H = 0;
int CONTROL_4L = 0;
int ARP_MODE = 0;
int ARP_TEMPO = 0;
int ARP_TEMPO_FINE = 0;
int ARP_DIVISION = 0;
int ARP_OCTAVES = 0;