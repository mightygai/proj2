#include <Servo.h>
#include <HCSR04.h>
#include <Stepper.h>
#include <IRremote.h>
#define triggerPin 12
#define echoPin 11


int stepsPerRevolution = 256; 
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

Servo myservo;  
int Input;

UltraSonicDistanceSensor sensor(triggerPin,echoPin);
int pos = 90; // start going straight at 90 deg
int receiver = 6;  // IR signal to pin 6

IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'


void setup() {
  
  Serial.begin(9600);

  irrecv.enableIRIn(); // Start the receiver
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);


  myStepper.setSpeed(80);
  myservo.attach(7);   // servo to pin 7
  myservo.write(pos);

}

void loop() {


if (irrecv.decode(&results)) // have we received an IR signal?

  {
    switch(results.value)

    {

      case 0xFFA857: // VOL+ button pressed --> turn left 

      pos = pos - 90; 
      myservo.write(pos);
                      break;

      case 0xFF629D: // VOL- button pressed --> turn right 
      pos = pos + 90; 
      myservo.write(pos); 
                      break;
                
    }
    
      irrecv.resume(); // receive the next value // do nothing       
  }  
}

     
float measureDistanceCm() 
{
}
