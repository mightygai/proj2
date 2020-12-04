#include "Project2Robot.h"

int b = 0;
long a;

void setup() {
 Serial.begin(9600);
}

void loop() {
  robot.setSteeringAngle(90);
  for (int i = 0; i < 32; i++)
  {
    robot.moveOneStepForward();
  }
  a=robot.readForwardDistance();
  Serial.print(a);
  Serial.print(",");
  Serial.print(b);
  Serial.println("cm");
  if (a<28){
    for (int i =0; i <= 250; ++i)
    {
      Serial.println(i);
      for (int i = 0; i < 32; i++)
      {
        robot.moveOneStepForward();
      }
      robot.setSteeringAngle(140-b);
    }
    delay(150);
    b = b+100;
  }
}
