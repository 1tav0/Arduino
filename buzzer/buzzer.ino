int buzzer = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer,10);
  delay(1000);
  noTone(buzzer);
  delay(1000);
}

//tone(pin number,frequency, duration of time working)
