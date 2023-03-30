#include "BMW.h"

double BMW::getFuelCapacity() {

	return 60.0;///litri
}

double BMW::getFuelConsumption() {
	return 10.0;///litri pe 100 de km
}

double BMW::getAverageSpeed(Weather weatherConditions) {
	switch (weatherConditions)
	{
	case Sunny: return 150.0;

	case Rain: return 90.0;

	case Snow: return 50.0;

	default: return 0.0;
	}

}