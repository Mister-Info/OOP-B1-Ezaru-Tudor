#pragma once
#include "Car.h"

class RangeRover : public Car {

public:
	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weatherConditions);

};