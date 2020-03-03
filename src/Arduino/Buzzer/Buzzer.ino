int buzzerPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode (buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (buzzerPin, HIGH);
  delay (500);
  digitalWrite (buzzerPin, LOW);
  delay (500);
}
