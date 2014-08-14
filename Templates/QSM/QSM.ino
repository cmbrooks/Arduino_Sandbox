String que[] = {"init"};

void setup(){
  Serial.begin(9600);
  //que.append("init");
}

void loop(){
  que.append("idle");
}
