#include "Seat.h"

double Seat::getFuelCapacity() {

	return 30.0;///litri
}

double Seat::getFuelConsumption() {
	return 4.0;///litri pe 100 de km
}

double Seat::getAverageSpeed(Weather weatherConditions) {
	switch (weatherConditions)
	{
	case Sunny: return 150.0;
		
	case Rain: return 90.0;
		
	case Snow: return 50.0;
		
	default: return 0.0;
	}
	
}