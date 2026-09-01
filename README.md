# Smart Building Access Control & Security System

A modular embedded security and access-control prototype based on the **LPC2129 ARM7 microcontroller**, developed in **Embedded C**. The project combines motion detection, RFID authentication, keypad password verification, RTC timing, EEPROM storage, LCD/UART status reporting, I2C communication, and servo-based door control.

> **Implementation note:** The supplied project reference describes a broader smart-building architecture that also includes fingerprint authentication, SD-card logging, ESP-01/ThingSpeak connectivity, CAN communication, a magnetic door sensor, relay control, and additional indicators. The source files in this repository currently contain the core modules listed in the repository structure below. The reference PDF is included under `docs/` for the complete proposed-system specification.

## Author

**Madiha Kandukuru**  
B.Tech – Electronics and Communication Engineering (ECE)

This project demonstrates practical embedded-systems development using ARM7 microcontrollers, peripheral interfacing, communication protocols, sensor integration, and modular Embedded C programming.

## Project Overview

The system is designed as a smart entrance-security solution. The LPC2129 acts as the central controller and coordinates authentication, sensing, user feedback, time information, data storage, and door operation.

The project reference specifies a multi-level authentication concept using RFID, fingerprint verification, and password authentication, together with security monitoring, event logging, IoT connectivity, and CAN networking. fileciteturn1file4L552-L584

The currently supplied source implementation demonstrates the following core path:

1. Initialize UART, RTC, LCD, servo, keypad, and GPIO.
2. Continuously monitor the PIR sensor.
3. When motion is detected, start RFID authentication.
4. If RFID authentication fails, request keypad password authentication.
5. On successful authentication, record/display the RTC time, write timing information to EEPROM, and operate the servo.
6. Provide LCD, UART, LED, and buzzer status indications.

The core program initializes the peripherals and continuously calls the PIR security routine. fileciteturn0file5L9-L15

## Core Features

- LPC2129 ARM7 central control
- PIR-based motion monitoring
- RFID-based authentication
- 4×4 matrix keypad password authentication
- DS1307 RTC time/date interface
- AT24C256 EEPROM interface
- 16×2 LCD status display
- UART0 serial communication
- I2C communication
- PWM-based servo door control
- LED and buzzer security indication
- Modular driver-based Embedded C architecture

The project reference identifies UART, SPI, I2C, CAN, and GPIO as the principal communication/interface mechanisms across the complete proposed architecture. fileciteturn1file0L99-L106

## System Flow

```text
                +----------------------+
                |      LPC2129 ARM7    |
                |   Central Controller |
                +----------+-----------+
                           |
             +-------------+-------------+
             |             |             |
          PIR Sensor    RFID Reader    Keypad
             |             |             |
             +-------------+-------------+
                           |
                     Authentication
                           |
                 +---------+---------+
                 |                   |
              Valid               Invalid
                 |                   |
                 v                   v
          RTC / EEPROM         Password Check
                 |                   |
                 +---------+---------+
                           |
                    Access Decision
                           |
                    Servo Door Control
                           |
                LCD / UART / LED / Buzzer
```

The reference architecture describes the LPC2129 as the central controller coordinating authentication, sensing, storage, cloud communication, CAN networking, and output devices. fileciteturn1file2L347-L355

## Repository Structure

```text
Smart-Building-Access-Control/
│
├── src/
│   ├── main.c
│   ├── delay.c
│   ├── eeprom.c
│   ├── i2c_driver.c
│   ├── keypad_driver.c
│   ├── lcd_driver.c
│   ├── pir_sensor.c
│   ├── project.h
│   ├── rfid_driver.c
│   ├── rtc_driver.c
│   ├── servo.c
│   └── uart_driver.c
│
├── docs/
│   ├── project_reference.pdf
│   ├── SYSTEM_ARCHITECTURE.md
│   ├── PROGRAM_FLOW.md
│   ├── HARDWARE_AND_INTERFACES.md
│   └── PROJECT_SCOPE.md
│
├── PROJECT_DESCRIPTION.txt
├── .gitignore
├── LICENSE
└── README.md
```

## Technologies Used

| Category | Technology |
|---|---|
| Microcontroller | LPC2129 ARM7 |
| Programming | Embedded C |
| RFID | RC522 |
| Motion Sensor | PIR |
| User Input | 4×4 Matrix Keypad |
| RTC | DS1307 |
| Non-volatile Memory | AT24C256 EEPROM |
| Display | 16×2 LCD |
| Communication | UART, I2C |
| Door Actuator | Servo Motor |
| Indication | LEDs, Buzzer |

