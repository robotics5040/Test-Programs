#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     spinnerMotor,  tmotorTetrix, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Motor F = Right Back
//Motor G = Right Front
//Motor H = Left Back
//Motor I = Left Front

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous A - Right
//                                  Virtual World Port
//
// Position robot so it is parallel to the creates, go forward sensing IR is 9 at all, if found,
// back up and position robot for dumping cube in create. If not found within certain rotation, back
// up put in last create and attempt to drive up ramp using white line.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}

//For condensed code, this function serves as an easy way to move all motors forward/backwards. Distance is in cm
void forward(int power, int distance)
{
	motor[rightMotor] = power;
	motor[leftMotor] = power;

	if(distance != 0)
	{
		nMotorEncoder[rightMotor] = 0;
		bool go = true;
		while (go)
		{
			if (nMotorEncoder[rightMotor] * ((PI * 10.16) / 360) >= distance)
				go = false;
		}
		motor[rightMotor] = 0;
		motor[leftMotor] = 0;
	}
}

//For condensed code, this function serves as an easy way to turn the robot by specifing the two sides power
void turn(int powL, int powR, int distance)
{
	motor[rightMotor] = powR;
	motor[leftMotor] = powL;

	if(distance != 0)
	{
		nMotorEncoder[rightMotor] = 0;
		bool go = true;
		while (go)
		{
			if (nMotorEncoder[rightMotor] * ((PI * 10.16) / 360) >= distance)
				go = false;
		}
		motor[rightMotor] = 0;
		motor[leftMotor] = 0;
	}
}

task main()
{
  initializeRobot();
  nMotorEncoder[leftMotor] = 0;

  //Find IR
	while(SensorValue(IRSeeker) != 9)
	{
		forward(60, 0);
	}
	forward(0, 0);

	int rotated = nMotorEncoder[leftMotor];

  //Align and drop
	while(SensorValue(IRSeeker) != 5)
		turn(70, -70, 0);
	wait10Msec(15);
	forward(0, 0);
	motor[armMotor] = 40;
	wait10Msec(60);
	motor[armMotor] = 0;
	forward(50, 0); //When ported to our robot, try distance calculator rather than time
	wait10Msec(100);
	forward(0, 0);
	motor[gripperMotor] = -40; // Release cube
	wait10Msec(50);

	//Retrace steps
	forward(-50, 0);
	wait10Msec(130);
	forward(0, 0);
	motor[gripperMotor] = 0;
	motor[armMotor] = -40;
	wait10Msec(60);
	motor[armMotor] = 0;
	if(rotated > -6500)
		while(SensorValue(IRSeeker) != 1)
			turn(-70, 70, 0);
	else
		while(SensorValue(IRSeeker) != 9)
			turn(70, -70, 0);

  //Get to ramp
	//forward(-70, 4);
	//if(rotated > -6500)
		//turn(-70, 70, 3);
}