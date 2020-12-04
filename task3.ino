/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <Stepper.h>
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 13
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
int b=0;
long a;
const int stepsPerRevolution = 32;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 11, 9, 10,8 );

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  
  myStepper.setSpeed(700);
    Serial.begin(9600);
    

  
}

void loop() {

 
  myservo.write(90);
  myStepper.step(stepsPerRevolution);
  a=sr04.Distance();
  Serial.print(a);
  Serial.print(",");
  Serial.print(b);
   Serial.println("cm");
  if (a<24){
    for (int i =0; i <= 110; ++i)
    {
   Serial.println(i);
   myStepper.step(32);
   myservo.write(140);
    }
    delay(150);

   
   for (int i =0; i <= 260; ++i)
    {
   Serial.println(i);
   myStepper.step(32);
   myservo.write(40);
    }
    delay(150);  
  for (int i =0; i <= 60; ++i)
    {
   Serial.println(i);
   myStepper.step(32);
   myservo.write(140);
    }
    delay(150); 
  
  
  }
  


}