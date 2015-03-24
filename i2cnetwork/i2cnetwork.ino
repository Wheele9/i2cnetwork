/*
 * i2cnetwork.ino
 *
 * Created: 3/24/2015 9:14:57 PM
 * Author: Matyi
 */ 
#include <Wire.h>


void setup()
{
	pinMode(3, OUTPUT);
	Serial.begin(9600);
	Wire.begin();
}


void loop(){
/*
	analogWrite(3, PWM_Input);
	Wire.beginTransmission(B0001111);
	Wire.write('$');
	Wire.write("I'm Counting ");
	Wire.write('#');
	Wire.write(counter);
	Wire.write(low);
	Wire.write(high);
	Wire.endTransmission();
	counter++;
	delay(25);*/


	Wire.requestFrom(5, 1);
	while(Wire.available())
	{
		c=Wire.read();
		Serial.println(c);
	}
}//loop
