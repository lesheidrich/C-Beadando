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
    XMLHandler xmlHandler;
    LicensePlate newLicensePlate();

    void newVehicle(string v);
    void newVehicleMenuSelection();
    void listVehicles();
    void searchByLicensePlate();
    void fileManagement();
//    template<typename T>
//    T readInput();
    template <typename T, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, double>::value, int>::type = 0>
    T readInput();
    void printUnderlinedTitle(string);

};

//// Explicit specialization for int
//template <>
//int MenuController::readInput<int>();
