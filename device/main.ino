#include "commands.h"

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

void _fail() {
    serial.write(COMMAND_PRG_FAIL);
}

void _ok() {
    serial.write(COMMAND_PRG_OK);
}

void setup() {
    serial.begin(9600);
    serial.println("~ Programmer ready");
}

void loop() {
    if(serial.available() > 0) {
        _incomingByte = serial.read();

        switch(_incomingByte) {
            default:
                serial.println("~ Unknown command");
                _fail();

                return;
        }
    }
}