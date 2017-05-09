//THIS PID FILE IS A PROTOTYPE

//Include h files here

/*
* Problems with this file included here:
* we need a totalError to be passed as an argument in the first place
* need to find a integralResponse
* need properheaders
*
* unsure about derivativeResponse method regarding taking previous error and current error
* the reason is because to get a current error other than a previous error, it needs to drive straight to find
* a difference of pixels
*/
int proportionalSignal(int totalError){
  int kp = 0.5;
  int proportionalSignal = error*kp;
  //Debugging
  printf("Proportional signal is: %d", proportionalSignal);
  return proportionalSignal;
}

int derivativeResponse(int totalError){
  int previousError = totalError;
  int currentError = getError();
  int kd = 5.0;
  
  Sleep(1,0); //Sleep 1  second enough to find a significant df
  derivativeSignal = (currentError-previousError/0.1)*kd;
  //Debugging
  printf("Derivative signal is: %d", derivativeSignal);
  return derivativeSignal;
}
