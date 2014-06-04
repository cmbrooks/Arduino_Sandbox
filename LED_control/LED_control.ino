int blinkSpeed = 3000;

void setup(){

  pinMode(2,INPUT); //Signal from NXT
  pinMode(3,OUTPUT); //Red
  pinMode(4,OUTPUT); //Green
  pinMode(5,OUTPUT); //Blue
  
}

void loop(){

  int NXTsignal = digitalRead(2);

  //In teleop mode, LEDs are constantly purple
  if(NXTsignal == LOW){
    digitalWrite(3,HIGH); //LEDs are purple
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
  }
  
  else{
    
    //Blinks the LEDs at an increacing pace when End Game starts

    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    
    delay(blinkSpeed);
    
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    
    delay(blinkSpeed);
    
    blinkSpeed = blinkSpeed * .8; //Shortens then next blink by 3/4
    
  }
}
