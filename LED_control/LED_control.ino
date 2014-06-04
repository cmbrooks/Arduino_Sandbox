char mode = "t"; //"t" as in Teleop

void setup(){

  pinMode(2,INPUT); //Signal from NXT
  pinMode(3,OUTPUT); //Red
  pinMode(4,OUTPUT); //Green
  pinMode(5,OUTPUT); //Blue
  
}

void loop(){

  int NXTsignal = digitalRead(2);
  int blinkSpeed = 2000;
  
  //Changes game mode to end game when NXT sends signal
  if(NXTsignal == HIGH){
    mode = "e"; //"e" as in End Game
    
  }
  
  //In teleop mode, LEDs are constantly purple
  if(mode == "t"){
    digitalWrite(3,HIGH);
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
    
    blinkSpeed = blinkSpeed * .75 //Shortens then next blink by 3/4
    
  }
}
