// setting PWM properties
const int pwmFrequency = 50000;
const int pwmChannel = 3;
const int pwmBitResolution = 8;

// MOTOR VARs
int motorPin = 03;

// ========== Motor Code =========//

void setupMotor(){
  //setup the PWM for the motor
  ledcSetup(pwmChannel, pwmFrequency, pwmBitResolution);
  ledcAttachPin(motorPin, pwmChannel);
}

void buzzMotor(int buzz_power){
  //buzz the motor at the buzz_power
  //ledcWrite(pwmChannel, 255);
  //digitalWrite(motorPin, HIGH);

}
