/*
 * slave.ino
 *
 * Created: 3/24/2015 9:15:23 PM
 * Author: Matyi
 */ 

#include <Wire.h>
#include "DHT.h"
#include "LedControl.h"


#define DHTTYPE DHT22
int DHTPIN = 9;
DHT dht(DHTPIN, DHTTYPE);
float t=444;
int temp;
LedControl lc=LedControl(12,11,10,1);
long previousMillis = 0;
long interval1=10000;  //  the measurment updates every 30 seconds
unsigned long delaytime=250;

void setup()
{

	pinMode(DHTPIN, INPUT);

	lc.shutdown(0,false);
	/* Set the brightness to a medium values */
	lc.setIntensity(0,8);
	/* and clear the display */
	lc.clearDisplay(0);

	Serial.begin(9600);
	Serial.println(55555555);
	dht.begin();
	//delay(5000);
	Wire.begin(5);
	Wire.onReceive(dataready);
	Wire.onRequest(datarequest);

}


void loop()
{
	if(millis() - previousMillis > interval1)
	{
		previousMillis = millis();
		float t = dht.readTemperature();
		temp = int(t+0.5);
		Serial.println("update");
		Serial.println(t);
		sevenseg(t);

	}
	
}


void sevenseg(float t)
{	Serial.println("sevseg");
	short ones, tens, hundreds;
	int input_number=int(10*t);
	hundreds = int(input_number/100);

	tens = int(input_number/10);
	tens = tens-(int(tens/10)*10);

	ones = input_number-(int(input_number/10)*10);

	lc.setDigit(0,4,hundreds,false);
	lc.setDigit(0,5,tens,false);
	lc.setDigit(0,6,ones,false);
	lc.setChar(0,7,'C',false);
	lc.setLed(0,5,0,true);
}




void dataready(int nobytes)
{

}

void datarequest()
{
	Wire.write(temp);
	
	
}


