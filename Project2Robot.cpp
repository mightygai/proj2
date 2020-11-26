include <Servo.h>
include <Stepper.h>

#define PIN_SERVO             12
#define PIN_TRIG              04
#define PIN_ECHO              05
#define PIN_STEPPER_1         08
#define PIN_STEPPER_2         09
#define PIN_STEPPER_3         10
#define PIN_STEPPER_4         11

#define STEPS_PER_REV         32

using namespace proj2;

class Project2Robot
{
  public:
    double steeringAngle;
    Servo servo;
    Stepper stepper;

    Project2Robot()
    {
      servo.attach(PIN_SERVO);
      stepper = Stepper(
        STEPS_PER_REV,
        PIN_STEPPER_1,
        PIN_STEPPER_3,
        PIN_STEPPER_2,
        PIN_STEPPER_4
        );
        stepper.setSpeed(700);
    }
    
    void setSteeringAngle(double newSteeringAngle)
    {
      if (isSteeringAngleOK(newSteeringAngle))
      {
        steeringAngle = newSteeringAngle;
        servo.write(newSteeringAngle);
      }
    }

    void adjustSteeringAngle(double steeringAngleAdjustment)
    {
      setSteeringAngle(steeringAngle + steeringAngleAdjustment);
    }

    bool isSteeringAngleOK(double newSteeringAngle)
    {
      return newSteeringAngle >= 60 || newSteeringAngle <= 120;
    }

    void moveForwardOneStep()
    {
      stepper.step(1);
    }

    void moveBackwardOneStep()
    {
      stepper.step(-1);
    }

    double readForwardDistance()
    {
      digitalWrite(PIN_TRIG, LOW);
      delayMicroseconds(2);
      digitalWrite(PIN_TRIG, HIGH);
      delayMicroseconds(10);
      digitalWrite(PIN_TRIG, LOW);
      
      duration = pulseIn(PIN_ECHO, HIGH);
      distance = 100.0*(343.0*(duration/2.0))/1000000.0;
      return distance;
    }
}
