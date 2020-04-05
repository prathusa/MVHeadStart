#include "main.h"

//Auton recorder, do not change at all unless you know what you are doing (except for save file name if needed) 
void auton_recorder()
{
    uint8_t data[3000];
    Controller1.Screen.clearScreen();
    for(int count = 5; count > 0; count--)
    {
      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print(count);
      vex::task::sleep(1000);
    }
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Recording");
    for (int i = 0; i < 3000; i+= 5) 
    {
        controls();

        data[i] = (uint8_t) (leftGroup.velocity(vex::velocityUnits::pct) + 100);
        data[i + 1] = (uint8_t) (rightGroup.velocity(vex::velocityUnits::pct) + 100);
        data[i + 2] = (uint8_t) (placeHolderMotor1.velocity(vex::velocityUnits::pct) + 100);
        data[i + 3] = (uint8_t) (placeHolderMotor3.velocity(vex::velocityUnits::pct) + 100);
        data[i + 4] = (uint8_t) (placeHolderMotor4.velocity(vex::velocityUnits::pct) + 100);
        vex::task::sleep(20);
    }
    //Changing "data.txt" will change the savefile name, this will allow multiple recordings 
    Brain.SDcard.savefile("data.txt", data, 3000);
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Complete!");  
}