The project reference additionally proposes R307S fingerprint sensing with Arduino UNO, ESP-01 Wi-Fi/ThingSpeak monitoring, SD-card logging, MCP2551 CAN networking, relay/electromagnetic locking, and magnetic door sensing. fileciteturn1file0L149-L170

## Authentication

### RFID

The current RFID driver receives a 12-character RFID identifier over UART and compares it with the configured authorized identifier. A successful match triggers the door-opening sequence; an invalid identifier is rejected. fileciteturn0file9L8-L31 fileciteturn0file9L33-L65

### Keypad

The keypad driver scans a 4×4 matrix and maps the keys to numeric and function characters. Password entry is masked on the LCD, and the entered four-character password is compared against the configured password. fileciteturn0file3L20-L25 fileciteturn0file3L133-L158

## Security Monitoring

The PIR module monitors the configured LPC2129 GPIO input. When no motion is detected, the system reports a normal/safe condition. When motion is detected, it reports an alert condition, activates the buzzer, and initiates RFID-based access checking. fileciteturn0file6L9-L27 fileciteturn0file6L31-L47

## Time & Event Information

The DS1307 driver communicates through I2C and provides time/date values to the application. The EEPROM routine stores selected RTC values through the I2C interface. fileciteturn0file10L7-L33 fileciteturn0file1L3-L29

## Door Control

The servo driver uses the LPC2129 PWM peripheral and provides 0°, 90°, and 180° positioning functions. fileciteturn0file11L5-L16 fileciteturn0file11L18-L31

## LCD & UART

The LCD driver operates the display in a 4-bit data arrangement and provides command, data, initialization, and string functions. fileciteturn0file4L4-L23 fileciteturn0file4L49-L67

UART0 provides initialization, transmit, receive, string, integer, and floating-point helper functions. fileciteturn0file12L5-L20 fileciteturn0file12L24-L50

## Building the Project

The supplied source is written for the **LPC2129 ARM7 environment** and includes the device header:

```c
#include <lpc21xx.h>
```

Build it using the ARM7/LPC2129 toolchain and project configuration appropriate to your development board/environment. The repository intentionally does not claim a specific compiler command because the supplied files do not include a project file or toolchain configuration.

### Source Dependencies

The common header `src/project.h` contains the external declarations shared by the driver modules, including UART, LCD, I2C, RTC, PIR, RFID, keypad, servo, and EEPROM interfaces. fileciteturn0file7L8-L24 fileciteturn0file7L32-L61

## Hardware Interfaces

- **GPIO:** PIR, keypad, LEDs and buzzer
- **UART0:** serial communication and RFID input in the supplied driver
- **I2C:** DS1307 RTC and EEPROM
- **PWM:** servo motor
- **LCD GPIO:** 16×2 display interface

## Expected Behaviour

### Normal Condition

```text
PIR Security
System Ready

Motion Status : CLEAR
Security : NORMAL
Field : SAFE
No Motion
```

### Motion Detected

```text
Motion Status : DETECTED
Security : ALERT

Motion Found
Check Field
```

### Valid Authentication

```text
RFID VALID
Password verified
ACCESS GRANTED
DOOR OPEN
```

### Invalid Authentication

```text
INVALID RFID
or
WRONG PASSWORD

Access denied
Door remains closed
```

## Complete Proposed-System Scope

For the full architecture described in the supplied reference document, the planned system includes:

- RFID authentication
- Fingerprint authentication
- Password authentication
- PIR motion detection
- Magnetic door monitoring
- RTC-based event timestamping
- EEPROM and SD-card logging
- ESP-01 cloud monitoring through ThingSpeak
- CAN communication between security nodes
- Relay and electromagnetic door-lock control
- Servo-based automatic door operation
- LCD, LED, and buzzer indications

These capabilities and the proposed applications are described in the reference specification. fileciteturn1file0L107-L125

## Future Scope

The reference proposes future extensions including face recognition, mobile application control, AI-based visitor management, voice authentication, biometric attendance integration, cloud analytics, emergency evacuation support, and broader smart-building automation. fileciteturn1file3L427-L432

## Project Documentation

- `docs/SYSTEM_ARCHITECTURE.md` — architecture and module relationships
- `docs/PROGRAM_FLOW.md` — execution and authentication flow
- `docs/HARDWARE_AND_INTERFACES.md` — hardware and communication interfaces
- `docs/PROJECT_SCOPE.md` — implemented core versus proposed full-system scope
- `docs/project_reference.pdf` — supplied project specification/reference

## Author

**Madiha Kandukuru**  
**B.Tech – Electronics and Communication Engineering (ECE)**

Interested in embedded systems, ARM-based microcontroller programming, peripheral interfacing, communication protocols, and practical electronics projects.

## License

This repository is intended for educational, academic, and portfolio purposes. See `LICENSE` for details.
