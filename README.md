# Arduino Uno + JSN-SR04T (PlatformIO)

Eenvoudig PlatformIO-project voor het uitlezen van een JSN-SR04T ultrasone sensor met een Arduino Uno.

Dit is een deelproject van "Heltec Lora Boatreadings" om de afstandsmeter die later in de boot gemonteerd wordt even te testen.

## Hardware
- Arduino Uno (of compatibele clone)
- JSN-SR04T (waterdichte ultrasone sensor, 5V)
- Bekabeling (VCC -> 5V, GND -> GND, TRIG -> D9, ECHO -> D8 )

> Let op: De Uno is 5V, de JSN-SR04T ook. Bij andere borden (3.3V) kan een spanningsdeler/level shifter nodig zijn.


## Foto's
Arduino plus JSN-SR04T met daarvan de sensor in een aluminium buis. 
![Arduino Uno connected to JSN-SR04T ultrasonic sensor with colored jumper wires on a wooden table, showing clear wiring between VCC, GND, TRIG, and ECHO pins; background includes scattered electronic components and a neutral workspace atmosphere]

De buis heeft gaatjes onderaan in de zijkant om het bilgewater door te laten
Ook zijn er kleinere gaatjes vlakbij de sensor om de buis te beluchten; hopelijk voorkom ik daarme dat de sensor later stukgaat door vocht.
Bovenop zit een witte klodder (niet zo netjes gedaan) siliconenkit om de sensor te beschermen tegen regen (in mijn boot komt deze sensor in directe buitenlucht te zitten namelijk).
![JSN-SR04T ultrasonic sensor mounted inside an aluminum tube with small holes at the bottom for bilge water entry and additional ventilation holes near the sensor; the top is sealed with a visible layer of white silicone sealant for weather protection. The setup rests on a wooden table surrounded by electronic components and tools, creating a practical and focused workspace atmosphere.]


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
