#include "RangeRover.h"


double RangeRover::getFuelCapacity() {

	return 80.0;///litri
}

double RangeRover::getFuelConsumption() {
	return 7.0;///litri pe 100 de km
}

double RangeRover::getAverageSpeed(Weather weatherConditions) {
	switch (weatherConditions)
	{
	case Sunny: return 150.0;

	case Rain: return 90.0;

	case Snow: return 50.0;

	default: return 0.0;
	}
}