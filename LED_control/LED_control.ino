//Variables for End Game mode
int blinkSpeed = 3000;

//Variables for Purple Fade mode
int fadeAmount = 5;
int fadeBrightness = 0;

//Variables for Mode changing
String modeList[] = {"solid","fade","colorFade"};
int modeIndex = 0;
String mode;

//Variables for Color Fade mode
int rgbFade[3];
int colorOut = 0;
int i = 0;

//Initializes pin numbers
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

//Timing Variables
int loopTime;
int lap;

void setup(){
  
  Serial.begin(9600);
  
  pinMode(2,INPUT); //Signal from NXT
  pinMode(3,INPUT); //Mode Change
  
  pinMode(redPin,OUTPUT); //Red
  pinMode(greenPin,OUTPUT); //Green
  pinMode(bluePin,OUTPUT); //Blue
  
  //Initializes at Red
  rgbFade[0] = 255;
  rgbFade[1] = 0;
  rgbFade[2] = 0;
    
  Serial.println("The program has started");
  
}

void loop(){
  
  //refreshes all inputs
  int NXTsignal = digitalRead(2);
  int modeChange = digitalRead(3);
  mode = modeList[modeIndex];
  lap = millis();
  
  if(modeChange == HIGH){
    
    /*
    When the Mode changing button is
    pressed, the mode index increments to
    change to the next mode
    */
    
    if (modeIndex > 1){
      modeIndex = 0;
    }else{
      modeIndex++;
      delay(250);
    }
    
  }
  
  if(mode == "solid"){
    
    //LEDs remain a constant color
    purple();
    
  }else if(mode == "fade"){
    
    //Flades LED in and out
    fadePurple();
    
  }else if(mode == "colorFade"){

    colorFade();
    
  }
  
  if(NXTsignal == HIGH){
    
    //Blinks the LEDs at an increacing pace
    purple(); 
    delay(blinkSpeed);
    off();
    delay(blinkSpeed);
    blinkSpeed = blinkSpeed * .8; //Shortens then next blink
  
  }
  
  loopTime = millis() - lap;  
  printStats();

}  
  


//LED Preset
void off(){
  digitalWrite(redPin,LOW); //LEDs are purple
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
}

void purple(){
  digitalWrite(redPin,HIGH); //LEDs are purple
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,HIGH);
}

void red(){
  digitalWrite(redPin,HIGH); //LEDs are Red
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
}

void blue(){
  digitalWrite(redPin,LOW); //LEDs are Blue
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,HIGH);
}

void green(){

  digitalWrite(redPin,LOW); //LEDs are Green
  digitalWrite(greenPin,HIGH);
  digitalWrite(bluePin,LOW);

}

void fadePurple(){

  analogWrite(redPin, fadeBrightness);    
  analogWrite(bluePin, fadeBrightness);  
  // change the brightness for next time
  fadeBrightness = fadeBrightness + fadeAmount;

  // reverse the direction of the fading 
  if (fadeBrightness == 0 || fadeBrightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
 
  delay(60); 

}

void colorFade(){

  if(colorOut < 3){
  
    int colorIn = colorOut == 2 ? 0 : colorOut + 1;
  
    if(i < 255){
      rgbFade[colorOut]--;
      rgbFade[colorIn]++;
    
      //Write RGB values
      analogWrite(redPin, rgbFade[0]);
      analogWrite(greenPin, rgbFade[1]);
      analogWrite(bluePin, rgbFade[2]);
   
      delay(5);

      i++;      

    }else{
      i = 0;
      colorOut++; 
    }
  
  }else{
    colorOut = 0;
  }
}

void printStats(){
  
  //Prints statistics for troubleshooting
  Serial.print("Button is ");
  Serial.print(digitalRead(3));
  Serial.print("\t");
  
  Serial.print("Mode is ");
  Serial.print(mode);
  Serial.print("\t");
  
  Serial.print("Mode Index is ");
  Serial.print(modeIndex);
  Serial.print("\t");
  Serial.print("\t");
  
  Serial.print("Loop took ");
  Serial.print(loopTime);
  Serial.println(" milliseconds to run");
  
}
