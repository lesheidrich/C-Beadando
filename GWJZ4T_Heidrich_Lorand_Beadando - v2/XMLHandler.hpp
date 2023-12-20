#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

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
    Car readCar(pugi::xml_node vehicleNode);
    Bus readBus(pugi::xml_node vehicleNode);
    Truck readTruck(pugi::xml_node vehicleNode);
    Machinery readMachinery(pugi::xml_node vehicleNode);
    bool licensePlateExists(string& licensePlate, string& issuingCountry);
    void changeRentalStatus(string& licensePlate_p, const int& command);
    void deleteByLicensePlate(string& licensePlate_p);
    void printQuote(string& licensePlate_p);
    void printInvoice(string& licensePlate_p);
    double inputReturnedKm(const pugi::xml_node& vehicleNode);
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
