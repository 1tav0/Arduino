int photoresistor =0; //global variable for light photo resistor, light depending resistor just like our potentiometer except this one 
//works depending on the amount of light it is given. it is suppose to have less resistance at night so theres more light. depends on amount of light for its resistance.
//shining light on photoresistor will turn off led


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//read the position of the knob
photoresistor = analogRead(A0);
Serial.println(photoresistor);

//if the photoresistor value is below the threshold
analogWrite(9,map{photoresistor,0,1023,0,255}); //mapping analog write and analog read thats all
delay(100);
}

//
