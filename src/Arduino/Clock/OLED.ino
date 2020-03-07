// ==== Message VARs ====== //
char in_text[64];                // Character buffer
int in_text_index = 0;

// ==== Message CODE ====== //
// OLED library includes
#include "U8x8lib.h"
#include <Wire.h>

// OLED setup
#define OLED_RESET 4 // this value resets the OLED
U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(OLED_RESET);

void initDisplay() {
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_r);
  u8x8.setCursor(0, 0);
}
// ----------------------------------------------------------------
// A function to write a message on the display
// "row" specifies which row to print on... 1, 2, 3, etc.
// "clearDisplay" specifies if everything should be wiped or not
// ----------------------------------------------------------------
void showMessage(const char * message, int row, bool cleardisplay) {
  if(cleardisplay){
    u8x8.clearDisplay();
  }
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
