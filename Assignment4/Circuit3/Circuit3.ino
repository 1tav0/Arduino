/*
 *  OCTAVIO CRUZ ORTEGA 
 * 
 * ID:918512808
 * 
 * 
 * 
 */
int sensorPin = A0;
const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the right motor
const int PWMA = 11;            //speed control pin on the motor driver for the right motor
int LED = 5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  // Setup motor pins
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //getting the voltage reading from the temperature sensor
  int sensorInput = analogRead(sensorPin);
  Serial.println(sensorInput); 

  // converting that reading to voltage, for 3.3v arduino use 3.3
  float voltage = sensorInput * 5.0;
  voltage /= 1024.0; 

   // print out the voltage
   Serial.print(voltage); Serial.println(" volts");
   
   // now print out the temperature
   float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                                 //to degrees ((voltage - 500mV) times 100)
   Serial.print(temperatureC); Serial.println(" degrees C");
   
   // now convert to Fahrenheit
   float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
   Serial.print(temperatureF); Serial.println(" degrees F");
   delay(1000);
   
   if(temperatureC > 24 && temperatureF > 76)
   {
      digitalWrite(LED,HIGH);
      // Set direction
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, 255);
      Serial.println("Hot");
   }else
        {
          digitalWrite(LED,LOW);
          // Set direction
          digitalWrite(AIN1, LOW);
          digitalWrite(AIN2, LOW);
          analogWrite(PWMA, 255);
          Serial.println("Cold");
        }   
}
