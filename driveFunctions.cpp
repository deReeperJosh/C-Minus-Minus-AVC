//driveForward is a function, given a time and speed will drive the robot forward
void driveForward(time, speed){ //takes a speed between the values -254 and 254, takes a time in seconds\
  set_motor(RIGHT_MOTOR,speed);//turns the right motor on
  set_motor(LEFT_MOTOR,-speed);//turns the left motor on in the opposite direction
  sleep1(0,time*1000000); //sleep1 takes time in micro-seconds so this needs to be multiplied by 10 
  stopDriving();

}
void driveBackward(time, speed){
  driveForward(time, -speed);
}
void turnRight(time, speed){
  set_motor(RIGHT_MOTOR,STABLE_SPEED);//turns the right motor on
  set_motor(LEFT_MOTOR,-speed);//turns the left motor on in the opposite direction
  sleep1(0,time*1000000); //sleep1 takes time in micro-seconds so this needs to be multiplied by 10 
  stopDriving();
}
void turnLeft(time, speed){
  set_motor(RIGHT_MOTOR,speed);//turns the right motor on
  set_motor(LEFT_MOTOR,-STABLE_SPEED);//turns the left motor on in the opposite direction
  sleep1(0,time*1000000); //sleep1 takes time in micro-seconds so this needs to be multiplied by 10 
  stopDriving();
}
void stopDriving(){
  set_motor(RIGHT_MOTOR,0);
  set_motor(LEFT_MOTOR,0);
}
