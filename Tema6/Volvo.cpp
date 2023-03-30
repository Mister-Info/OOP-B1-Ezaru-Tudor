#include "Volvo.h"

double Volvo::getFuelCapacity() {

	return 0.0;///litri
}

double Volvo::getFuelConsumption() {
	return 8.0;///litri pe 100 de km
}

double Volvo::getAverageSpeed(Weather weatherConditions) {
	switch (weatherConditions)
	{
	case Sunny: return 150.0;

	case Rain: return 80.0;

	case Snow: return 50.0;

	default: return 0.0;
	}
}