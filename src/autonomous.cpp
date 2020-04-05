#include "main.h"
using namespace vex;

void autoRFS()
{
    //Code Red Front Side auton here:
}

void autoBFS()
{
    //Code Blue Front Side auton here:
}

void autoRBS()
{
    //Code Red Back Side auton here:
}

void autoBBS()
{
    //Code Blue Back Side auton here:
}

void autoSkills()
{
    //Code Skills auton here:
}

void autonomous()
{
    if(auton == 0)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running RFS");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoRFS();
    }
    else if(auton == 1)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running BFS");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoBFS();
    }
    else if(auton == 2)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running RBS");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoRBS();
    }
    else if(auton == 3)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running BBS");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoBBS();
    }
    else if(auton == 4)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running Skills");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoSkills();
    }
    else if(auton == 6)
    {
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("Running Playback");
      Controller1.Screen.newLine();
      Controller1.Screen.print("Team 8995_");
      uint8_t buf[3000];
      Brain.SDcard.loadfile("data.txt", buf, 3000);
    
      for (int i = 0; i < 3000; i+= 5) 
      {    
          leftGroup.spin(vex::directionType::fwd, buf[i] - 100, vex::velocityUnits::pct);
          rightGroup.spin(vex::directionType::fwd, buf[i + 1] - 100, vex::velocityUnits::pct);
          placeHolderMotor1.spin(vex::directionType::fwd, buf[i + 2] - 100, vex::velocityUnits::pct);
          placeHolderMotor2.spin(vex::directionType::fwd, buf[i + 2] - 100, vex::velocityUnits::pct);
          placeHolderMotor3.spin(vex::directionType::fwd, buf[i + 3] - 100, vex::velocityUnits::pct);
          placeHolderMotor4.spin(vex::directionType::fwd, buf[i + 4] - 100, vex::velocityUnits::pct);
          vex::task::sleep(20);
      }
    }
    else
    {
        //Doesn't run Auton
        Controller1.Screen.clearScreen();
        Controller1.Screen.print(":( i sleep");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
    }
}