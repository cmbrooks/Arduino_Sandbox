/*Setup Datalogging shdield*/
#include "SD.h"
#include <Wire.h>
#include "RTClib.h"

#define LOG_INTERVAL  1000 // mills between entries
#define ECHO_TO_SERIAL   1 // echo data to serial port
#define WAIT_TO_START    0 // Wait for serial input in setup() 
 
// the digital pins that connect to the LEDs
#define redLEDpin 3
#define greenLEDpin 4
 
// The analog pins that connect to the sensors
#define battPin 0           // analog 0


RTC_DS1307 RTC; // define the Real Time Clock object

// for the data logging shield, we use digital pin 10 for the SD cs line
const int chipSelect = 10;

// the logging file
File logfile;

/*Setup Current sensor*/
#include <Adafruit_INA219.h>
 
Adafruit_INA219 ina219_A;
Adafruit_INA219 ina219_B(0x41);

void error(char *str)
{
  Serial.print("error: ");
  Serial.println(str);
  
  // red LED indicates error
  digitalWrite(redLEDpin, HIGH);
  
  while(1);
}


void setup () {
  /*Start Serial output*/
  Serial.begin(9600);
  Serial.println("The program has begun");
  
  Serial.print("Initializing SD card...");
  /* 
  make sure that the default chip select pin is set to
  output, even if you don't use it:
  */
  pinMode(10, OUTPUT);
  
  /* see if the card is present and can be initialized: */
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    /*don't do anything more:*/
    return;
  }
  Serial.println("card initialized.");
  
  /* create a new file */
  char filename[] = "LOGGER00.CSV";
  for (uint8_t i = 0; i < 100; i++) {
    filename[6] = i/10 + '0';
    filename[7] = i%10 + '0';
    if (! SD.exists(filename)) {
      /* only open a new file if it doesn't exist */
      logfile = SD.open(filename, FILE_WRITE); 
      break;  /*leave the loop!*/
    }
  }
  
  if (!logfile) {
    error("couldnt create file");
  }
  
  Serial.print("Logging to: ");
  Serial.println(filename);
  
  /*Begin Current Sensor*/
  ina219_A.begin();  // Initialize first board (default address 0x40)
  ina219_B.begin();  // Initialize second board with the address 0x41
}

void loop () {
  
  DateTime now;

  // delay for the amount of time we want between readings
  delay((LOG_INTERVAL -1) - (millis() % LOG_INTERVAL));
  
  digitalWrite(greenLEDpin, HIGH);

  // log milliseconds since starting
  uint32_t m = millis();
  logfile.print(m);           // milliseconds since start
  logfile.print(", ");    
#if ECHO_TO_SERIAL
  Serial.print(m);         // milliseconds since start
  Serial.print(", ");  
#endif

  // fetch the time
  now = RTC.now();
  // log time
  logfile.print(now.get()); // seconds since 2000
  logfile.print(", ");
  logfile.print(now.year(), DEC);
  logfile.print("/");
  logfile.print(now.month(), DEC);
  logfile.print("/");
  logfile.print(now.day(), DEC);
  logfile.print(" ");
  logfile.print(now.hour(), DEC);
  logfile.print(":");
  logfile.print(now.minute(), DEC);
  logfile.print(":");
  logfile.print(now.second(), DEC);
#if ECHO_TO_SERIAL
  Serial.print(now.get()); // seconds since 2000
  Serial.print(", ");
  Serial.print(now.year(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print("/");
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.print(now.second(), DEC);
#endif //ECHO_TO_SERIAL


/*Start logging data to file*/

int battReading = analogRead(battPin);

//float rawVoltage = /*convert analog voltage to readable battery voltage*/


logfile.print(", ");
logfile.print(voltage

}
