int greenSensor;
int greenSensorPin = A0;
int greenSensorVal;
int greenPin = 10;

void setup(){
  Serial.begin(9600);
}

void loop(){
  //analogWrite(greenPin,255);
  greenSensorVal = analogRead(greenSensorPin);
  Serial.println(greenSensorVal);
}
