#include "Car.h" 
#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "Fiat.h"
#include "Seat.h"
#include "RangeRover.h"

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Sunny);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();
}
