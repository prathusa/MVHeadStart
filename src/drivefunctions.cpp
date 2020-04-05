#include "main.h"
using namespace vex;

void drive(double distanceInches, int speed) // Speed ranges from 0 to 100
//                     if you put in a negative number for distance then you will move backwards
{
  driveTrain.driveFor(directionType::fwd, distanceInches, distanceUnits::in, speed, velocityUnits::pct);
}

//turn method that turns to a target rotation
void turn(double degrees) //P loop turn code (better than the smartdrive methods once kP is tuned properly)
{
  if(Inertial.installed())
  {
    double target = degrees; // In revolutions
    double error = target - Inertial.rotation();
    double kP = .6;
    if(error > 0)
    {
      
      while (std::abs(error) > 1) //1 allows +- 1 degree variance, don't reduce unless you know what you are doing
      {
        error = target - Inertial.rotation();
        double percent = kP * error + 20;
        leftGroup.spin(directionType::fwd, percent, pct);
	      rightGroup.spin(directionType::rev, percent, pct);
        vex::task::sleep(20);
      }
    }
    else if(error > 0)
    {
      double target = degrees; // In revolutions
      double error = target - Inertial.rotation();
      double kP = .6;
      while (std::abs(error) > 1) //1 allows +- 1 degree variance, don't change unless you know what you are doing
      {
        error = target - Inertial.rotation();
        double percent = kP * error - 20;
        leftGroup.spin(directionType::fwd, percent, pct);
	      rightGroup.spin(directionType::rev, percent, pct);
        vex::task::sleep(20);
      }
    }
    else
    {
      leftGroup.stop();
      rightGroup.stop();
    }
  }
  else
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono40);
    Brain.Screen.setFillColor(red);
    Brain.Screen.print("No Inertial Sensor Installed");
  }
}