/*Setup Variables here*/
int currQue = 0;
int writeQue = 0;

/*Fill enum with all case names*/
enum cases{
  init,
  idle,
  case1,
  case2,
  leave
};

/*Begin Program*/
void setup(){
  Serial.begin(9600);
  String que[writeQue] = init;
  writeQue++;
}

void loop(){
  
  switch(que[currQue]){
    
    case init:
      /*Prepare program here*/
      nextState = idle;
      break;
    
    case idle:
      if (input1){
        que[writeQue] = case1;
      }else if (input2){
        que[writeQue] = case2;
      }else{
        que[writeQue] = idle;
      }   
    
    case case1:
      //Code for case1 here
      break;
    
    case case2:
      //Code for case2 here
      break;
      
  }
}
