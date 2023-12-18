#pragma once

#include <iostream>
#include <chrono>

#include "pugixml.hpp"
#include "XMLHandler.hpp"

#include "LicensePlate.hpp"
#include "Car.hpp"
#include "Bus.hpp"
#include "Truck.hpp"
#include "Machinery.hpp"

class MenuController
{
public:

//private:
    XMLHandler xmlHandler;
    LicensePlate newLicensePlate();
    void newCar();
    void newBus();
    void newTruck();
    void newMachinery();
};
