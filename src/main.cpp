#include "vex.h"
auton = -1;

void askPosition()
{
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono40);
    Brain.Screen.drawRectangle(0, 0, 240, 115, red); //RFS
    Brain.Screen.printAt(90,70,"RFS");
    Brain.Screen.drawRectangle(240, 0, 240, 115, blue); //BFS
    Brain.Screen.printAt(330,70,"BFS");
    Brain.Screen.drawRectangle(0, 115, 240, 115, red); //RBS
    Brain.Screen.printAt(90,180,"RBS");
    Brain.Screen.drawRectangle(240, 115, 240, 115, blue); //BBS
    Brain.Screen.printAt(330,180,"BBS");
}

void pre_auton(void) 
{
    int xLastTouch = Brain.Screen.xPosition();
    int yLastTouch = Brain.Screen.yPosition();
    askPosition();
    while(Brain.Screen.xPosition() == xLastTouch && Brain.Screen.yPosition() == yLastTouch)
    {
        vex::task::sleep(20);
    }
    bool k = true;
    while(k)
    {
        if(Brain.Screen.xPosition() < 240 && Brain.Screen.yPosition() < 115 && Brain.Screen.xPosition() > 0)
        {
            auton = 0;
            k = false;
        }
        else if(240 < Brain.Screen.xPosition() && Brain.Screen.yPosition() < 115 && Brain.Screen.xPosition() > 0)
        {
            auton = 1;
            k = false;
        }
        else if(Brain.Screen.xPosition() < 240 && 115 < Brain.Screen.yPosition() && Brain.Screen.xPosition() > 0)
        {
            auton = 2;
            k = false;
        }
        else if(240 < Brain.Screen.xPosition() && 115 < Brain.Screen.yPosition() && Brain.Screen.xPosition() > 0)
        {
            auton = 3;
            k = false;
        } 
    }
    
    if(auton == 0)
    {
        Brain.Screen.clearScreen();
        Brain.Screen.print("RFS Selected");
        Brain.Screen.newLine();
        Brain.Screen.print("By: Pratham Baid");
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("RFS Selected");
        Controller1.Screen.newLine();
        Controller1.Screen.print("By: Pratham");
    }
    else if(auton == 1)
    {
        Brain.Screen.clearScreen();
        Brain.Screen.print("BFS Selected");
        Brain.Screen.newLine();
        Brain.Screen.print("By: Pratham Baid");
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("BFS Selected");
        Controller1.Screen.newLine();
        Controller1.Screen.print("By: Pratham");
    }
    else if(auton == 2)
    {
        Brain.Screen.clearScreen();
        Brain.Screen.print("RBS Selected");
        Brain.Screen.newLine();
        Brain.Screen.print("By: Pratham Baid");
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("RBS Selected");
        Controller1.Screen.newLine();
        Controller1.Screen.print("By: Pratham");
    }
    else if(auton == 3)
    {
        Brain.Screen.clearScreen();
        Brain.Screen.print("BBS Selected");
        Brain.Screen.newLine();
        Brain.Screen.print("By: Pratham Baid");
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("BBS Selected");
        Controller1.Screen.newLine();
        Controller1.Screen.print("By: Pratham");
    }
   
}

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

void autonomous(void) 
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
    else
    {
        //Doesn't run Auton
        Controller1.Screen.clearScreen();
        Controller1.Screen.print(":( i sleep");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
    }
}

void usercontrol(void) 
{
    while(1) 
    {
        // ------------------------Drive
        
        LeftFrontMotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        RightFrontMotor.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
        LeftRearMotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        RightRearMotor.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
        
        // -----------------------------Add Button Commands Here:


    }
}

int main() {
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Prevent main from exiting with an infinite loop.                        
    while(1) 
    {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
}