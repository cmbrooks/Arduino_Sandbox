int blinkSpeed = 3000;
int fadeAmount = 5;
int brightness = 0;

void setup(){

  pinMode(2,INPUT); //Signal from NXT
  pinMode(3,INPUT); //Breathe
  pinMode(9,OUTPUT); //Red
  pinMode(10,OUTPUT); //Green
  pinMode(11,OUTPUT); //Blue
  
}

void loop(){

  int NXTsignal = digitalRead(2);
  int Bumpers = digitalRead(3);
  
  if(NXTsignal == HIGH){
    
    //Blinks the LEDs at an increacing pace when End Game starts
    purple(); 
    delay(blinkSpeed);
    off();
    delay(blinkSpeed);
    blinkSpeed = blinkSpeed * .8; //Shortens then next blink by 3/4
  
  }else if(Bumpers == HIGH){
  
    red();         
    
  }else{
  
    fadePurple();
    
  }
}  
  


//LED Preset Colors
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

void fadePurple(){

  analogWrite(9, brightness);    
  analogWrite(11, brightness);  
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(60); 

}
