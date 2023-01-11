
#include <Servo.h>

Servo servo;

#define trig 7
#define echo 6

void setup() {
  servo.attach(2);
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(trig,LOW);
  digitalWrite(echo,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo,HIGH);
  distance = ((float) (340 * duration)/10000)/2;

  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 10) { // TODO : change to 10
    servo.write(0);
    Serial.print("Opened");

    delay(10000);
  }
  else {
    servo.write(90);
    }
}
