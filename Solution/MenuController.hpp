#pragma once

#include <iostream>
#include <stdexcept>
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
    void run();

private:
    // attribute
    XMLHandler xmlHandler;
    // methods
    void newVehicleMenuSelection();
    void newVehicle(string v);
    LicensePlate newLicensePlate();

    void listVehicles();
    void searchByLicensePlate();
    void fileManagement();
    void printUnderlinedTitle(string);
    template <typename T, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, double>::value, int>::type = 0>
    T readInput();
};
