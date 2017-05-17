
//Put headers here, I don't know each one of them

//CHANGE THIS FUCKING METHOD, IT'S JUST THE GENERAL IDEA
//Skeleton code
void getErrorWalls(){
  int threshold = 0;
  //ir 1 - left
  //ir 2 - straight
  //ir 3 - right
  
  //Get values here for IR cameras
  
  //Going above threshold means detecting walls
  if(ir1 < threshold){
    turnLeft();
  }else if(ir2 < threshold){
    straight();
  }else if(ir3 < threshold){
    turnRight();
  }else{
    //back 
  }
}
