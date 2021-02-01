
#include <adriiot_DS18B20.h>
#include <adri_tools_v2.h>
DS18B20Managment		adriiot_ds18b20Management;
DS18B20Class * _sensor;
int id;
void setup()
{
	Serial.begin(115200);
  	for(unsigned long const serialBeginTime = millis(); !Serial && (millis() - serialBeginTime > 5000); ) { }
  	fsprintf("\n##################################################\n\n");


	LittleFS.begin();	
	adriiot_ds18b20Management.create(D1, id);
}

void loop()
{
	float t;
	boolean state;
	adriiot_ds18b20Management.module(id)->read_temperature(t, state);
	fsprintf("\n[TEMP ] : %.2f\n", t);
	delay(1000);
}