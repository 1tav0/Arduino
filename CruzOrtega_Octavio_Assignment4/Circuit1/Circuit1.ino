/*
 * OCTAVIO CRUZ ORTEGA
 * ID:918512808
 * 
 */
  
// * Program to choose between two melodies by using a potentiometer and a piezo buzzer.
//* Program borrowed by Kirtan Jha to edit.//*

//*Task: This program is using potentiometer to control two melodies. Your task is to remove portions of potentiometer and use two push buttons to control the melodies.//8
  

  // TONES //
  // Defining the relationship between note, period & frequency. 
   
  // period is in microsecond so P = 1/f * (1E6)
   
  #define  c3    7634
  #define  d3    6803
  #define  e3    6061
  #define  f3    5714
  #define  g3    5102
  #define  a3    4545
  #define  b3    4049
  #define  c4    3816    // 261 Hz 
  #define  d4    3401    // 294 Hz 
  #define  e4    3030    // 329 Hz 
  #define  f4    2865    // 349 Hz 
  #define  g4    2551    // 392 Hz 
  #define  a4    2272    // 440 Hz 
  #define  a4s   2146
  #define  b4    2028    // 493 Hz 
  #define  c5    1912    // 523 Hz
  #define  d5    1706
  #define  d5s   1608
  #define  e5    1517    // 659 Hz
  #define  f5    1433    // 698 Hz
  #define  g5    1276
  #define  a5    1136
  #define  a5s   1073
  #define  b5    1012
  #define  c6    955
   
  #define  R     0      // Define a special note, 'R', to represent a rest
   
   
  // MELODIES and TIMING //
  //  melody[] is an array of notes, accompanied by beats[], 
  //  which sets each note's relative length (higher #, longer note) 
   
  // Melody 1: Star Wars Imperial March
  int melody1[] = {  a4, R,  a4, R,  a4, R,  f4, R, c5, R,  a4, R,  f4, R, c5, R, a4, R,  e5, R,  e5, R,  e5, R,  f5, R, c5, R,  g5, R,  f5, R,  c5, R, a4, R};
  int beats1[]  = {  50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5, 20, 5, 60, 80, 50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5,  20, 5, 60, 40};
   
  // Melody 2: Star Wars Theme
  int melody2[] = {  f4,  f4, f4,  a4s,   f5,  d5s,  d5,  c5, a5s, f5, d5s,  d5,  c5, a5s, f5, d5s, d5, d5s,   c5};
  int beats2[]  = {  21,  21, 21,  128,  128,   21,  21,  21, 128, 64,  21,  21,  21, 128, 64,  21, 21,  21, 128 }; 

  // Melody length, for looping.
  int MAX_COUNT1 = sizeof(melody1) / 2; 
  int MAX_COUNT2 = sizeof(melody2) / 2;
    
  long tempo = 10000; // Set overall tempo
  int pause = 1000; // Set length of pause between notes
  int rest_count = 50; // Loop variable to increase Rest length (BLETCHEROUS HACK; See NOTES)
   
  // Initialize core variables
  int toneM = 0;
  int beat = 0;
  long duration  = 0;
  
  // SETUP //
  int speakerOut = 9;    // Set up speaker on digital pin 9
  int Button1 = 7;
  int Button2 = 6;
  

  /******************what happens when you're not pushing the button?
  In this state, the pin is disconnected from everything, which 
  we call "floating". What will the pin read as then, HIGH or LOW?
  It's hard to say, because there's no solid connection to either
  5 Volts or GND. The pin could read as either one.

  To deal with this issue, we'll connect a small (10K, or 10,000 Ohm)
  resistance between the pin and 5 Volts. This "pullup" resistor
  will ensure that when you're NOT pushing the button, the pin will
  still have a weak connection to 5 Volts, and therefore read as
  HIGH.***********************************/ 
  void setup() 
  { 
    pinMode(speakerOut, OUTPUT);
    pinMode(Button1,INPUT_PULLUP);
    pinMode(Button2,INPUT_PULLUP);
    Serial.begin(9600); // Set serial out if we want debugging 
  } 
   
 
  void loop() 
  {
    /*********Since a pushbutton has only two states (pushed or not pushed),
    we've run them into digital inputs. To read an input, we'll
    use the digitalRead() function. This function takes one
    parameter, the pin number, and returns either HIGH (5V)
    or LOW (GND).********/
    
    /*read the state of the pushbutton value into the buttonState variable:*/
    
    int buttonState1 = digitalRead(Button1);
    int buttonState2 = digitalRead(Button2);
    // Show the state of pushbutton on serial monitor
    Serial.println(buttonState1);
    Serial.println(buttonState2);

    /*********If the button is being pressed, it will be
    connected to GND. If the button is not being pressed,
    the pullup resistor will connect it to 5 Volts.
    So the state will be LOW when it is being pressed,
    and HIGH when it is not being pressed.*************/
    
    if(buttonState1 == LOW)
    {
      Serial.println("button1 pressed");
      // Set up a counter to pull from melody1[] and beats1[]
      for (int i=0; i<MAX_COUNT1; i++)
      {
        toneM = melody1[i];
        beat = beats1[i];
     
        duration = beat * tempo; // Set up timing
     
        //playTone(); // A pause between notes
        playTone();
        delayMicroseconds(pause);
      }
    }
    else if(buttonState2 == LOW)// ... else play Melody2
    {  
      Serial.println("button2 pressed");  
      for (int i=0; i<MAX_COUNT2; i++) 
      {
        toneM = melody2[i];
        beat = beats2[i];
        duration = beat * tempo; // Set up timing
        playTone(); // A pause between notes
        delayMicroseconds(pause);
      }
    }
  }
  
  void playTone() 
  {
    long elapsed_time = 0;
    if (toneM > 0) // if this isn't a Rest beat, while the tone has
    { 
      //  played less long than 'duration', pulse speaker HIGH and LOW
      while (elapsed_time < duration) 
      {
   
        digitalWrite(speakerOut,HIGH);
        //tone(speakerOut,HIGH);
        delayMicroseconds(toneM / 2);
        // DOWN
        digitalWrite(speakerOut, LOW);
        //noTone(speakerOut);
        delayMicroseconds(toneM / 2);
        // Keep track of how long we pulsed
        elapsed_time += (toneM);
      } 
    }
    else // Rest beat; loop times delay
    { 
      for (int j = 0; j < rest_count; j++) // See NOTE on rest_count
        delayMicroseconds(duration);                                  
    }                                 
  }
  
