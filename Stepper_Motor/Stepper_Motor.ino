#include <Stepper.h>

const float STEPS_PER_REV = 32;
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

int StepsRequired;
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  steppermotor.setSpeed(1);
  StepsRequired = 4;
  steppermotor.step(StepsRequired);
  delay(1500);

  StepsRequired = STEPS_PER_OUT_REV;
  steppermotor.setSpeed(700);
  steppermotor.step(StepsRequired);
  delay(1000);
}
