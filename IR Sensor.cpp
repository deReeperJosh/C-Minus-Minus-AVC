int getIRValue(int pin){
  
	//This sets up the RPi hardware and ensures 
	//everything is working correctly
	init();
	//We declare an integer variable to store the ADC data
	int adc_reading;
	//Reads from Analog Pin 0 (A0) 
	adc_reading = read_analog(0);
	//Prints read analog value 
	printf("%d\n",adc_reading); 
	//Waits for 0.5 seconds (500000 microseconds)
	sleep1(0,500000); 
return adc_reading;}
