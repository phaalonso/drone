#include <Arduino.h>
#line 1 "/home/pedro/dev/arduino/blink.ino"
const int PIN = 9;

#line 3 "/home/pedro/dev/arduino/blink.ino"
void setup();
#line 7 "/home/pedro/dev/arduino/blink.ino"
void loop();
#line 3 "/home/pedro/dev/arduino/blink.ino"
void setup() {
	pinMode(PIN, OUTPUT);
}

void loop() {
	digitalWrite(PIN, HIGH);
	delay(1000);
	digitalWrite(PIN, LOW);
	delay(1000);
}

