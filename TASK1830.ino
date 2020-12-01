#include <Servo.h>
#include <Stepper.h>
#include "IRremote.h"
#include"IRremoteInt.h"

int stepsPerRevolution = 256; 
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

Servo myservo;  

int pos = 90; // start going straight at 90 deg
int receiver = 6;  // IR signal to pin 6
int  Steps2Take; 

IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'


void setup() {
  
  Serial.begin(9600);

  irrecv.enableIRIn(); // Start the receiver


  myStepper.setSpeed(80);
  myservo.attach(7);   // servo to pin 7
  myservo.write(pos);

}

void loop() {


if (irrecv.decode(&results)) // have we received an IR signal?

  {
    switch(results.value)

    {

      
      case 0xFF629D: // VOL+ pressed --> start stepper 
       myStepper.setSpeed(200); //can slow this down if u want?
                      Steps2Take  =  2048;  // Rotate CW
                      myStepper.step(Steps2Take);
                      break;


      case 0xFFA857: //  VOL- pressed --> stop stepper  
      myStepper.setSpeed(0);
      
                      break;
                
    


      case 0xFF22DD: // << button pressed --> turn left 
      pos = 0; 
      myservo.write(pos);
       myStepper.setSpeed(200); //can slow this down if u want?
                      Steps2Take  =  2048;  // Rotate CW
                      myStepper.step(Steps2Take);
                      break;

      case 0xFF02FD: // middle playpause button pressed --> turn straight

      pos = 90; 
      myservo.write(pos);
      
       myStepper.setSpeed(200); //can slow this down if u want?
                      Steps2Take  =  2048;  // Rotate CW
                      myStepper.step(Steps2Take);
                      break;


      case 0xFFC23D: // >> button pressed --> turn right 
      pos = 180; 
      myservo.write(pos); 
      
       myStepper.setSpeed(200); //can slow this down if u want?
                      Steps2Take  =  2048;  // Rotate CW
                      myStepper.step(Steps2Take);
                      break;
                
    }
    
      irrecv.resume(); // receive the next value // do nothing       
  }  
}

     
float measureDistanceCm() 
{
}
