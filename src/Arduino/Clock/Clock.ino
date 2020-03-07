void setup(){
  initDisplay();
  timeSetup();
  Serial.begin(9600);
}
void loop(){
  //Serial.print(2);
  //receiveMessage();
  timeLoop();
}
