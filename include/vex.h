#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
brain Brain;
motor RightFrontMotor (vex::PORT11, vex::gearSetting::ratio18_1,true);
motor RightRearMotor (vex::PORT12, vex::gearSetting::ratio18_1,true);
motor LeftRearMotor (vex::PORT19, vex::gearSetting::ratio18_1,false);
motor LeftFrontMotor (vex::PORT20, vex::gearSetting::ratio18_1,false);
//Add motor definitions here:
controller Controller1;
competition Competition;
//Add gobal variable initializations here:
int auton;