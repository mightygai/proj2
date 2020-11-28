#include <Servo.h>
#include <HCSR04.h>
#include <Stepper.h>
#define triggerPin 12
#define echoPin 11


int stepsPerRevolution = 256; 
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

Servo myservo;  
int Input;

UltraSonicDistanceSensor sensor(triggerPin,echoPin);
int pos = 90;


void setup() {
  
  Serial.begin(9600);

  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);


  myStepper.setSpeed(80);
  myservo.attach(6);  
  myservo.write(pos);

}

void loop() {
 int obstacle = 4; //ult sensor glitches at <2 so 4cm distance is fine


     
    if(obstacle >= Input){
      
      //turn left 4 s 
      pos = 0;
 myservo.write(pos);
      delay(4000);
      //turn right 4 s
      pos = 90; 
 myservo.write(pos);
      delay(4000);
      //turn right 4 s 
      pos = 180;
  myservo.write(pos);
      delay(4000);
      //turn left 4 s
      pos = 90;
  myservo.write(pos);
      delay(4000);   
  }

}
     
float measureDistanceCm() 
{
}
