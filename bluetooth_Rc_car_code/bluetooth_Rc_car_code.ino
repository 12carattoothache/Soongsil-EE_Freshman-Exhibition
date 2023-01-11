#include <AFMotor.h>
#include <SoftwareSerial.h>

const int rxPin = A0;
const int txPin = 2;

SoftwareSerial mySerial(rxPin, txPin); // RX, TX

AF_DCMotor motor1(2);
AF_DCMotor motor2(2);
int speed = 150;

void setup() {
  mySerial.begin(9600);
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  if (mySerial.available()) {
    char ch = mySerial.read();

    switch (ch) {
      case 'w':
          motor1.run(FORWARD);
          motor2.run(FORWARD);
          break;
      case 's':
          motor1.run(BACKWARD);
          motor2.run(BACKWARD);
          break;
      case 'a':
          motor1.run(BACKWARD);
          motor2.run(FORWARD);
          break;
      case 'd':
          motor1.run(FORWARD);
          motor2.run(BACKWARD);
          break;
      case 'h':
          motor1.run(RELEASE);
          motor2.run(RELEASE);
          break;
      case 'o':
          motor1.run(RELEASE);
          motor2.run(RELEASE);
          break;
      case 'p':
          motor1.run(FORWARD);
          motor2.run(RELEASE);
          break;
      case 'm':
          speed += 10;
          if (speed >= 250) speed = 250;
          motor1.setSpeed(speed);
          motor2.setSpeed(speed);
          break;
      case 'n':
          speed -= 10;
          if (speed <= 0) speed = 0;
          motor1.setSpeed(speed);
          motor2.setSpeed(speed);
          break;
      }
    }

}
