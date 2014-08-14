#include <Servo.h>

int thresh = 400;

int greenSensPin = A0;
int greenVal;
boolean lightOn = false;
int lightSwitch = 7;

void setup(){
  Serial.begin(9600);
  Serial.println("Light off");
}

void loop(){
 
  greenVal = analogRead(greenSensPin);
  Serial.print("Green light value: ");
  Serial.println(greenVal);
  
  if (lightOn > thresh){
    if (lightOn == false){
      digitalWrite(lightSwitch,HIGH);
      Serial.println("Light on");
      if (analogRead(greenSensPin) > thresh){
        Serial.print("Green still on");
      }else{
        lightOn = true;
      }
    }else{
      digitalWrite(lightSwitch,LOW);
      lightOn = false;
      Serial.println("Light off");
      if (analogRead(greenSensPin) > thresh){
        Serial.print("Green still on");
      }else{
        lightOn = true;
      }
    }
  }else{
    Serial.println("No change");
  }
}
