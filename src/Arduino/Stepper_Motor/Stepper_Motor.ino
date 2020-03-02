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
  StepsRequired = STEPS_PER_OUT_REV;
  steppermotor.setSpeed(1000);
  steppermotor.step(StepsRequired);
  delay(1000);
}
