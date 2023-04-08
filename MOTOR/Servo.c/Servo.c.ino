#include <Servo.h>

int pos = 0;
 Servo myObj;

void setup() {
  // put your setup code here, to run once:
  myObj.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(pos =0; pos <= 180; pos += 1)
  {
    myObj.write(pos);
    delay(10);
  }
  for(pos =0; pos <= 180; pos++)
  {
    myObj.write(pos);
    delay(15);
  }
}
