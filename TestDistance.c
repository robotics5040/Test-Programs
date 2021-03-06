#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     SensorIR,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     SensorColor,    sensorCOLORFULL)
#pragma config(Sensor, S4,     SensorSonic,    sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	nMotorEncoder[motorF] = 0;

	int distance = 30;
	//while ((nMotorEncoder[motorF]/360) * (PI * 5) > distance * -1)
	while (69 * distance > nMotorEncoder[motorF])
	{
		int enc = nMotorEncoder[motorF];
		motor[motorF] = 20;
		motor[motorG] = 20;
		motor[motorH] = 20;
		motor[motorI] = 20;
	}
	motor[motorF] = 0;
	motor[motorG] = 0;
	motor[motorH] = 0;
	motor[motorI] = 0;

}
