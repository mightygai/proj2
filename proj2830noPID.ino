#include <HCSR04.h>
#define triggerPin 12
#define echoPin 11
#define ENABLE 5
#define DIRA 3
#define DIRB 4

UltraSonicDistanceSensor ultrasonic(triggerPin,echoPin);

int Input;

void setup() {
  
 Serial.begin(9600);

 pinMode(triggerPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(ENABLE, OUTPUT);
 pinMode(DIRA,OUTPUT);
 pinMode(DIRB,OUTPUT);                  

}

void loop() {
  
Input = ultrasonic.measureDistanceCm();
int obstacle = 3; //ult sensor glitches at <2 so 3cm distance is fine


digitalWrite(ENABLE, HIGH); 
digitalWrite(DIRA, HIGH); // not sure what direction its initially in
     
    if(obstacle >= Input){
      
      //turn left 3 s // this is how you would make the turns but not sure how the gear situation/mechanical build is, need to clarify for code
    digitalWrite(DIRA,HIGH); 
    digitalWrite(DIRB,LOW);
      delay(3000);
      //TURN right 3 s
    digitalWrite(DIRA,LOW); 
    digitalWrite(DIRB,HIGH);     
      delay(3000);
      //turn right 3 s
    digitalWrite(DIRA,LOW); 
    digitalWrite(DIRB,HIGH);     
      delay(3000);
      //turn left 3 s
    digitalWrite(DIRA,HIGH); 
    digitalWrite(DIRB,LOW);
      delay(3000);   
  }

}
     
float measureDistanceCm() 
{
}
