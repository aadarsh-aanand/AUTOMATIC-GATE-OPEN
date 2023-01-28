#include <Arduino.h>
#include <Servo.h>
int ir = 2;
int led = 13;
int button = 4;
Servo myservo1;

void setup()
{
  Serial.begin(9600);
  pinMode(ir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  myservo1.attach(6); // ALWAYS CONNECTED TO PWM PINS
}

void loop()
{
  int irvalue = digitalRead(ir);
  int val = digitalRead(button);
  Serial.print(val);
  Serial.print(" && ");
  Serial.println(irvalue);
  if (irvalue == 0 || val == 1)
  {
    digitalWrite(led, 1);
    myservo1.write(90);
    delay(2000);
  }
  else
  {
    digitalWrite(led, 0);
    myservo1.write(0);
  }
}