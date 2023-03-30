#pragma once
#include "Car.h"

class Circuit {
public:
    Circuit();
    ~Circuit();
    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();

    Car** finishers;
    Car** nonFinishers;
private:
    int length;
    Weather weather;
    Car** cars;
    int numCars;
    
    int numFinishers;
   
    int numNonFinishers;
   
};