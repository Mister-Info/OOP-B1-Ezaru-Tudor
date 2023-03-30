#include "Circuit.h"
using namespace std;
Circuit::Circuit() {
    length = 0;
    weather = Weather::Sunny;
    cars = nullptr;
    finishers = nullptr;
    nonFinishers = nullptr;
    numCars = 0;
    numFinishers = 0;
    numNonFinishers = 0;
}

Circuit::~Circuit() {
    for (int i = 0; i < numCars; ++i) {
        delete cars[i];
    }
    delete[] cars;

   
    delete[] finishers;

    delete[] nonFinishers;

}

void Circuit::SetLength(int length) {
    this->length = length;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}

void Circuit::AddCar(Car* car) {
    Car** newCars = new Car * [numCars + 1];
    for (int i = 0; i < numCars; i++) {
        newCars[i] = cars[i];
    }
    newCars[numCars] = car;
    delete[] cars;
    cars = newCars;
    numCars++;
}

void Circuit::Race() {
    
    int iFinish = 0;
    int iNonFinish = 0;
    for (int i = 0; i < numCars; ++i) {
        if ((cars[i]->getFuelConsumption() * length)/100 > cars[i]->getFuelCapacity())
            numNonFinishers++;
        else numFinishers++;
    }
    finishers = new Car * [numFinishers+1];
    nonFinishers = new Car * [numNonFinishers+1];
    

    for (int i = 0; i < numCars; ++i) {
        if ((cars[i]->getFuelConsumption() * length)/100 > cars[i]->getFuelCapacity())
        {
            nonFinishers[iNonFinish++] = cars[i];
        }
        else {
            finishers[iFinish++] = cars[i];
        }
    }
}

void Circuit::ShowWhoDidNotFinish() {
    for (int i = 0; i < numNonFinishers; ++i)
    {
        cout << "Masina " << i + 1 << " nu a terminat cursa"<<endl;
    }
}

void Circuit::ShowFinalRanks() {
    for(int i=0;i<numFinishers-1;i++)
        for (int j = i + 1; j < numFinishers; j++) {
            if (length / finishers[i]->getAverageSpeed(this->weather) < length / finishers[j]->getAverageSpeed(this->weather))
                std::swap(finishers[i], finishers[j]);
        }
    for (int i = 0; i < numFinishers; i++) {
        cout << length / finishers[i]->getAverageSpeed(this->weather)<<endl;
    }
}