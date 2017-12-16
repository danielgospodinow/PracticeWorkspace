#include <AFMotor.h>

AF_DCMotor motor_m1(1);
AF_DCMotor motor_m2(2);
AF_DCMotor motor_m3(3);
AF_DCMotor motor_m4(4);

void setup()
{
motor_m1.setSpeed(255);
motor_m2.setSpeed(255);
motor_m3.setSpeed(255);
motor_m4.setSpeed(255);
}

//FORWARD - napred
//BACKWARD - nazad
//RELEASE - stop

void loop()
{
    moveForeward();
    delay(1000);
    stopMotors();
    delay(1000);
    moveBackward();
    delay(1000);
    stopMotors();
    delay(1000);
}

void moveForeward()
{
  motor_m1.run(FORWARD);
  motor_m2.run(FORWARD);
  motor_m3.run(FORWARD);
  motor_m4.run(FORWARD);
}

void moveBackward()
{
  motor_m1.run(BACKWARD);
  motor_m2.run(BACKWARD);
  motor_m3.run(BACKWARD);
  motor_m4.run(BACKWARD);
}

void stopMotors()
{
  motor_m1.run(RELEASE);
  motor_m2.run(RELEASE);
  motor_m3.run(RELEASE);
  motor_m4.run(RELEASE);
}
