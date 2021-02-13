
#include <adriiot_DS18B20.h>

DS18B20Managment		adriiot_ds18b20Management;
DS18B20Class * _sensor;

int id;

void setup()
{
	Serial.begin(115200);
  	for(unsigned long const serialBeginTime = millis(); !Serial && (millis() - serialBeginTime > 5000); ) { }
  	Serial.printf("\n##################################################\n\n");

	adriiot_ds18b20Management.create(D1, id);
}

void loop()
{
	float t;
	boolean state;
	adriiot_ds18b20Management.module(id)->read_temperature(t, state);
	Serial.printf("\n[TEMP ] : %.2f\n", t);
	delay(1000);
}