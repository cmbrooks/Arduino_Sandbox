/*Setup Variables here*/
int que[10];
int writeQue = 1;

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
  que[0] = init;
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
        writeQue++;
      }else if (input2){
        que[writeQue] = case2;
        writeQue++;
      }else{
        que[writeQue] = idle;
        writeQue++;
      }   
    
    case case1:
      //Code for case1 here
      que[writeQue] = idle;
      writeQue++;
      break;
    
    case case2:
      //Code for case2 here
      que[writeQue] = idle;
      writeQue++;
      break;
      
  }
  
  for(int x = 1; x < 10; x++){
    que[x-1] = que[x];

}
