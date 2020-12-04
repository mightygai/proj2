#ifndef ROBOT_H
#define ROBOT_H

#include <Servo.h>
#include <Stepper.h>

#define PIN_IRREC             2
#define PIN_SERVO             3
#define PIN_TRIG              4
#define PIN_ECHO              5
#define PIN_STEPPER_1         8
#define PIN_STEPPER_2         9
#define PIN_STEPPER_3         10
#define PIN_STEPPER_4         11
#define STEPS_PER_REV         32

class Project2Robot
{
private:
  Servo servo;
  Stepper stepper = Stepper(
        STEPS_PER_REV,
        PIN_STEPPER_1,
        PIN_STEPPER_3,
        PIN_STEPPER_2,
        PIN_STEPPER_4
        );
  double steeringAngle;
  IRrecv irRecv = IRRecv(PIN_IRRECV);

public:
  Project2Robot();
  void initializeServo();
  void setSteeringAngle(double newSteeringAngle);
  void adjustSteeringAngle(double steeringAngleAdjustment);
  bool isSteeringAngleOK(double newSteeringAngle);
  void moveForwardOneStep();
  void moveBackwardOneStep();
  double readForwardDistance();
  long getRemoteResults();
};

#endif
