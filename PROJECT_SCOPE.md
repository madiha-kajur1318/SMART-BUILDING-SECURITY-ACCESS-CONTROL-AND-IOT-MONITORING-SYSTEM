# Project Scope

## Implemented in Supplied Source

The repository contains source files for:

- LPC2129 startup/application logic
- UART0
- LCD
- I2C
- DS1307 RTC
- AT24C256 EEPROM write routine
- PIR monitoring
- RFID input/authentication routine
- 4×4 keypad/password routine
- PWM servo control
- LEDs and buzzer

## Described in the Reference Specification

The supplied project PDF describes a larger smart-building system with:

- RFID
- Fingerprint
- Password
- PIR
- Magnetic door sensing
- RTC
- EEPROM
- SD card
- ESP-01 / ThingSpeak
- MCP2551 CAN
- Relay
- Electromagnetic door lock
- Servo
- LCD
- LEDs
- Buzzer

The reference emphasizes multi-level authentication, automatic access control, event logging, cloud monitoring and CAN networking. fileciteturn1file4L565-L584

## Why This Separation Matters

Keeping the repository description aligned with the supplied source code prevents the GitHub project from claiming that a driver exists when it is only specified in the design document.

The reference PDF is retained in `docs/project_reference.pdf` so the complete intended architecture remains documented.
