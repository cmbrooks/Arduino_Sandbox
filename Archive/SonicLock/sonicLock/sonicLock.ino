#include <Servo.h>

int thresh = 400;

Servo lock;
/*
Locked Value: 130
Unlocked Value: 30
*/

int greenSensPin = A0;
int greenVal;
boolean locked = true;

void setup(){
  Serial.begin(9600);
  lock.attach(3);
  lock.write(130);
}

void loop(){
 
  greenVal = analogRead(greenSensPin);
  Serial.print("Green light value: ");
  Serial.println(greenVal);
  
  if (greenVal > thresh){
    if (locked == true){
      lock.write(30);
      Serial.println("Box unlocked");
      if (analogRead(greenSensPin) > thresh){
        Serial.print("Green still on");
      }else{
        locked = false;
      }
    }else{
      lock.write(130);
      Serial.println("Box locked");
      if (analogRead(greenSensPin) > thresh){
        Serial.print("Green still on");
      }else{
        locked = true;
      }
    }
  }else{
    Serial.println("No change");
  }
}
