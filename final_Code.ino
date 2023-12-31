#include <Servo.h>
#include "Talkie.h"
#include "Vocab_US_Large.h"
int m;
Talkie voice;
Servo Servodemo;
int servopin = 8;
int trigpin = 5;
int echopin = 6;
int d;
long duration, distance;
void setup()
{
  Servodemo.attach(servopin);
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.println("3");

}

void loop()
{
  for (int i = 0; i <= 180; i + 90)
  {
    Serial.println("3");
    Servodemo.write(90);
    Serial.println("5");
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigpin, LOW);
    duration = pulseIn(echopin, HIGH);
    distance = (duration / 2) / 29.1;
    Serial.print(distance);
    Serial.println("CM");
    if (distance <= 10)
    {
      Serial.println("6");
      message(d);
    }

  }
  delay(1000);

}
delay(100);

for (int i = 180; i >= 0; i - 90)
{
  Serial.println("4");
  Servodemo.write(0);
  Serial.println("5");
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println("CM");
  if (distance <= 10)
  {
    Serial.println("6");
    message(d);
  }

}

delay(1000);

}

int ultra(int a)
{
  Serial.println("5");
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println("CM");
  if (distance <= 10)
  {
    Serial.println("6");
    return (a);
  }
  return 0;
}

void message(int x)
{
  m = x;
  if (m == 0)
  {
    for (int j = 0; j < 3; j++)
    {
      Serial.println("6");
      voice.say(sp2_DANGER);
      voice.say(sp2_DANGER);
      delay(20);
      voice.say(sp2_DANGER);
      voice.say(sp2_ON);
      voice.say(sp2_LEFT);
    }
  }
  else if (m == 90)
  { for (int j = 0; j < 3; j++)
    {
      Serial.println("7");
      voice.say(sp2_DANGER);
      voice.say(sp2_DANGER);
      delay(20);
      voice.say(sp2_ALERT);
      voice.say(sp2_ALERT);
    }
  }
  else if (m == 180)
  {
    for (int j = 0; j < 3; j++)
    {
      Serial.println("8");
      voice.say(sp2_DANGER);
      voice.say(sp2_DANGER);
      delay(20);
      voice.say(sp2_DANGER);
      voice.say(sp2_ON);
      voice.say(sp2_RIGHT);
    }
  }
}
