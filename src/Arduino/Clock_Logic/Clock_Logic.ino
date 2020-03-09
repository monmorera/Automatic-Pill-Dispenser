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

lcd.begin(16, 2); //Tell the LCD that it is a 16x2 LCD
pinMode(contra, OUTPUT); //set pin 9 to OUTPUT
pinMode(bri, OUTPUT); //Set pin 10 to OUTPUT
//pinMode-ing OUTPUT makes the specified pin output power
digitalWrite(contra, LOW); /*outputs no power to the contrast pin.
                            this lets you see the words*/
analogWrite(bri, 255);
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

  lcd.print(" Hello, World!!"); //Output " Hello, World!!" on the first line of the LCD
  lcd.setCursor(0, 1); /*Set the (invisible) cursor on the first place second row of the LCD.
                        Cursor values are 0-indexed, 0 would the be the first place.
                        The cursor coordinates are X,Y coordinates.*/
  lcd.print("16x2 LCD Screen");
  delay(1000); //Wait a second
  for (int l = 0; l < 16; l++) { //For loop. Repeating 16 times
    lcd.scrollDisplayRight(); //Scroll whole screen to the right once
    delay(90); //Slight delay for animation
  }
  delay(1000);
  for (int l = 0; l < 16; l++)
    lcd.scrollDisplayLeft();
  for (int l = 51; l > -1; l--) { //Repeating 51 times
    analogWrite(bri, l * 5);
    delay(35);
  }
  delay(1000);
  digitalWrite(bri, HIGH);
  for (int l = 0; l < 51; l++) { //Repeating 51 times
    analogWrite(contra, l * 5);
    delay(35);
  }
  delay(1000);
  digitalWrite(contra,LOW);
  lcd.setCursor(0, 0);
}
