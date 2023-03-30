#pragma once
#include "Car.h"

class Seat : public Car {

public:
	
	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weatherConditions);
};