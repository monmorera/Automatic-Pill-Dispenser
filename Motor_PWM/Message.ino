char in_text[64];
int in_text_index = 0;
int char_to_int = 0;
void receiveMessage(){
  if(Serial.available() > 0 ){
    char incomingChar = Serial.read();
    if(incomingChar=='\n'){
      power = atoi(in_text);
      in_text_index=0;
      Serial.println(power);
      memset(in_text,0,20);
    }
    else{
      in_text[in_text_index]=incomingChar;
      in_text_index++;
    }
  }
}
