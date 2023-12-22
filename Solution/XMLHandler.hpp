#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstdlib>
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

    void addVehicle(Vehicle* v);
    void readAll();
    void readBy(const int& condition, const string& filter);
    void changeRentalStatus(string& licensePlate_p, const int& command);
    void deleteByLicensePlate(string& licensePlate_p);
    void printQuote(string& licensePlate_p);
    void printInvoice(string& licensePlate_p);
    void saveToFile();
    void loadFromFile();
    bool licensePlateExists(string& licensePlate, string& issuingCountry);
private:
    // attributes
    pugi::xml_document vehiclesXML;
    pugi::xml_node fleet;
    pugi::xml_parse_result result;
    // methods
    Car readCar(pugi::xml_node vehicleNode);
    Bus readBus(pugi::xml_node vehicleNode);
    Truck readTruck(pugi::xml_node vehicleNode);
    Machinery readMachinery(pugi::xml_node vehicleNode);
    double inputReturnedKm(const pugi::xml_node& vehicleNode);
    pugi::xml_node loadAndCheck();
};
