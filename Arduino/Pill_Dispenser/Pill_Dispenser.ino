#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "U8x8lib.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
#include <DS1302.h>
int Hour;
int Min;
int pset = 46; // pushbutton for setting alarm
int phour = 48; // pushbutton for hour
int pmin = 50; // pushbutton for minutes
int pexit = 52; // pushbutton for exit of set alarm
int buzzer = 5;
int h;
int m;
int buttonforset = 0; // pushbutton state for setting alarm
int buttonforhour = 0; // pushbutton state for hour
int buttonformin = 0;// pushbutton state for minutes
int buttonforexit = 0; // pushbutton state for exit of set alarm
int activate=0;
int go =0;
 Time t;

#define OLED_RESET 4 // this value resets the OLED
U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(OLED_RESET);

// Init the DS1302
DS1302 rtc(2, 3, 4);

void timeSetup()
{
 pinMode(pset, INPUT);
 pinMode(phour, INPUT);
 pinMode(pmin, INPUT);
 pinMode(pexit, INPUT);
 // Set the clock to run-mode, and disable the write protection
 rtc.halt(false);
 rtc.writeProtect(false);

 // Setup LCD to 16x2 characters
 
}

void timeLoop()
{
  showMessage(rtc.getTimeStr(),0,true);
  showMessage(rtc.getDateStr(),1,true);
  showMessage(rtc.getDOWStr(),2,true);
  t = rtc.getTime();
  Hour = t.hour;
  Min = t.min;
  
  if (activate == 0) {
    buttonforset = digitalRead(pset);
  } // setting button pressed

  if (buttonforset == HIGH) {
    activate = 1;
    u8x8.clearDisplay(); 
  }

  while(activate == 1){

    showMessage("Set Alarm",0,true);

    showMessage("Hour = ",1,true);

    showMessage("Min = ",3,true);
  
    buttonforhour = digitalRead(phour); // set hour for alarm
  
    if (buttonforhour == HIGH){
      h++;
      
      u8x8.setCursor(7, 1);
      u8x8.print(h);
    
      if (h>23){ 
        h=0;
        u8x8.clearDisplay();
      }
      delay(100); 
    }
    
    buttonformin = digitalRead(pmin); // set minutes for alarm
  
    if (buttonformin == HIGH){
      m++;

      u8x8.setCursor(7, 3);
      u8x8.print(m);
      
      if (m>59){
        m=0; 
        u8x8.clearDisplay();
      }
      delay(100); 
    }

    buttonforexit = digitalRead(pexit); // exit from set alarm mode
    if (buttonforexit == HIGH){
      activate = 0;
      u8x8.clearDisplay();
    }
  }
 
  if (Hour== h && Min== m) {
    while(go==0){
     runStepper();
      if(runSense()==true){
       go=1;
      }
      Serial.println("hi");
    }
   tone(6,400,300);
   delay (500);
  }
  if(Hour!=h && Min!=m){
    go=0;
  }
  delay(500);
  u8x8.clearDisplay();
 
}



// ==== Message VARs ====== //
char in_text[64];                // Character buffer
int in_text_index = 0;


void initDisplay() {
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_r);
  u8x8.setCursor(0, 0);
}
// ----------------------------------------------------------------
// A function to write a message on the display
// "clearDisplay" specifies if everything should be wiped or not
// ----------------------------------------------------------------
void showMessage(const char * message, int row, bool cleardisplay) {
  u8x8.setCursor(0, row);
  u8x8.print(message);
}
void receiveMessage(){
  if (Serial.available() > 0) { 
    char incomingChar = Serial.read();// read byte from serial
    Serial.println(incomingChar);
    if (incomingChar=='\n'){
      //show the in_text with show message
      Serial.println(" NOOOO");
      showMessage(in_text, 1, true);
      //reset the in_text index back to 0
      in_text_index=0;
      memset(in_text,0,20); // this will clear the in_text buffer
    }
    else{
      //assign in_text[index] to the incoming char
      in_text[in_text_index]=incomingChar;
      //increment the index
      in_text_index++;
    }
  }
}
void setup(){
  Serial.begin(9600);
  initDisplay();
  timeSetup();
  setupSense();
}
void loop(){
  //Serial.print(2);
  //receiveMessage();
  timeLoop();
  showMessage("hello",1,true);
}
//
//
//
//
