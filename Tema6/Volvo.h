#pragma once
#include "Car.h"

class Volvo : public Car {

public:
	
	 double getFuelCapacity();
	 double getFuelConsumption();
	 double getAverageSpeed(Weather weatherConditions);
};