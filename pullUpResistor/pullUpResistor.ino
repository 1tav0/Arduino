int LED = 9;
int readpin = 2;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED,OUTPUT);
  pinMode(readpin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(readpin);
  Serial.println(buttonState);
  if (buttonState == 0){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
}
