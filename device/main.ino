#include "commands.h"

#include "Arduino.h"
#include "HardwareSerial.h"
HardwareSerial serial;

int _incomingByte = 0;

/*
    Provides information about memory selected.

    0: No memory selected
    1: Flash memory
    2: EEPROM
*/
int _selectedMemory = 0;

int _pinout_buzzer = 13;

void _fail() {
    serial.write(COMMAND_PRG_FAIL);
}

void _ok() {
    serial.write(COMMAND_PRG_OK);
}

void setup() {
    serial.begin(9600);

    pinMode();

    serial.println("~ Programmer ready");
}

void loop() {
    if(serial.available() > 0) {
        _incomingByte = serial.read();

        switch(_incomingByte) {
            case COMMAND_SET_FLASH:
                serial.println("~ Select memory: Flash");
                _selectedMemory = 1;

                _ok();
                break;

            case COMMAND_SET_EEPROM:
                serial.println("~ Select memory: EEPROM");
                _selectedMemory = 2;

                _ok();
                break;

            default:
                serial.println("~ Unknown command");
                _fail();

                break;
        }
    }
}