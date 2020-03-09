
int run = 0;
int power = 0;
void setup()
{
  Serial.begin(115200);
  // Initialize sensor
  setupSense();
}

void loop()
{
  receiveMessage();
  if(power>1){
    run=0;
    power=0;
  }
  while(run==0){
    runStepper();
    if(runSense()==true){
      run=1;
    }
    Serial.println("hi");
  }
    /*if(runSense() == true){
      Serial.print("found");
      run =1;
    }
  }
  Serial.println("end");*/
  
}
