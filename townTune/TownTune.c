/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"
// Animal Crossing: Wild World Default Town Tune: CECGFGBDC_G_c--
// notes in the melody:
int melody[] = {NOTE_C4, NOTE_E4, NOTE_C4, NOTE_G3, NOTE_F3, NOTE_G3, NOTE_B3, NOTE_D4, NOTE_C4, 0, NOTE_E4, 0, NOTE_C3};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4,4,4,4,4,4,4,4,4,4,4,4,2};
  
int speakerPin = 8;

void setup()
{
  while(true)
  {
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 13; thisNote++)
    {
      // to calculate the note duration, take one second 
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/noteDurations[thisNote];
      tone(speakerPin, melody[thisNote],noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 10% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.1;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(speakerPin);
    }
    
    delay(1000);
  }
}
