#include <Servo.h>
#include <Stepper.h>
#include <Arduino.h>

#include "Project2Robot.h"

Project2Robot::Project2Robot()
{
  stepper.setSpeed(700);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void Project2Robot::initializeRobot()
{
  servo.attach(PIN_SERVO);
  irRecv.enableIRIn();
}

void Project2Robot::setSteeringAngle(double newSteeringAngle)
{
  if (isSteeringAngleOK(newSteeringAngle))
  {
    steeringAngle = newSteeringAngle;
    servo.write(newSteeringAngle);
  }
}

void Project2Robot::adjustSteeringAngle(double steeringAngleAdjustment)
{
  setSteeringAngle(steeringAngle + steeringAngleAdjustment);
}

bool Project2Robot::isSteeringAngleOK(double newSteeringAngle)
{
  return newSteeringAngle >= 60 && newSteeringAngle <= 120;
}

void Project2Robot::moveForwardOneStep()
{
  stepper.step(1);
}

void Project2Robot::moveBackwardOneStep()
{
  stepper.step(-1);
}

double Project2Robot::readForwardDistance()
{
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  double duration = pulseIn(PIN_ECHO, HIGH);
  double distance = 100.0*(343.0*(duration/2.0))/1000000.0;
  return distance;
}

long Project2Robot::getRemoteResults()
{
  int tempValue;
  if (irRecv.decode(&results))
  {
    tempValue = results.value;
    irRecv.resume();

    return tempValue;
  }
  else
  {
    return 0;
  }
}
