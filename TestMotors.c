#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorC,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,      ,             tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	motor[motorC] = 75;
	wait1Msec(2000);
	motor[motorD] = 75;
	wait1Msec(2000);
	motor[motorH] = 75;
	wait1Msec(2000);
	motor[motorI] = 75;
	wait1Msec(5000);

}
