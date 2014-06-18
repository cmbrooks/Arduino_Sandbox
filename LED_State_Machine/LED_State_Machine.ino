//State setup
int nextState;
int currState;

//Button Setup
int NXTSignal;
int modeChange;
int off;

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

//Setup enum
enum cases
{
  solid,
  fade,
  colorFade,
  initialize,
  idle,
  updateMode,
  updateLEDs,
  leave
};

int byebye;


/*Begin Program*/
void setup(){
  
  Serial.begin(9600);
  
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  
  currState = initialize;
  
  Serial.println("Setup finished");
}


void loop(){
  
  while(byebye == 0){
    
    modeChange = digitalRead(2);
    off = digitalRead(3);
    mode = modeList[modeIndex];
    
    switch(currState){
        
      case initialize: //Initialize
        //code here
        Serial.println("Current Case: Initialize");
        nextState = idle;
        break;
        
      case idle://Idle
        if(modeChange == HIGH){
          nextState = updateMode; //Update Mode
        }else if(off == HIGH){
          nextState = leave;
        }else{
          nextState = currMode;
        }
        Serial.println("Current Case: Idle");
        break;
        
      case updateMode:
        if (modeIndex == 2){
          modeIndex = 0;
        }else{
          modeIndex++;
        } 
        delay(500);
                
        currMode = modeIndex;
        nextState = currMode;
        Serial.println("Current Case: Update Mode");
        break;
        
      case updateLEDs: //Update LEDs
        analogWrite(redPin,redVal);
        analogWrite(greenPin,greenVal);
        analogWrite(bluePin,blueVal);
        
        nextState = idle; //Idle State
        Serial.println("Current Case: Update LEDs");
        break;
      
      case leave:
        byebye = 1;
        Serial.println("LEDs are now turned off");
        delay(500);        
        break;
      
      case solid: //Mode: Solid purple
        redVal = 255;
        greenVal = 0;
        blueVal = 255;
        
        nextState = updateLEDs;
        currMode = solid;
        Serial.println("Current Case: Mode: Solid Purple");
        break;
      
      case fade: //Fade Purple
        
        fadeBrightness = fadeBrightness + fadeAmount;
        
        // reverse the direction of the fading 
        if (fadeBrightness == 0 || fadeBrightness == 255) {
          fadeAmount = -fadeAmount;
        }
        
        redVal = fadeBrightness;
        greenVal = 0;
        blueVal = fadeBrightness;
        
        nextState = updateLEDs;
        currMode = fade;
        Serial.println("Current Case: Mode: Fade Purple");
        break;
      
      case colorFade://colorFade
        
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
      
        nextState = updateLEDs;
        currMode = colorFade;
        Serial.println("Current Case: Mode: Color Fade");
        break;
    }
    
    currState = nextState;
    
  }
  
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
  
}
