# System Architecture

## Central Controller

The LPC2129 ARM7 microcontroller is the central controller. The supplied project code initializes UART, RTC, LCD, servo, and keypad peripherals and continuously monitors the PIR sensor. fileciteturn0file5L9-L33

## Core Architecture

```text
                    LPC2129 ARM7
                         |
       +-----------------+------------------+
       |        |        |       |          |
      PIR      RFID    Keypad    RTC      LCD/UART
       |        |        |       |          |
       |        +--------+       |          |
       |       Authentication    |          |
       |              |          |          |
       +--------------+----------+----------+
                      |
                Access Decision
                      |
                 Servo Motor
                      |
               Door Operation
```

## Communication

The complete project specification defines UART for ESP-01/Arduino communication, SPI for RC522 and SD card, I2C for DS1307 and AT24C256, CAN through MCP2551, and GPIO for local peripherals. fileciteturn1file0L99-L106

The currently supplied source code directly implements the UART, I2C, GPIO/keypad, LCD, RTC, PIR, RFID and PWM-servo portions.

## Full Proposed Architecture

```text
 Authentication
 ┌────────┬──────────────┬──────────┐
 │ RFID   │ Fingerprint  │ Keypad   │
 └────────┴──────────────┴──────────┘
              |
              v
        ┌─────────────┐
        │  LPC2129    │
        │   ARM7      │
        └──────┬──────┘
               |
     ┌─────────┼─────────┐
     v         v         v
  Sensors    Storage   Communication
  PIR/Door   RTC/EEPROM   ESP-01
             SD Card      CAN
               |
               v
        Door / Indicators
        Relay + Lock
        Servo + LCD
        LEDs + Buzzer
```

The full reference architecture describes this controller-centric, modular design. fileciteturn1file2L347-L355
