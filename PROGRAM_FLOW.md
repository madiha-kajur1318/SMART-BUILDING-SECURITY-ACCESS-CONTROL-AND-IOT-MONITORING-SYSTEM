# Program Flow

## Main Program

1. Initialize UART0.
2. Initialize RTC.
3. Initialize LCD.
4. Initialize servo PWM.
5. Initialize keypad.
6. Configure PIR input.
7. Display `PIR Security / System Ready`.
8. Continuously call `PIR_Sensor()`.

This sequence is present in the supplied `main.c`. fileciteturn0file5L9-L33

## PIR Decision

```text
START
  |
Initialize peripherals
  |
Monitor PIR
  |
Motion?
 /     \
No      Yes
|        |
Safe     Alert
|        |
|      RFID
|        |
|   +----+----+
| Valid     Invalid
|   |          |
| Access     Keypad
| Granted      |
|             Password
|          +----+----+
|        Valid     Invalid
|          |          |
+----------+          |
           |          |
        Door Open   Door Closed
```

The supplied PIR routine reports safe/normal status when the sensor input is low and an alert when motion is detected. On motion, it calls the RFID routine and invokes keypad authentication when RFID returns failure. fileciteturn0file6L11-L27 fileciteturn0file6L31-L47

## RFID Flow

The supplied RFID driver receives 12 characters and compares them against the configured RFID identifier. A match operates the servo; an invalid identifier returns failure. fileciteturn0file9L8-L31 fileciteturn0file9L33-L65

## Keypad Flow

The keypad routine reads four characters, masks them on the LCD, appends a null terminator, and compares the resulting string with the configured password. fileciteturn0file3L149-L158

## Door Flow

The servo driver provides predefined PWM positions for 0°, 90°, and 180°. fileciteturn0file11L18-L31
