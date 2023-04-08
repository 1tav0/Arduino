
//Arduino.cc projects
int analogPin = A0; //pin that attaches to potentiometer
int ledCount = 8; //number of LEDs in the bar graph
int ledPins[] = {13,12,11,10,9,8,7,6}; //array of pin numbers that LEDs are attached to

void setup() {
  // put your setup code here, to run once:
for(int thisLed = 0;thisLed<ledCount; thisLed++){ //loop over the pin array to set them all to OUTPUT
  pinMode(ledPins[thisLed],OUTPUT);
  Serial.begin(9600);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading = analogRead(analogPin); //to read the potentiometer
  Serial.println(sensorReading);
  int ledLevel = map(sensorReading, 0,102,0,ledCount); //map the result of the potentiomer reading to a range from 0 to the number of LEDs

  for(int thisLed=0;thisLed<ledCount;thisLed++) //loop over the LED array
  {
    if (thisLed <ledLevel)            //if array element 's index is < ledLevel turn the pin for this element on
    {
     digitalWrite(ledPins[thisLed],HIGH);
    }
    else{                           //turn off all  pins higher than ledLevel
      digitalWrite(ledPins[thisLed],LOW);
      }
    }
}
