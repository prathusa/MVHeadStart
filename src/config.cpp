#include "main.h"
using namespace vex;
brain Brain;
controller Controller1;
competition Competition;

//Add motor definitions here:
motor rightFrontMotor (vex::PORT11, vex::gearSetting::ratio18_1, true); //Change the port number to change the port
motor rightRearMotor (vex::PORT12, vex::gearSetting::ratio18_1, true); //Change the port number to change the port
motor leftRearMotor (vex::PORT19, vex::gearSetting::ratio18_1, false); //Change the port number to change the port
motor leftFrontMotor (vex::PORT20, vex::gearSetting::ratio18_1, false); //Change the port number to change the port
motor placeHolderMotor1 (vex::PORT1, vex::gearSetting::ratio18_1); //Change the port number to change the port
motor placeHolderMotor2 (vex::PORT2, vex::gearSetting::ratio18_1); //Change the port number to change the port
motor placeHolderMotor3 (vex::PORT3, vex::gearSetting::ratio18_1); //Change the port number to change the port
motor placeHolderMotor4 (vex::PORT3, vex::gearSetting::ratio18_1); //Change the port number to change the port
//motor placeHolderTorqueMotor (vex::PORT3, vex::gearSetting::ratio36_1); //Just change the gearsetting on 
//                                                            the motor that has a changed insert to match these demo motors
//motor placeHolderSpeedMotor (vex::PORT3, vex::gearSetting::ratio6_1);

//Add sensor definitions here:
inertial Inertial(vex::PORT20); //Change the number to change the port
pot Potentiometer(Brain.ThreeWirePort.A); //Change the letter to change the port
limit LimitSwitch(Brain.ThreeWirePort.H); //Change the letter to change the port

//Add motor_group/drivetrain definitions here:
motor_group leftGroup(leftFrontMotor, leftRearMotor);
motor_group rightGroup(rightFrontMotor, rightRearMotor);
drivetrain driveTrain(leftGroup, rightGroup);
smartdrive smartDrive(leftGroup, rightGroup, Inertial, 12.56, 16, 16, distanceUnits::in);