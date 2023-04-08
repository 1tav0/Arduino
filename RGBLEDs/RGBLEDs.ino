int red_pin = 9;
int blue_pin = 10;
int green_pin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  maincolor();
}

void maincolor(){
  digitalWrite(9,HIGH);//this section activates the red light
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(1000);
  digitalWrite(9,LOW);//this section activates the red light
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(1000);
  digitalWrite(9,LOW);//this section activates the red light
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(1000);
  
}
