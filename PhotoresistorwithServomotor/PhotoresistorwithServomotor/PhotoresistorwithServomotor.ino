#include <Servo.h>
#define unpress 90
#define press_angle 30

Servo servo1;
int sensor;
int threshold = 250;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(10);
  servo1.write(unpress);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensor = analogRead(A0);
  Serial.println(sensor);
  servo1.write(unpress);
  if (threshold > sensor){
    servo1.write(press_angle);
    delay(500);
    }
  
}
