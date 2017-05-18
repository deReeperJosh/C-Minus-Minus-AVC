
//Put headers here, I don't know each one of them

//CHANGE THIS METHOD, IT'S JUST THE GENERAL IDEA
//Skeleton code

void getErrorWallks(){
  int irReading1;
  int irReading2;
  int irReading3;
  int threshold = 100;
  
  irReading1 = read_analog();
  irReading2 = read_analog();
  irReading3 = read_analog();
  
  if(irReading2 > threshold){
    //forward
  }else if(irReading1 > threshold){
    //left
  }else if(irReading3 > threshold){
     //right
  } 
}
