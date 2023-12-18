#pragma once

#include <iostream>
#include <chrono>
#include <string>

#include "Car.hpp"
#include "Bus.hpp"
#include "Truck.hpp"
#include "Machinery.hpp"
#include "pugixml.hpp"

class XMLHandler
{
public:
    // constructor
    XMLHandler();

    void addCar(Car* c);
    void addBus(Bus* b);
    void addTruck(Truck* t);
    void addMachinery(Machinery* m);
    void readAll();
    void deleteByLicensePlate(string licensePlate_p);
private:
    // attributes
    pugi::xml_document vehiclesXML;
    pugi::xml_node fleetNode;
    pugi::xml_parse_result result;
    std::string licensePlateNumber;
    std::string licensePlateIssuingCountry;
    std::string type;
    std::string make;
    std::string model;
    int year;
    double kms;
    double pricePerKm;
    double pricePerDay;
    double insuranceCostPerPerson;
    int currentPassengers;
    std::chrono::time_point<std::chrono::system_clock> dateRentedOut;
    double pricePerTon;
    double currentTons;
    bool availableToRent;
};
