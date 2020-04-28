# XFM2UI
XFM2UI is an Arduino user interface for XFM2 based on Teensy 4.0 microcontroller.
XFM2 is a project by Rene that implements a very full featured 2-voice FM synthesizer on top of the CMOD A7 FPGA.  You can find his project here https://www.futur3soundz.com/

## Hardware
You will likely need to have built one of the XFM2 synths prior to taking interest, so please refer to Rene's blog above for instructions on aquiring the synth.

### Build of Materials
The current XFM2UI hardware consists of:
- PJRC Teensy 4.0 (however almost any arduino compatible board will work)
- A clickable rotary encoder
- Breadboard or other suitable prototyping platform
- Adafruit SSD1306 OLED 128x64 pixel display

### Hardware Build Instructions

To be completed...

## Software
To be completed...

## Contributing
Pull requests are always welcome and encouraged.  I am not an experienced software developer and new to the Arduino platform so I'm learning through this project.

### Collaboration
There is a slack channel created for active discussion and development for the software.  https://join.slack.com/t/xfm2/shared_invite/zt-dmrs50h3-34WvYiWgPBWruNXSXLYgBg

### List of Priorities
- Implementation of the UART bi-directional data communication between the XFM2UI and XMF2
- Implementation of basic parameter changes
- Implementation of preset recall features (load, save, share)
- Implementation of web-based UI (using wireless adapter potentially)
