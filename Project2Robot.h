namespace proj2
{
  class Project2Robot
  {
  public:
    void setSteeringAngle(double);
    void adjustSteeringAngle(double);
    bool isSteeringAngleOK();
    void moveForwardOneStep();
    void moveBackwardOneStep();
    double readForwardDistance();
  }
}
