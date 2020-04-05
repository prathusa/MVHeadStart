#pragma once //You should include this on the top of all of your include files (.h/.hpp files)

extern vex::brain Brain;
extern vex::controller Controller1;
extern vex::competition Competition;

//Add motor definitions here:
extern vex::motor rightFrontMotor;
extern vex::motor rightRearMotor;
extern vex::motor leftRearMotor;
extern vex::motor leftFrontMotor;
extern vex::motor placeHolderMotor1;
extern vex::motor placeHolderMotor2;
extern vex::motor placeHolderMotor3;
extern vex::motor placeHolderMotor4;
//extern vex::motor placeHolderTorqueMotor;
//extern vex::motor placeHolderSpeedMotor;

//Add sensor definitions here:
extern vex::inertial Inertial;
extern vex::pot Potentiometer;
extern vex::limit LimitSwitch;

//Add motor_group/drivetrain definitions here:
extern vex::motor_group leftGroup;
extern vex::motor_group rightGroup;
extern vex::drivetrain driveTrain;
extern vex::smartdrive smartDrive;