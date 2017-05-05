import <stdio.h>
import <time.h>
import "ECS101"

int main(){
	/*I would add more code but I'm too tired*/
	//Open a socket connection here to open gate
	
	while(true) pathFind();
	return 0;
}


/* This doesn't work properly for now because I don't know proper values*/
void pathFind(){
	take_picture();
	int sum = 0;
	for(int i=-160; i<160; i++){
		sum+= + (i*get_pixel(i, 120, 3));
	}
	//These threshold values are imaginary for now, change them when we find out real black and white values
	String direction = (sum < -300 && !(sum <= 300 && sum >= 300)) ? "left":"right"
	if(sum <=300 && sum >=300) direction = "straight";
	goDirection(direction);		
}

/*Changes motor settings based on direction*/
void goDirection(){
	//Conditions that say if(something.equals(direction))
}
