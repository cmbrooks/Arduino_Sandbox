/*Setup Variables here*/
int nextState;
int currState;

/*Fill enum with all case names*/
enum cases{
  
  init;
  idle;
  case1;
  case2;
  leave;

};

/*Begin Program*/
void setup(){
  Serial.begin(9600);
  currState = init;
}

void loop(){
  switch(currState){
    
    case init:
      /*Prepare program here*/
      nextState = idle;
      break;
    
    case idle:
      if (input1){
        nextState = case1;
      }else if (input2){
        nextState = case2;
      }else{
        nextState = idle;
      }   
    
  }
  
  currState = nextState;
}
