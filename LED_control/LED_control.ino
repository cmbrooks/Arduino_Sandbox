int blinkSpeed = 3000;
int fadeAmount = 5;
int fadeBrightness = 0;
char* modeList[] = {"solid","fade","colorCycle"};

void setup(){
  
  Serial.begin(9600);
  pinMode(2,INPUT); //Signal from NXT
  pinMode(3,INPUT); //Breathe
  pinMode(9,OUTPUT); //Red
  pinMode(10,OUTPUT); //Green
  pinMode(11,OUTPUT); //Blue
  
  Serial.println("Hello World");
}

void loop(){

  int NXTsignal = digitalRead(2);
  int modeChange = digitalRead(3);
  int modeIndex = 0;
  String mode = modeList[modeIndex];
  
  if(modeChange == HIGH){
    
    /***
    *When the Mode changing button is
    *pressed, the mode index increments to
    *change to the next mode
    ***/
    modeIndex = modeIndex++;
    delay(250);
  }
  
  if(mode == "solid"){
    
    //LEDs remain a constant color
    purple();
    Serial.print("Mode is ");
    Serial.println(mode);
    
  }else if(mode == "fade"){
    
    //Flades LED in and out
    fadePurple();
    Serial.print("Mode is ");
    Serial.println(mode);
    
  }else if(mode == "colorCycle"){
    
    //Changes LED color every 2 seconds
    red();
    delay(2000);
    blue();
    delay(2000);
    green();
    delay(2000);
    
    Serial.print("Mode is ");
    Serial.println(mode);
    
  }
  
  if(NXTsignal == HIGH){
    
    //Blinks the LEDs at an increacing pace
    purple(); 
    delay(blinkSpeed);
    off();
    delay(blinkSpeed);
    blinkSpeed = blinkSpeed * .8; //Shortens then next blink
  
  }
}  
  


//LED Preset
void off(){
  digitalWrite(9,LOW); //LEDs are purple
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

void purple(){
  digitalWrite(9,HIGH); //LEDs are purple
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}

void red(){
  digitalWrite(9,HIGH); //LEDs are Red
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

void blue(){
  digitalWrite(9,LOW); //LEDs are Blue
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}

void green(){

  digitalWrite(9,LOW); //LEDs are Green
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);

}

void fadePurple(){

  analogWrite(9, fadeBrightness);    
  analogWrite(11, fadeBrightness);  
  // change the brightness for next time
  fadeBrightness = fadeBrightness + fadeAmount;

  // reverse the direction of the fading 
  if (fadeBrightness == 0 || fadeBrightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
 
  delay(60); 

}
