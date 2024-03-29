#include <Servo.h>

#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
#define MOTOR_PIN 9

Servo motor;

void setup() {
  Serial.begin(9600);
  Serial.println("Program begin...");
  Serial.println("This program will calibrate the ESC.");

  motor.attach(MOTOR_PIN);

  Serial.println("Calibrating Maximum Signal");
  Serial.println("Turn on power source, then wait 2 seconds and press any key + <enter>");
  motor.writeMicroseconds(MAX_SIGNAL);

  // Wait for input
  while (!Serial.available());
  Serial.read();

  // Send min output
  Serial.println("Calibrating Minimum Signal");
  motor.writeMicroseconds(MIN_SIGNAL);

}

void loop() {  

}
