//State setup
int nextState;
int currState;

//Button Setup
int NXTSignal;
int modeChange;

//Variables for Mode changing
String modeList[] = {"solid","fade","colorFade"};
String mode;
int modeIndex = 0;
int currMode;

//LED setup
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int redVal;
int greenVal;
int blueVal;

//Variables for Color Fade mode
int rgbFade[3];
int colorOut = 0;
int i = 0;

//Variables for End Game mode
int blinkSpeed = 3000;

//Variables for Purple Fade mode
int fadeAmount = 5;
int fadeBrightness = 0;


/*Begin Program*/
void setup(){
  
  Serial.begin(9600);
  
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  
  currState = 1;
  
  Serial.println("Setup finished");
}


void loop(){
 
  Serial.println("Main loop started");
  
  while(currState != 5){
    
    modeChange = digitalRead(2);
    mode = modeList[modeIndex];
    
    switch(currState){
        
      case 1: //Initialize
        //code here
        Serial.println("Current Case: Initialize");
        nextState = 2;
        break;
        
      case 2://Idle
        if(modeChange == HIGH){
          nextState = 3; //Update Mode
        }else{
          nextState = currMode;
        }
        Serial.println("Current Case: Idle");
        break;
        
      case 3://Update Mode
        if (modeIndex > 1){
          modeIndex = 0;
        }else{
          modeIndex++;
          delay(250);
        } 
        
        currMode = modeIndex * 100;
        nextState = currMode;
        Serial.println("Current Case: Update Mode");
        break;
        
      case 4: //Update LEDs
        analogWrite(redPin,redVal);
        analogWrite(greenPin,greenVal);
        analogWrite(bluePin,blueVal);
        
        nextState = 2; //Idle State
        Serial.println("Current Case: Update LEDs");
        break;
      
      case 5: //exit
        break;
      
      case 0: //Mode: Solid purple
        redVal = 255;
        greenVal = 0;
        blueVal = 255;
        
        nextState = 4;
        Serial.println("Current Case: Mode: Solid Purple");
        break;
      
      case 100: //Fade Purple
        
        fadeBrightness = fadeBrightness + fadeAmount;
        
        // reverse the direction of the fading 
        if (fadeBrightness == 0 || fadeBrightness == 255) {
          fadeAmount = -fadeAmount;
        }
        
        redVal = fadeBrightness;
        greenVal = 0;
        blueVal = fadeBrightness;
        
        nextState = 4;
        Serial.println("Current Case: Mode: Fade Purple");
        break;
      
      case 200://colorFade
        
        if(colorOut < 3){
  
          int colorIn = colorOut == 2 ? 0 : colorOut + 1;
          
          //variable i is set to 255/increment to RGB
          if(i < 51){
            
            //Increments 5 up and down each loop
            rgbFade[colorOut] -= 5;
            rgbFade[colorIn] += 5;
          
            //Write RGB values
            redVal = rgbFade[0];
            greenVal = rgbFade[1];
            blueVal = rgbFade[2];
         
            delay(5);
            i++;      
          }else{
            i = 0;
            colorOut++; 
          }
          
        }else{
          colorOut = 0;
        }
      
        nextState = 4;
        Serial.println("Current Case: Mode: Color Fade");
        break;
    }
    
    currState = nextState;
    
  } 
}
