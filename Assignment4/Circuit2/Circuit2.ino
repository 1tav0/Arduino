/*
 * OCTAVIO CRUZ ORTEGA
 * ID:918512808
 * 
 */
 
//parts of this code are edited by the instructor.
//PIN VARIABLES
//the motor will be controlled by the motor A pins on the motor driver
const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the right motor
const int PWMA = 11;            //speed control pin on the motor driver for the right motor

const int BIN1 = 8;           //control pin 1 on the motor driver for the right motor
const int BIN2 = 9;            //control pin 2 on the motor driver for the right motor
const int PWMB = 10;            //speed control pin on the motor driver for the right motor

const int BUTTON_1 = 4;
const int BUTTON_2 = 5;
const int BUTTON_3 = 7;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int currentState = 0;

void setup() {
  // Setup motor pins
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  
  // Initialise serial
  Serial.begin(9600);

}

void loop() {
  //to read in the state of the button
  buttonState1 = digitalRead(BUTTON_1);
  buttonState2 = digitalRead(BUTTON_2);
  buttonState3 = digitalRead(BUTTON_3);
   motorDemo();
}

void motorDemo(){
  
/*********If the button is being pressed, it will be
    connected to GND. If the button is not being pressed,
    the pullup resistor will connect it to 5 Volts.
    So the state will be LOW when it is being pressed,
    and HIGH when it is not being pressed.*************/

  if(buttonState1 == LOW){
    currentState = 1;
  }
  else if(buttonState2 == LOW) {
    currentState = 2;
  }

  else if(buttonState3 == LOW){
    currentState = 0;
  }


  switch(currentState){

    //stop motor
    case 0:
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, 0);
      digitalWrite(BIN1, LOW); 
      digitalWrite(BIN2, LOW);
      analogWrite(PWMB, 0);
      Serial.println("Turned off");
     break;
    

    case 1:
      //drive motor forward (positive speed)
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, 127);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      analogWrite(PWMB, 127);
      Serial.println("Medium Speed");
      break;

      
    case 2:
      //drive motor backward (negative speed)
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      analogWrite(PWMA, 255);
      digitalWrite(BIN1, LOW); 
      digitalWrite(BIN2, HIGH); 
      analogWrite(PWMB, 255);
      Serial.println("High Speed");
      break;
  }
}
      
