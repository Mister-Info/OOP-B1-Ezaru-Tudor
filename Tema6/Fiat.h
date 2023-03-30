#pragma once
#include "Car.h"

class Fiat :public Car {

public:

	double getFuelCapacity();
	double getFuelConsumption();
	double getAverageSpeed(Weather weatherConditions);

};