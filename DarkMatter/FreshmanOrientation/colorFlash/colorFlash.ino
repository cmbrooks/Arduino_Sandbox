int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int redVal;
int greenVal;
int blueVal;

int lastTime;
int currTime;
int elapsedTime;

int colorVals[][3] = {
  {HIGH,LOW,LOW}, //Red
  {HIGH,HIGH,LOW}, //Yellow
  {LOW,HIGH,LOW}, //Green
  {LOW,HIGH,HIGH}, //Blue-Green
  {LOW,LOW,HIGH}, //Blue
  {HIGH,LOW,HIGH} //Purple
};

int colorIndex = 0;


/*Begin Program*/
void setup(){
  Serial.begin(9600);
  
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop(){
  
  currTime = millis();
  elapsedTime = currTime - lastTime;
  
  if (elapsedTime < 1000){
    //Continue current color
    redVal = colorVals[colorIndex][0];
    greenVal = colorVals[colorIndex][1];
    blueVal = colorVals[colorIndex][2];
  }else{
    lastTime = millis();
    //Change to next color
    if (colorIndex != 5){
      colorIndex++;
    }else{
      colorIndex = 0;
    }
  }
  
  digitalWrite(redPin,redVal);
  digitalWrite(greenPin,greenVal);
  digitalWrite(bluePin,blueVal);

}
