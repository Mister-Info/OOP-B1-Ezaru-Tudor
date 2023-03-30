#pragma once
#include "Car.h"

class BMW : public Car {

public:
	
	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weatherConditions);
};