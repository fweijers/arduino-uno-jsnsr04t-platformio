# Arduino Uno + JSN-SR04T (PlatformIO)

Eenvoudig PlatformIO-project voor het uitlezen van een JSN-SR04T ultrasone sensor met een Arduino Uno.

## Hardware
- Arduino Uno (of compatibele clone)
- JSN-SR04T (waterdichte ultrasone sensor, 5V)
- Bekabeling (VCC -> 5V, GND -> GND, TRIG -> D7, ECHO -> D6 in de default code)

> Let op: De Uno is 5V, de JSN-SR04T ook. Bij andere borden (3.3V) kan een spanningsdeler/level shifter nodig zijn.

## Projectstructuur
```text
arduino-uno-jsnsr04t-platformio/
├─ src/
│  └─ main.cpp
├─ include/
├─ lib/
├─ .vscode/
├─ platformio.ini
└─ README.md
```

## Gebruik (VS Code + PlatformIO)
1. Open deze map in VS Code.
2. Installeer extensie **PlatformIO IDE** als dat nog niet is gedaan.
3. Sluit je Uno via USB aan. Controleer de seriële poort via PlatformIO > Devices.
4. Pas eventueel `PIN_TRIG` en `PIN_ECHO` in `src/main.cpp` aan.
5. **Build** (✔️), **Upload** (➡️) en open **Monitor** (🔌). Baudrate is 115200.
6. Je zou regels als `distance_cm=XX` moeten zien.

## platformio.ini
De baudrate en optionele poort staan in `platformio.ini`. Als auto-detect niet werkt, zet je eigen poort daar neer, bv.
```ini
upload_port = COM5
monitor_port = COM5
```

## Licentie
MIT
