#include "Fiat.h"

double Fiat::getFuelCapacity() {

	return 40.0;///litri
}

double Fiat::getFuelConsumption() {
	return 6.0;///litri pe 100 de km
}

double Fiat::getAverageSpeed(Weather weatherConditions) {
	switch (weatherConditions)
	{
	case Sunny: return 150.0;

	case Rain: return 90.0;

	case Snow: return 50.0;

	default: return 0.0;
	}

}