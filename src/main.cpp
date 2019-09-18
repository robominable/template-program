/*
      READ THE VEXCODE TUTORIAL IF YOU HAVE ANY QUESTIONS
*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Todd Rylaarsdam                                           */
/*    Created:      Thu Sep 12 2019                                           */
/*    Description:  Template program                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vex.h"
#include "visionSensor.h"

using namespace vex;

//REMOVE THE "//""  ON THE LINE WITH YOUR TYPE  OF DRIVE (e.g. if you have an xDrive remove the // on line 24)

//#define linearDrive
//#define mechDrive
//#define xDrive



// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::controller Controller = vex::controller(vex::controllerType::primary);
vex::motor FLdrive = vex::motor(PORT1,vex::gearSetting::ratio18_1,false); 
vex::motor FRdrive = vex::motor(PORT2,vex::gearSetting::ratio18_1,false);
vex::motor BLdrive = vex::motor(PORT3,vex::gearSetting::ratio18_1,false);
vex::motor BRdrive = vex::motor(PORT4,vex::gearSetting::ratio18_1,false);

// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    //MECH DRIVES
    #ifdef mechDrive
    int creep;
        creep = float(0.05);
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep || Controller.Axis4.position(vex::percentUnits::pct) > creep || Controller.Axis4.position(vex::percentUnits::pct) < -creep){
            FLdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct) + Controller.Axis4.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            FLdrive.stop();
          }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            BLdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct) - Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            BLdrive.stop();
          }
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep || Controller.Axis4.position(vex::percentUnits::pct) > creep || Controller.Axis4.position(vex::percentUnits::pct) < -creep){
            FRdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct) - Controller.Axis4.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            FRdrive.stop();
          }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            BRdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct) + Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            BRdrive.stop();
          }
      #endif

      //XDRIVE
      #ifdef xDrive
      int creep;
        creep = float(0.05);
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep || Controller.Axis4.position(vex::percentUnits::pct) > creep || Controller.Axis4.position(vex::percentUnits::pct) < -creep){
            FLdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct) + Controller.Axis4.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            FLdrive.stop();
          }
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            BLdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct) - Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            BLdrive.stop();
          }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep || Controller.Axis4.position(vex::percentUnits::pct) > creep || Controller.Axis4.position(vex::percentUnits::pct) < -creep){
            FRdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct) - Controller.Axis4.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            FRdrive.stop();
          }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            BRdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct) + Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            BRdrive.stop();
          }
        #endif 

    //4 WHEEL LINEAR DRIVE 
    #ifdef linearDrive
    int creep;
        creep = float(0.05);
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep){
            FLdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
            BLdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
            else{
                FLdrive.stop();
                BLdrive.stop();
            }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep){
            FRdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
            BRdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
            else{
                FRdrive.stop();
                BRdrive.stop();
              }
      #endif
      
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................

 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}