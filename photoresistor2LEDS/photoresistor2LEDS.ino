int light =0; //stores the current light value

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//read the position of the knob
light = analogRead(A0);
Serial.println(light);


if(light>450){
  Serial.println("Its bright light"); //if it is bright
  digitalWrite(13,LOW);
  digitalWrite(8,LOW);
  }else if(light>150 && light < 229){ //if it is average light 
    Serial.println("Its average light");
  digitalWrite(13,HIGH);
  digitalWrite(8,LOW);
    }else if(light>229 && light < 451){ //if its dark
    Serial.println("Its normal dark");
  digitalWrite(13,LOW);
  digitalWrite(8,HIGH);
    }else{
      digitalWrite(13,HIGH);
      digitalWrite(8,HIGH);
      }
    delay(1000);

}
