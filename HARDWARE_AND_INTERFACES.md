# Hardware & Interfaces

| Module | Role | Interface in supplied code |
|---|---|---|
| LPC2129 ARM7 | Central controller | — |
| PIR sensor | Motion detection | GPIO P0.15 |
| RC522 RFID | User authentication | UART-based input in supplied RFID driver |
| 4×4 keypad | Password input | GPIO |
| DS1307 RTC | Time/date | I2C |
| AT24C256 EEPROM | Non-volatile storage | I2C |
| 16×2 LCD | User/status display | GPIO |
| Servo motor | Door movement | PWM |
| LEDs | Status indication | GPIO |
| Buzzer | Security alert | GPIO |
| UART0 | Debug/status communication | UART |

The supplied code configures PIR on P0.15, while the keypad uses GPIO row/column definitions and the RTC uses I2C. fileciteturn0file5L20-L27 fileciteturn0file3L10-L23 fileciteturn0file10L7-L33

## Additional Modules in the Reference Design

The PDF specification also includes R307S fingerprint sensor, Arduino UNO, magnetic door sensor, ESP-01, MCP2551 CAN, SD card, relay, electromagnetic lock, and ThingSpeak. fileciteturn1file0L149-L170

These should be treated as part of the **proposed complete system architecture**, not as implemented source modules in this repository unless corresponding driver/source files are added.
