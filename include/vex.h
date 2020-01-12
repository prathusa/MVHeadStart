#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
brain Brain;
controller Controller1;
competition Competition;

//Add motor definitions here:
motor rightFrontMotor (vex::PORT11, vex::gearSetting::ratio18_1, true);
motor rightRearMotor (vex::PORT12, vex::gearSetting::ratio18_1, true);
motor leftRearMotor (vex::PORT19, vex::gearSetting::ratio18_1, false);
motor leftFrontMotor (vex::PORT20, vex::gearSetting::ratio18_1, false);

//Add sensor definitions here:
inertial Inertial(vex::PORT20);
pot Potentiometer(Brain.ThreeWirePort.A);

//Add motor_group/drivetrain definitions here:
motor_group rightGroup(rightFrontMotor, rightRearMotor); 
motor_group leftGroup(leftFrontMotor, leftRearMotor);
drivetrain driveTrain(leftGroup, rightGroup);
smartdrive smartDrive(leftGroup, rightGroup, Inertial, 12.56, 16, 16, distanceUnits::in);
