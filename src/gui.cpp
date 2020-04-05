#include "main.h"
using namespace vex;
int auton = -1;

// GUI initialization code, don't change unless you know what you are doing
void askPosition() 
{ 
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

void pre_auton() 
{
  
  if(Inertial.installed())
  {
    Inertial.calibrate(2000);
    vex::task::sleep(2000);
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono40);
    Brain.Screen.setFillColor(red);
    Brain.Screen.print("Inertial Sensor Calibrating");
  }

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
    } else if ((Brain.Screen.xPosition() >= 15 && Brain.Screen.xPosition() <= 135) && (Brain.Screen.yPosition() >= 0 && Brain.Screen.yPosition() <= 40)) {
      auton = 5;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 150 && Brain.Screen.xPosition() <= 290) && (Brain.Screen.yPosition() >= 0 && Brain.Screen.yPosition() <= 40)) {
      auton = 6;
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
  } else if (auton == 5) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Recorder Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("Recorder Selected");
  } else if (auton == 6) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Playback Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("Playback Selected");
  } else {
    Brain.Screen.clearScreen();
    Brain.Screen.print("No Auton Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("No Auton Selected");
  }
}