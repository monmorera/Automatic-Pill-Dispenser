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

int month = 0;
int day = 0;
int year = 0;

int alarm_month = 0;
int alarm_day = 0;
int alarm_year = 0;
int alarm_hour = 0;
int alarm_minute = 0;

void initial_setup(int varType){
  
  while(1){
    if (buttonUpState == HIGH)
      varType++;
    if (buttonDownState == HIGH)
      varType--;
    if(buttonOkState == HIGH)
      break;
    delay(1000);
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

void set_alarm(){

  initial_setup(alarm_month);
  initial_setup(alarm_day);
  initial_setup(alarm_year);
  initial_setup(alarm_hour);
  initial_setup(alarm_minute);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(SwitchState == HIGH)
    while(1){
      set_alarm;
      delay(1000);
    }

  if (rtc.getDay() == alarm_month)
    
  if (rtc.getMonth() == alarm_day)
  
  if(rtc.getYear() == alarm_year)
  
  if(rtc.getHours() == alarm_hour)
  
  if(rtc.getMinutes() == alarm_minute);

  delay(1000);

}
