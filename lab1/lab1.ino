/**************************************************************
* Class:  ENGR-121- Fall 2020
* Name: Octavio Cruz Ortega
* Student ID: 918512808
* Project: Assignment 1 - LED glow alternation

**************************************************************/


int led[] = {6,7,8,9,10,11,12,13};
int i;
void setup() {
  // put your setup code here, to run once:
for(i=0;i<8;i++)
pinMode(led[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(led[0],LOW);
  digitalWrite(led[0],HIGH);
  delay(600);
  digitalWrite(led[0],HIGH);
  digitalWrite(led[0],LOW);
  delay(600);
  
  digitalWrite(led[2],LOW);
  digitalWrite(led[2],HIGH);
  delay(600);
  digitalWrite(led[2],HIGH);
  digitalWrite(led[2],LOW);
  delay(600);

  digitalWrite(led[4],LOW);
  digitalWrite(led[4],HIGH);
  delay(600);
  digitalWrite(led[4],HIGH);
  digitalWrite(led[4],LOW);
  delay(600);

  digitalWrite(led[6],LOW);
  digitalWrite(led[6],HIGH);
  delay(600);
  digitalWrite(led[6],HIGH);
  digitalWrite(led[6],LOW);
  delay(600);

  for(i=0;i<8;i++)
  {
    digitalWrite(led[i],LOW);
    //delay(150);
    }
  
digitalWrite(led[1],LOW);
  digitalWrite(led[1],HIGH);
  delay(600);
  digitalWrite(led[1],HIGH);
  digitalWrite(led[1],LOW);
  delay(600);
  
  digitalWrite(led[3],LOW);
  digitalWrite(led[3],HIGH);
  delay(600);
  digitalWrite(led[3],HIGH);
  digitalWrite(led[3],LOW);
  delay(600);

  digitalWrite(led[5],LOW);
  digitalWrite(led[5],HIGH);
  delay(600);
  digitalWrite(led[5],HIGH);
  digitalWrite(led[5],LOW);
  delay(600);

  digitalWrite(led[7],LOW);
  digitalWrite(led[7],HIGH);
  delay(600);
  digitalWrite(led[7],HIGH);
  digitalWrite(led[7],LOW);
  delay(600);

  for(i=0;i<8;i++)
    {
      digitalWrite(led[i],LOW);
      //delay(1500);
      }
}
  
/*for(i=8;i>=0; i--)
{
  digitalWrite(led[i],HIGH);
  delay(650);
  digitalWrite(led[i],LOW);
  }*/
