
/*****************************************************************************
Name:        getCompassReading 
Parameters:        none             
Returns:        a newly read compass heading from the digital compass
Description:  returns a newly read compass heading from the digital compass   

*****************************************************************************/
int getCompassReading(int avg){
	double newDigitHeading=get_digital_heading();
	double old_value=heading.current;
	newDigitHeading-=180;//flip the compass to correct digital compass position
    if (newDigitHeading < 0) newDigitHeading += 360;
	if(abs(old_value-newDigitHeading)>180)
		old_value=newDigitHeading+degreeDifferance(1,old_value,newDigitHeading);
	if(avg&&degreeDifferance(1,old_value,newDigitHeading)<20){
		newDigitHeading=((5.0/16.0)*old_value)+(((16.0-5.0)/16.0)*newDigitHeading);
	}
	if(newDigitHeading>360)
		newDigitHeading-=360;
return (int)newDigitHeading;
}

/* if the absoluteValue is set to 0 then degreeDifferance will have a sign pos or  neg */
int degreeDifferance(int absoluteValue,int current,int desired){
	int compDiff=0;
	int accrossN=0;
	compDiff=abs(current-desired);
	if(compDiff>180){
		compDiff=abs(compDiff-360);
		accrossN=1;
	}
	if(absoluteValue || ((heading.current>heading.desired && accrossN==0) || (accrossN==1 && heading.current<heading.desired))){
		return compDiff;
	}
	else{
		return (-1*compDiff);
	}
}
