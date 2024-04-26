#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

#define servo1Pin 11 // Top
#define servo2Pin 2  // Left
#define servo3Pin 3  // Right

void movePlankUp() {
  for (int pos = servo1.read(); pos >= 0; pos -= 1) {
    servo1.write(pos);
    delay(15); // Adjust this delay for slower movement
  }
  // Move the plank down by an additional 70 degrees
  for (int pos = 0; pos >= -70; pos -= 1) {
    servo1.write(pos);
    delay(15); // Adjust this delay for slower movement
  }
}

void movePlankDown() {
  for (int pos = servo1.read(); pos <= 180; pos += 1) {
    servo1.write(pos);
    delay(15); // Adjust this delay for slower movement
  }
}

void openClaw() {
  servo3.write(230);
  servo2.write(0);
}

void closeClaw() {
  servo3.write(230);
  servo2.write(0);
  
}

void setup() {
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  movePlankUp();
}

void loop() {
  movePlankDown();
  delay(2000);
  openClaw();
  delay(2000);

  closeClaw();
  delay(2000);
  movePlankUp();
  delay(2000);
}