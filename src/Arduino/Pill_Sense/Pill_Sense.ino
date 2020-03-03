
int run = 0;
void setup()
{
  Serial.begin(9600);
  // Initialize sensor
  setupSense();
}

void loop()
{
  while(run==0){
    runStepper();
    if(runSense() == true){
      Serial.print("found");
      run =1;
    }
  }
  Serial.println("end");
  
}
