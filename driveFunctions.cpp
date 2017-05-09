//driveForward is a function, given a speed will drive the robot forward

#include "driveFunctions.h"

void driveForward(int speed){ //takes a speed between the values -254 and 254
  set_motor(RIGHT_MOTOR,speed);/
  set_motor(LEFT_MOTOR,-speed);
  sleep1(SLEEP_TIME_SECONDS,SLEEP_TIME_MICROSECONDS);  
  stopDriving();

}
void driveBackward(int speed){
  driveForward(-speed);
}
void turnRight(int speed){
  set_motor(RIGHT_MOTOR,STABLE_SPEED);
  set_motor(LEFT_MOTOR,-speed);
  sleep1(SLEEP_TIME_SECONDS,SLEEP_TIME_MICROSECONDS); 
  stopDriving();
}
void turnLeft(int speed){
  set_motor(RIGHT_MOTOR,speed);
  set_motor(LEFT_MOTOR,-STABLE_SPEED);
  sleep1(SLEEP_TIME_SECONDS,SLEEP_TIME_MICROSECONDS);  
  stopDriving();
}
void stopDriving(){
  set_motor(RIGHT_MOTOR,0);
  set_motor(LEFT_MOTOR,0);
}
