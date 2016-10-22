/*********************************************************
*                                                        *
* 5 Minute Timer With Minute indicators and Alarm Melody *
*                                                        *
*********************************************************/


#include "pitches.h"

#define SPEAKER 8
#define COUNTER 2
#define RESET 8
#define WhiteLED 3
#define RedLED 4
#define BlueLED 5
#define GreenLED 6
#define YellowLED 7

int SetTime = 500; // Change to 50 to test TIMER
int a = 250; // Change length of StartUp() blink
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() 
{
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT);
  pinMode(WhiteLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(COUNTER, OUTPUT);
  pinMode(RESET, INPUT);
  StartUp();
  Serial.println("Setup Complete");
  
} // End Setup



void loop() 
{

  TIMER(5);

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(SPEAKER, melody[thisNote], noteDuration);

    
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SPEAKER);
  }

  
   int wait = 1;
  
    while(wait == 1)  //Waits for RESET button to be pressed
    {}
  
} //End Main



void TIMER(int set)
{
  
   for(int Mins = 1; Mins <= set; Mins++)
   {
  
    for(int secs = 0; secs <= 60; secs++)
    {
      
      delay(SetTime);
      digitalWrite(COUNTER, HIGH);
      delay(SetTime);
      digitalWrite(COUNTER, LOW);
      Serial.println(secs);
      
    } //End Seconds loop
    
    Serial.println(Mins);

    switch(Mins)
    {

      case 1:
        digitalWrite(WhiteLED, HIGH);
        break;
      case 2:
        digitalWrite(RedLED, HIGH);
        break;
      case 3:
        digitalWrite(BlueLED, HIGH);
        break;
      case 4:
        digitalWrite(GreenLED, HIGH);
        break;
      case 5:
        digitalWrite(YellowLED, HIGH);
        break;
        
    } // End Switch
   
  } //End Minutes Loop
  
} //End TIMER()



void StartUp()
{

  digitalWrite(WhiteLED, HIGH);
  digitalWrite(RedLED, HIGH);
  digitalWrite(BlueLED, HIGH);
  digitalWrite(GreenLED, HIGH);
  digitalWrite(YellowLED, HIGH);
  
  delay(a);
  digitalWrite(WhiteLED, LOW);
  digitalWrite(RedLED, LOW);
  digitalWrite(BlueLED, LOW);
  digitalWrite(GreenLED, LOW);
  digitalWrite(YellowLED, LOW);
  
  delay(a);
  digitalWrite(WhiteLED, HIGH);
  digitalWrite(RedLED, HIGH);
  digitalWrite(BlueLED, HIGH);
  digitalWrite(GreenLED, HIGH);
  digitalWrite(YellowLED, HIGH);;
  
  delay(a);
  digitalWrite(WhiteLED, LOW);
  digitalWrite(RedLED, LOW);
  digitalWrite(BlueLED, LOW);
  digitalWrite(GreenLED, LOW);
  digitalWrite(YellowLED, LOW);
  
} // End StartUp()
  

