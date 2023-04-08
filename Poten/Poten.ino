int input_value;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  input_value = analogRead(A0);
  Serial.println(input_value);
  digitalWrite(13,HIGH);
  delay(input_value);
  digitalWrite(13,LOW);
  delay(input_value);
}
