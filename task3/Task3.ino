#include "Project2Robot.h"

Project2Robot robot;

int b=0;
long a;

bool startedTurn = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 32; i++)
  {
    robot.moveOneStepForward();
  }
  if (robot.getForwardDistance() < 35 && !startedTurn) {
    startedTurn = true;
    robot.setSteeringAngle(120);
    for (int i = 0; i < 1500; i++) {
      delay(1);
      robot.moveOneStepForward();
    }
    robot.setSteeringAngle(90);
    for (int i = 0; i < 2500; i++) {
      delay(1);
      robot.moveOneStepForward();
    }
    robot.setSteeringAngle(90);
    for (int i = 0; i < 1000; i++) {
      delay(1);
      robot.moveOneStepForward();
    }
    robot.setSteeringAngle(120);
    for (int i = 0; i < 1000; i++) {
      delay(1);
      robot.moveOneStepForward();
    }
    robot.setSteeringAngle(90);
  }
}
