#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
#include <DS1302.h>
int Hour;
int Min;
int pset = 8; // pushbutton for setting alarm
int phour = 9; // pushbutton for hour
int pmin = 10; // pushbutton for minutes
int pexit = 11; // pushbutton for exit of set alarm
int buzzer = 6;
int h;
int m;
int buttonforset = 0; // pushbutton state for setting alarm
int buttonforhour = 0; // pushbutton state for hour
int buttonformin = 0;// pushbutton state for minutes
int buttonforexit = 0; // pushbutton state for exit of set alarm
int activate=0;
 Time t;

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

// The following lines can be commented out to use the values already stored in the DS1302
 //rtc.setDOW(SATURDAY); // Set Day-of-Week to FRIDAY
 //rtc.setTime(10, 0, 0); // Set the time to 12:00:00 (24hr format)
 //rtc.setDate(11, 11, 2017); // Set the date to August 6th, 2010
}

void timeLoop()
{
  showMessage(rtc.getTimeStr(),0,true);
  t=rtc.getTime();
}
