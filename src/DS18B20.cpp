#include "DS18B20.h"

#define MAX_SENSOR 10
DS18B20Class 	* DS18B20ClassArray[MAX_SENSOR];

DS18B20Managment::DS18B20Managment(){

}

void DS18B20Managment::create(int value, int & result){
	DS18B20ClassArray[_pos] = new DS18B20Class(value);
	result = _pos;
	_pos++;
}

void DS18B20Managment::read_temperature(float & result, boolean & isNan){
	for (int i = 0; i < _pos; ++i) {DS18B20ClassArray[i]->read_temperature(result, isNan);}
}
void DS18B20Managment::read_temperatureF(float & result, boolean & isNan){
	for (int i = 0; i < _pos; ++i) {DS18B20ClassArray[i]->read_temperatureF(result, isNan);}
}
void DS18B20Managment::read_temperature(int pos, float & result, boolean & isNan){
	DS18B20ClassArray[pos]->read_temperature(result, isNan);
}
void DS18B20Managment::read_temperatureF(int pos, float & result, boolean & isNan){
	DS18B20ClassArray[pos]->read_temperatureF(result, isNan);
}


DS18B20Class * DS18B20Managment::module(int pos){
	return DS18B20ClassArray[pos];
}




DS18B20Class::DS18B20Class(int pin) {
	_whire 	= new OneWire(pin);
	_module = new DallasTemperature(_whire);
	begin();
	_module->setResolution(9);
}
void DS18B20Class::begin(){
	_module->begin();	
}
void DS18B20Class::read_temperature(float & result, boolean & isNan){
	_module->requestTemperatures(); 
	float temp = _module->getTempCByIndex(0);
	if(temp != DEVICE_DISCONNECTED_C) 	isNan = true;
	else 								isNan = false;
	result = temp;
}
void DS18B20Class::read_temperatureF(float & result, boolean & isNan){
	_module->requestTemperatures(); 
	float temp = _module->getTempFByIndex(0);
	if(temp != DEVICE_DISCONNECTED_C) 	isNan = true;
	else 								isNan = false;
	result = temp;
}
void DS18B20Class::json(JsonObject & root){
	float value_1;
	float value_2;
	boolean state;
	read_temperature(value_1, state);
	read_temperatureF(value_2, state);
	root[F("v1")] = value_1;
	root[F("v2")] = value_2;
}
void DS18B20Class::domoticzJson(JsonObject & root){
	float value_1;
	boolean state;
	read_temperature(value_1, state);
	root[F("nvalue")] = 0;
	root[F("svalue")] = String(value_1) ;
}