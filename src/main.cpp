#include <Arduino.h>

// Pins for JSN-SR04T on Arduino Uno
// Change these to the pins you actually use.
const uint8_t PIN_TRIG = 9;
const uint8_t PIN_ECHO = 8;

long readUltrasonicCM() {
  // Send a 10µs pulse to trigger the sensor
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Read the echo pulse width (timeout 30 ms ~ 5 m)
  long duration = pulseIn(PIN_ECHO, HIGH, 60000UL); // was 30000UL
  if (duration <= 0) return -1; // timeout / invalid

  // Convert time to distance:
  // Sound speed ~ 343 m/s => 29.1 µs/cm roundtrip; 58 µs per cm (to target and back)
  long cm = duration / 58L;
  return cm;
}

float readUltrasonicMM() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long duration = pulseIn(PIN_ECHO, HIGH, 60000UL);
  if (duration <= 0) return -1;
  float mm = duration * 0.343 / 2.0;
  return mm;
}

long stableUltrasonicCM(int attempts = 3) {
  for (int i = 0; i < attempts; i++) {
    long d = readUltrasonicCM();
    if (d > 0) return d;
    delay(100);
  }
  return -1;
}

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  Serial.begin(115200);
  // Wait for Serial on native USB boards; harmless on Uno
  while (!Serial) { ; }
  Serial.println(F("JSN-SR04T (PlatformIO) – ready"));
  Serial.println(F("Hoera!")); // Toegevoegde
}

void loop() {
  const int samples = 5;   // simple median-ish smoothing
  long vals[samples];
  for (int i = 0; i < samples; i++) {
    vals[i] = readUltrasonicCM();
    delay(50);
  }
  // simple sort
  for (int i = 0; i < samples - 1; i++) {
    for (int j = i + 1; j < samples; j++) {
      if (vals[j] < vals[i]) {
        long t = vals[i]; vals[i] = vals[j]; vals[j] = t;
      }
    }
  }
  long d = vals[samples/2]; // median

  if (d < 0) {
    Serial.println(F("distance_cm=NaN (timeout)"));
  } else {
    long d_mm = d * 10; // afstand in millimeter
    Serial.print(F("distance_cm="));
    Serial.print(d);
    Serial.print(F(" ; distance_mm="));
    Serial.println(d_mm);
  }
  delay(300);
}
