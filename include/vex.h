#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include <unistd.h>

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
motor placeHolderMotor1 (vex::PORT1, vex::gearSetting::ratio18_1);
motor placeHolderMotor2 (vex::PORT2, vex::gearSetting::ratio18_1);
motor placeHolderMotor3 (vex::PORT3, vex::gearSetting::ratio18_1);
motor placeHolderMotor4 (vex::PORT3, vex::gearSetting::ratio18_1);
//motor placeHolderTorqueMotor (vex::PORT3, vex::gearSetting::ratio36_1);
//motor placeHolderSpeedMotor (vex::PORT3, vex::gearSetting::ratio6_1);

//Add sensor definitions here:
inertial Inertial(vex::PORT20);
pot Potentiometer(Brain.ThreeWirePort.A);

//Add motor_group/drivetrain definitions here:
motor_group leftGroup(leftFrontMotor, leftRearMotor);
motor_group rightGroup(rightFrontMotor, rightRearMotor);
drivetrain driveTrain(leftGroup, rightGroup);
smartdrive smartDrive(leftGroup, rightGroup, Inertial, 12.56, 16, 16, distanceUnits::in);
