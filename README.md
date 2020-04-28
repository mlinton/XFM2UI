# XFM2UI
XFM2UI is an Arduino user interface for XFM2 based on Teensy 4.0 microcontroller.
XFM2 is a project by Rene that implements a very full featured 2-voice FM synthesizer on top of the CMOD A7 FPGA.  You can find his project here https://www.futur3soundz.com/

## Hardware
You will likely need to have built one of the XFM2 synths prior to taking interest, so please refer to Rene's blog above for instructions on aquiring the synth.

18 digital pins available for the connection of mapped analog or digital controls for additional direct control.

![Messy wire prototype](https://i.imgur.com/HUyAj72.jpg)

### Build of Materials
The current XFM2UI hardware consists of:
- PJRC Teensy 4.0 (however almost any arduino compatible board will work)
- A clickable rotary encoder
- Breadboard or other suitable prototyping platform
- Adafruit SSD1306 OLED 128x64 pixel display

### Hardware Build Instructions

To be completed...

## Software
The basis of the interface is menu driven concept to permit the modification of the parameters within the XFM2 code.  These parameters are numbered and named and each refers to a value that will change the personality of the synthesizer in real-time.

The menu system is based on the Arduino Menu library (https://github.com/neu-rah/ArduinoMenu).


## Contributing
Pull requests are always welcome and encouraged.  I am not an experienced software developer and new to the Arduino platform so I'm learning through this project.

### Collaboration
There is a slack channel created for active discussion and development for the software.  https://join.slack.com/t/xfm2/shared_invite/zt-dmrs50h3-34WvYiWgPBWruNXSXLYgBg

### List of Priorities
- UART bi-directional data communication between the XFM2UI and XMF2
- Basic parameter changes
- Preset recall features (load, save, share)
- Map additional controls (pots, encoders, faders, etc)
- Web-based UI (using wireless adapter potentially)
