// setting PWM properties
int power = 0;
int pin = 3;
void setup() {
  // configure PWM functionalities
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  setupMotor();
  
  // attach the pwmChannel to the outputGPIO to be controlled

}

void loop() {
  //max is 255 min is 0
//  receiveMessage();
  //buzzMotor(200);
  analogWrite(pin,HIGH);
}
