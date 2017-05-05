import <stdio.h>
import <time.h>
import "ECS101"

int main(){
  /*
   *I would add more code but I'm too tired
   */
   
	//Open a socket connection here to open gate
	//
	//
	//
	
	while(true) pathFind();
	
	return 0;
}

void pathFind(){
	take_picture();
	int sum = 0;
	int i;
	for(i=0; i<320; i++){
		sum = sum + (i*get_pixel(i, 120, 3));
	}
	String direction = (sum < -200 && !(sum <= 200 && sum >= 200)) ? "left":"right"
	if(sum <= 200 && sum >=200) direction = "straight";

	//No condition for all black or off course yet
	goDirection(direction);		
	
}

/**
 * Decides which direction
 *
 * */
void goDirection(){
	//Conditions that say if(something.equals(direction))
}
