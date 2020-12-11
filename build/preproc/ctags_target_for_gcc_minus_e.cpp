# 1 "/home/pedro/dev/arduino/blink.ino"
const int PIN = 9;

void setup() {
 pinMode(PIN, 0x1);
}

void loop() {
 digitalWrite(PIN, 0x1);
 delay(1000);
 digitalWrite(PIN, 0x0);
 delay(1000);
}
