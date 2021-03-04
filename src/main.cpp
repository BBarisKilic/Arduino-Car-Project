#include <Arduino.h>

//Defines the pins used
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define ENA 5
#define ENB 11
#define headlight 12
#define tailLight 13
#define horn 2
//This example code will be updated. Then you will be able to change speed through ArduBlu.
#define speed 200

char state;

//A method for the go forward.
void forward()
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.flush();
}

//A method for the go back.
void back()
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.flush();
}

//A method for the go right.
void right()
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.flush();
}

//A method for the go left.
void left()
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.flush();
}

//A method for the stop.
void stop()
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(horn, LOW);
  Serial.println("stop!");
  Serial.flush();
}

void setup()
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(headlight, OUTPUT);
  pinMode(tailLight, OUTPUT);
  pinMode(horn, OUTPUT);
  stop();
}

void loop()
{
  if (Serial.available() > 0)
  {
    state = Serial.read();
  }

  if (state == 'f' || state == 'F')
  {
    forward();
  }
  else if (state == 'b' || state == 'B')
  {
    back();
  }
  else if (state == 'r' || state == 'R')
  {
    right();
  }
  else if (state == 'l' || state == 'L')
  {
    left();
  }
  else if (state == ']')
  {
    stop();
  }
  else if (state == 'h' || state == 'H')
    digitalWrite(horn, HIGH);

  else if (state == 'W')
    digitalWrite(headlight, HIGH);

  else if (state == 'w')
    digitalWrite(headlight, LOW);

  else if (state == 'T')
    digitalWrite(tailLight, HIGH);

  else if (state == 't')
    digitalWrite(tailLight, LOW);
}