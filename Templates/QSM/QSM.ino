/*Setup Variables here*/
String queue = "";

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
  queue = "init*";
}

void loop(){
  
  switch(queue.substring(0, queue.indexOf("*"))){
    
    case init:
      /*Prepare program here*/
      queue += "idle*";
      break;
    
    case idle:
      if (input1){
        queue += "idle*";
      }else if (input2){
        queue += "idle*";
      }else{
        queue += "idle*";
      }   
    
    case case1:
      //Code for case1 here
      queue += "idle*";
      break;
    
    case case2:
      //Code for case2 here
      queue += "idle*";
      break;
      
      /*Remove the residual astrics*/
     queue = queue.substring(1, queue.length);
      
  }

}
