#include "main.h"
using namespace vex;

void X_Button_Macro()
{

}

void Y_Button_Macro()
{
  
}

void Left_Button_Macro()
{
  
}

void Right_Button_Macro()
{
  
}

void drive_Tank() {
  leftGroup.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
  rightGroup.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
}

void drive_Arcade() {
  leftGroup.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  rightGroup.spin(vex::directionType::fwd, Controller1.Axis3.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
}

void controls()
{
        // ------------------------Drive

        drive_Arcade();
        // drive_Tank(); - Switch between the 2 and find what you/your driver wants to use

        // -----------------------------Add Button Commands Here:
        
        /* 
        
        -Not all of these if statements need code in them.
            You just need to code the buttons you want to use with the commands that you want the button press to complete.
        -Basically, all of these if statements sense if the button is pressing on the controller 
            and if that is true does all of the commands enclosed in the brackets {} of the statement.
        
        */
        if(Controller1.ButtonA.pressing())
        {
          //add commands here to complete when button is pressing
          //Demo code:
          placeHolderMotor1.spin(forward, 100, percentUnits::pct);
        }
        else if(Controller1.ButtonB.pressing())
        {
          //add commands here to complete when button is pressing
          //Demo code:
          placeHolderMotor1.spin(reverse, 100, percentUnits::pct);
        }
        else
        {
          //usually the motor stop command goes here
          //Demo code:
          placeHolderMotor1.stop(brakeType::brake); 
          //You can change the type of brake to better suit the type of system
          //For example,  use brake type hold for lift/arm mechanisms
        }

        if(Controller1.ButtonUp.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else if(Controller1.ButtonDown.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else
        {
          //usually the motor stop command goes here
        }

        if(Controller1.ButtonR1.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else if(Controller1.ButtonR2.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else
        {
          //usually the motor stop command goes here
        }

        if(Controller1.ButtonL1.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else if(Controller1.ButtonL2.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else
        {
          //usually the motor stop command goes here
        }

        if(Controller1.ButtonX.pressing())
        {
          X_Button_Macro();
        }

        if(Controller1.ButtonY.pressing())
        {
          Y_Button_Macro();
        }

        if(Controller1.ButtonLeft.pressing())
        {
          Left_Button_Macro();
        }

        if(Controller1.ButtonRight.pressing())
        {
          Right_Button_Macro();
        }
}

void usercontrol()
{
    if(auton == 5) 
    {
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("Running Recorder");
      Controller1.Screen.newLine();
      Controller1.Screen.print("Team 8995_");
    }
    while(1)
    {
      if(auton == 5) 
      {
        auton_recorder();
      } else 
      {
        controls();
      }
    }
}
