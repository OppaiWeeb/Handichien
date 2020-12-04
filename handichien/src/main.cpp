#include <Arduino.h>
#include <Segment.h>   // Include the Segment library

Segment sixtseg(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, true);      // Uncomment for straight wiring pins (segment a - segment m)
int ECHO_pin = 13;
int distance = ;
int Trig_pin = 14;
int delayVal = 1000;   // Milliseconds to delay after each number (default 1 second)
int displays = 4;  // Number of sixteen segment displays you have daisy-chained (default 1)
// Var/Tours
int course = 0;
int passage =0;
int passageold=0;
void setup() {
	Serial.begin(9600);
	pinMode(Trig_pin, INPUT);
	pinMode(ECHO_pin, OUTPUT);
  	sixtseg.clear(displays); // Clear the number of displays you have
}

int trigger()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);

  const unsigned long duration = pulseIn(ECHO_pin, HIGH);
  int distance = duration / 29 / 2;
  if (duration == 0) {
    Serial.print("U r God we can't detect");
  }
  else {
    if (course < 100) {
      return 0;
    }
    else {
      return 1;
    }   
  }
}

void loop() 
{
passage = distance;
  if (passage != passageold){ 
    if (passage == 1){
      course=course+1;
      }
    passageold=passage;
    }
  sixtseg.display(course);
}