#include "vex.h"
int auton = -1;

void askPosition(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(prop30);
  Brain.Screen.setPenColor(color(180, 180, 180));
  Brain.Screen.printAt(0, 30, "Battery Percentage: %d%%", Brain.Battery.capacity());
  Brain.Screen.setFont(prop20);
  Brain.Screen.drawLine(300, 0, 300, 40);
  Brain.Screen.setPenColor(color(0, 150, 0));
  Brain.Screen.drawRectangle(305, 0, 170, 40, color(0, 150, 0));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(365, 25, false, "Skills");
  Brain.Screen.setPenColor(color(180, 180, 180));
  Brain.Screen.setFont(prop30);
  Brain.Screen.drawLine(0, 40, 480, 40);
  Brain.Screen.setPenColor(color(180, 0, 0));
  Brain.Screen.drawRectangle(10, 50, 220, 85, color(180, 0, 0));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(95, 100, false, "RFS");
  Brain.Screen.setPenColor(color(0, 0, 180));
  Brain.Screen.drawRectangle(250, 50, 220, 85, color(0, 0, 180));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(335, 100, false, "BFS");
  Brain.Screen.setPenColor(color(180, 0, 0));
  Brain.Screen.drawRectangle(10, 145, 220, 85, color(180, 0, 0));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(95, 195, false, "RBS");
  Brain.Screen.setPenColor(color(0, 0, 180));
  Brain.Screen.drawRectangle(250, 145, 220, 85, color(0, 0, 180));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(335, 195, false, "BBS");
  Brain.Screen.setPenColor(color(180, 180, 180));
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
      
      while (std::abs(error) > 1) //1 allows +- 1 degree variance, don't change unless you know what you are doing
      {
        error = target - Inertial.rotation();
        double percent = kP * error + 15;
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
        double percent = kP * error - 15;
        leftGroup.spin(directionType::fwd, percent, pct);
	      rightGroup.spin(directionType::rev, percent, pct);
        vex::task::sleep(20);
      }
    }
    else
    {
      leftGroup.stop();
      rightGroup.stop();
      goto end;
    }
  }
  else
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono40);
    Brain.Screen.setFillColor(red);
    Brain.Screen.print("No Inertial Sensor Installed");
  }
  end:
  vex::task::sleep(10);
}

void pre_auton(void) {
  int xLastTouch = Brain.Screen.xPosition();
  int yLastTouch = Brain.Screen.yPosition();
  askPosition();
  while (Brain.Screen.xPosition() == xLastTouch && Brain.Screen.yPosition() == yLastTouch) {
    vex::task::sleep(20);
  }
  bool k = true;
  while (k) {
    if ((Brain.Screen.xPosition() >= 10 && Brain.Screen.xPosition() <= 230) && (Brain.Screen.yPosition() >= 50 && Brain.Screen.yPosition() <= 135)) {
      auton = 0;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 250 && Brain.Screen.xPosition() <= 470) && (Brain.Screen.yPosition() >= 50 && Brain.Screen.yPosition() <= 135)) {
      auton = 1;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 10 && Brain.Screen.xPosition() <= 230) && (Brain.Screen.yPosition() >= 145 && Brain.Screen.yPosition() <= 230)) {
      auton = 2;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 250 && Brain.Screen.xPosition() <= 470) && (Brain.Screen.yPosition() >= 145 && Brain.Screen.yPosition() <= 230)) {
      auton = 3;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 305 && Brain.Screen.xPosition() <= 475) && (Brain.Screen.yPosition() >= 0 && Brain.Screen.yPosition() <= 40)) {
      auton = 4;
      k = false;
    }
  }

  if (auton == 0) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("RFS Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("RFS Selected");
  } else if (auton == 1) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("BFS Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("BFS Selected");
  } else if (auton == 2) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("RBS Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("RBS Selected");
  } else if (auton == 3) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("BBS Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("BBS Selected");
  } else if (auton == 4) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Skills Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("Skills Selected");
  }

  Inertial.calibrate(2000);
  vex::task::sleep(2000);
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

void autoSkills()
{
    //Code Skills auton here:
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
    else if(auton == 4)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running Skills");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoSkills();
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

        leftGroup.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        rightGroup.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);

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
        }
        else if(Controller1.ButtonB.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else
        {
          //usually the motor stop command goes here
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
          //macro button template
        }

        if(Controller1.ButtonY.pressing())
        {
          //macro button template
        }

        if(Controller1.ButtonLeft.pressing())
        {
          //macro button template
        }

        if(Controller1.ButtonRight.pressing())
        {
          //macro button template
        }

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
