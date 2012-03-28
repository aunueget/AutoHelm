int previous_error = setpoint - process_feedback;
float integral = 0
float modPID(int setPoint , int compassReading){
	wait(dt)
	int error = setpoint - compassReading;
	float integral = integral + (error*dt);
	float derivative = (error - previous_error)/dt;
	float output = (Kp*error) + (Ki*integral) + (Kd*derivative);
	previous_error = error;
	return output;
  }