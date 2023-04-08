int led[] = {6,7,8,9,10,11,12,13};
int i;
void setup() {
  // put your setup code here, to run once:
for(i=0;i<8;i++)
pinMode(led[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
/*for(i=0;i<8;i++)
{ 
  digitalWrite(led[i++],HIGH);
  delay(65);
  digitalWrite(led[i],LOW);
  }*/
for(i=8;i>=0; i--)
{
  digitalWrite(led[i],HIGH);
  delay(650);
  digitalWrite(led[i],LOW);
  }
}
