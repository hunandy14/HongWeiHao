#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "fun.h"

Demo::Demo(int a){
	this->i = a;
}
int Demo::get(){
	return this->i;
}