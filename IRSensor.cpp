getIRError(){
	int frontReading = read_analog(FRONT);
	int leftReading = read_analog(LEFT);
	int rightReading = read_analog(RIGHT);
	
	if(frontReading > threshold){
		
		drive forward	
	}else if(frontReading <= threshold && leftReading <= threshold && rightReading > threshold){
		turn right 90 degrees
	}else if(frontReading <= threshold && leftReading > threshold && rightReading >= threshold){
		turn left 90 degrees
	}else if((frontReading <= threshold && leftReading <= threshold && rightReading <= threshold){
		turn 180 degrees
	}
}
	
