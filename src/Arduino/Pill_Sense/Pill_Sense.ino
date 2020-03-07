
int run = 0;
void setup()
{
  Serial.begin(115200);
  // Initialize sensor
  setupSense();
}

void loop()
{
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
