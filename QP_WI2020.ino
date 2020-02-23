#include <RTC.h>

int buttonUpPin = 2;
int buttonDownPin = 3;
int buttonOkPin = 4;
int SwitchPin = 5;
int ledPin = 6;
int motorPin = 13;

int buttonUpState;
int buttonDownState;
int buttonOkState;
int SwitchState;
int ledState;
int motorState = LOW;

int hours = 0;
int minutes = 0;
int seconds = 0;

int day = 0;
int month = 0;
int year = 0;

int initial_setup(int varType){
  
  while(1){
    if (buttonUpState == HIGH)
      varType++;
    if (buttonUpState == HIGH)
      varType--;
    if(buttonOkState == HIGH)
      break;
  }
  
}

void setup() {
 
// put your setup code here, to run once:
  
int pill_input = 0

pinMode(buttonUpState, INPUT);
pinMode(buttonDownState, INPUT);
pinMode(SwitchState, INPUT);
pinMode(ledState, OUTPUT);
pinMode(motorState, OUTPUT);

//time and day

initial_setup(hours);
initial_setup(minutes);
initial_setup(seconds);

initial_setup(month);
initial_setup(day);
initial_setup(year);

//pill input

initial_setup(pill_input);

Serial.begin(9600);

rtc.begin();

rtc.setHours(hours);
rtc.setMinutes(minutes);
rtc.setSeconds(seconds);

rtc.setDay(day);
rtc.setMonth(month);
rtc.setYear(year);

}

void loop() {
  // put your main code here, to run repeatedly:



}
