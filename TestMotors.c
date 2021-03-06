#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorC,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//E R B
//F R F
//H L B
//I L F

task main()
{

	motor[motorE] = 75;
	wait1Msec(2000);
	motor[motorF] = 75;
	wait1Msec(2000);
	motor[motorH] = 75;
	wait1Msec(2000);
	motor[motorI] = 75;
	wait1Msec(5000);

}
