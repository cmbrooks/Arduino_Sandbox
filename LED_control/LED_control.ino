//initializes all variables for later loops
int blinkSpeed = 3000;
int fadeAmount = 5;
int fadeBrightness = 0;
char* modeList[] = {"solid","fade","colorCycle"};
int modeIndex = 0;
int rgbFade[3];

//Initializes pin numbers
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup(){
  
  Serial.begin(9600);
  
  pinMode(2,INPUT); //Signal from NXT
  pinMode(3,INPUT); //Mode Change
  
  pinMode(redPin,OUTPUT); //Red
  pinMode(greenPin,OUTPUT); //Green
  pinMode(bluePin,OUTPUT); //Blue
  
  Serial.println("The program has started");
  
}

void loop(){
  
  //refreshes all inputs
  int NXTsignal = digitalRead(2);
  int modeChange = digitalRead(3);
  String mode = modeList[modeIndex];
  
  if(modeChange == HIGH){
    
    /***
    When the Mode changing button is
    pressed, the mode index increments to
    change to the next mode
    ***/
    
    if (modeIndex > 2){
      modeIndex = 0;
    }else{
      modeIndex = modeIndex + 1;
      delay(500);
    }
    
  }
  
  if(mode == "solid"){
    
    //LEDs remain a constant color
    purple();
    
  }else if(mode == "fade"){
    
    //Flades LED in and out
    fadePurple();
    
  }else if(mode == "colorCycle"){
    
    //Initializes at Red
    rgbFade[0] = 255;
    rgbFade[1] = 0;
    rgbFade[2] = 0;
    
    for(int colorOut = 0; colorOut < 3; colorOut += 1){
      /***
      Color in is equal to colorOut + 1 if colorOut
      does not equal 2, otherwise, it is equal to 0
      ***/
      int colorIn = colorOut == 2 ? 0 : colorOut + 1;
      
      //Increment colorIn PWM value, and decrement colorOut value
      for(int i = 0; i < 255; i += 1){
        
        rgbFade[colorOut] -= 1;
        rgbFade[colorIn] += 1;
        
        //Write RGB values
        analogWrite(redPin, rgbFade[0]);
        analogWrite(greenPin, rgbFade[1]);
        analogWrite(bluePin, rgbFade[2]);
        
        delay(5);
      
      }
    }
  }
  
  if(NXTsignal == HIGH){
    
    //Blinks the LEDs at an increacing pace
    purple(); 
    delay(blinkSpeed);
    off();
    delay(blinkSpeed);
    blinkSpeed = blinkSpeed * .8; //Shortens then next blink
  
  }
  
  Serial.print("Button is ");
  Serial.print(digitalRead(3));
  Serial.print("\t");
  
  Serial.print("Mode is ");
  Serial.print(mode);
  Serial.print("\t");
  
  Serial.print("Mode Index is ");
  Serial.println(modeIndex);
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
