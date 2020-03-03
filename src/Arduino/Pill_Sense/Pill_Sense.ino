

void setup()
{
  Serial.begin(9600);
  // Initialize sensor
  setupSense();
}

void loop()
{
  runSense();
}
