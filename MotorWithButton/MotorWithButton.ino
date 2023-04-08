
//parts of this code are edited by the instructor.
//PIN VARIABLES
//the motor will be controlled by the motor A pins on the motor driver
const int AIN1 = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the right motor
const int PWMA = 11;            //speed control pin on the motor driver for the right motor

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

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  
  // Initialise serial
  Serial.begin(9600);

}

void loop() {
  buttonState1 = digitalRead(BUTTON_1);
  buttonState2 = digitalRead(BUTTON_2);
  buttonState3 = digitalRead(BUTTON_3);
   motorDemo();
}

void motorDemo(){
  // Turn on motor
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

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

    case 0:
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, 0);
      Serial.println("Turned off");
     break;
    

    case 1:
      // Set direction
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, 127);
      Serial.println("Medium Speed");
      break;
    case 2:
      // Set direction
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      analogWrite(PWMA, 255);
      Serial.println("High Speed");
      break;
  }
}
      
