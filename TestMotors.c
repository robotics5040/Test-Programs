#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
//TODO: Check the robot to see the pathing and enter for motor variables
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop)

task main()
{

	motor[motorB] = 75;
	wait1Msec(2000);
	motor[motorC] = 75;
	wait1Msec(2000);
	motor[motorD] = 75;
	wait1Msec(2000);
	motor[motorE] = 75;
	wait1Msec(5000);

}
