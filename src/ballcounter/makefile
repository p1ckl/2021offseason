### DISCLAIMER
### This is an example Makefile and it MUST be configured to suit your needs.
### For detailed explanations about all of the available options, please refer
### to https://github.com/sudar/Arduino-Makefile/blob/master/arduino-mk-vars.md
### Original project where this Makefile comes from: https://github.com/WeAreLeka/Bare-Arduino-Project

### PROJECT_DIR
### This is the path to where you have created/cloned your project
PROJECT_DIR       = /Users/p1ckl/2021offseason/2021offseason/src/ballcounter/

### ARDMK_DIR
### Path to the Arduino-Makefile directory.
ARDMK_DIR         = $(HOME)/.arduino_mk

### ARDUINO_DIR
### Path to the Arduino application and resources directory.
### On OS X:
ARDUINO_DIR       = /Applications/Arduino\ IDE.app/Contents/Java

### BOARD_TAG
### It must be set to the board you are currently using. (i.e uno, mega2560, etc.)
BOARD_TAG         = mega2560

### MONITOR_BAUDRATE
### It must be set to Serial baudrate value you are using.
MONITOR_BAUDRATE  = 9600

### MONITOR_PORT
### The port your board is connected to. Using an '*' tries all the ports and finds the right one.
MONITOR_PORT      = /dev/tty.usbmodem*

### CURRENT_DIR
### Do not touch - used for binaries path
CURRENT_DIR       = $(shell basename $(CURDIR))

### OBJDIR
### This is where you put the binaries you just compile using 'make'
OBJDIR            = $(PROJECT_DIR)/bin/$(BOARD_TAG)/$(CURRENT_DIR)

### Do not touch - the path to Arduino.mk, inside the ARDMK_DIR
include $(ARDMK_DIR)/Arduino.mk



