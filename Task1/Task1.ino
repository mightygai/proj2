#include "Project2Robot.h"

Project2Robot robot;

int stepperState = 1;

void setup() {
  Serial.begin(9600);
  robot.initializeRobot();
}

void loop() {
  if (stepperState == 0)
  {
    robot.moveOneStepBackward();
  }
  else if (stepperState == 2)
  {
    robot.moveOneStepForward();
  }
  
  long results = robot.getRemoteResults();
  if (results != 0) // have we received an IR signal?
  {
    switch(results)
    {
      case 0xFF629D: // VOL+ pressed --> start stepper
      stepperState = 2;
      break;

      case 0xFFA857: //  VOL- pressed --> stop stepper
      stepperState = 1;
      break;
      
      case 0xFF22DD: // << button pressed --> turn left 
      robot.setSteeringAngle(60);
      break;

      case 0xFF02FD: // middle playpause button pressed --> turn straight
      robot.setSteeringAngle(90);
      break;

      case 0xFFC23D: // >> button pressed --> turn right 
      robot.setSteeringAngle(120);
      break;     
    }    
  }  
}
