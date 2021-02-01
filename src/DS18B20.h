
#ifndef DS18B20_H
#define DS18B20_H

	#include <Arduino.h>
	#include <ArduinoJson.h>

	#include <OneWire.h>
	#include <DallasTemperature.h>

	class DS18B20Class
	{
		OneWire  			* _whire;
		DallasTemperature  	* _module;
	public:
		DS18B20Class(int pin);
		~DS18B20Class(){};
		
		void begin 				();
		void read_temperature 		(float & result, boolean & isNan);
		void read_temperatureF 		(float & result, boolean & isNan);

		void json 				(JsonObject & root);
		void domoticzJson		(JsonObject & root);
	};
	class DS18B20Managment
	{
	private:
		int _pos = 0;
	public:
		DS18B20Managment();
		~DS18B20Managment(){};

		void create 			(int value, int & result);

		void read_temperature	(float & result, boolean & isNan);
		void read_temperatureF	(float & result, boolean & isNan);
		void read_temperature	(int pos, float & result, boolean & isNan);
		void read_temperatureF	(int pos, float & result, boolean & isNan);

		
		DS18B20Class * module(int pos);
	};
#endif // DS18B20_H