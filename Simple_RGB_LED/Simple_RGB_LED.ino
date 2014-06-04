void setup(){
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop(){
  
  int button = digitalRead(2);
  int Red = 3;
  int Green = 4;
  int Blue = 5;
  
  if(button == HIGH){
    digitalWrite(Red,HIGH);
    digitalWrite(Green,LOW);
    digitalWrite(Blue,HIGH);
  }
  
  else{
    digitalWrite(Red,HIGH);
    digitalWrite(Green,LOW);
    digitalWrite(Blue,LOW);    
  }
}
