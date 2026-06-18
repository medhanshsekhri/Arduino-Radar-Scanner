#include <Servo.h>
long duration = 0;
int distance = 0;
 Servo myServo;
  void setup() {
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  Serial.begin(9600);
  myServo.attach(6);
  myServo.write(90);






}

  void loop() {


for (int angle = 0; angle <=180; angle++)  {
myServo.write(angle);
delay(15);
digitalWrite(9, LOW);
delayMicroseconds(2);
digitalWrite(9, HIGH);
delayMicroseconds(10);
digitalWrite(9, LOW);
duration = pulseIn(10, HIGH);
distance = duration * 0.034 / 2;

if (distance <20){
     digitalWrite(13, HIGH);
  
} else {
  digitalWrite(13, LOW);
}

Serial.print(angle);
Serial.print(",");
Serial.print(distance);
Serial.println(".");
}

for (int angle = 180; angle >=0; angle--)  {
myServo.write(angle);
delay(15);
digitalWrite(9, LOW);
delayMicroseconds(2);
digitalWrite(9, HIGH);
delayMicroseconds(10);
digitalWrite(9, LOW);
duration = pulseIn(10, HIGH);
distance = duration * 0.034 / 2;

if (distance <20){
     digitalWrite(13, HIGH);
  
} else {
  digitalWrite(13, LOW);
}

Serial.print(angle);
Serial.print(",");
Serial.print(distance);
Serial.println(".");
}




}
