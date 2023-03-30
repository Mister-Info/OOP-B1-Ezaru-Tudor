#pragma once
#include <iostream>
#include <algorithm>

enum Weather { Sunny, Rain, Snow };

class Car {

public:
	
	virtual double getFuelCapacity()=0;
	virtual double getFuelConsumption()=0;
	virtual double getAverageSpeed(Weather weatherConditions)=0;
};
