#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include "LicensePlate.hpp"

/*
    IssuingCountries to be used by LicensePlate
    LicensePlate for use by Vehicles
    Vehicle base class for derived vehicle classes
*/
class Vehicle
{
public:
    // constructor and virtual destructor for abstract class
    Vehicle(LicensePlate& vehicleLicensePlate_p, string vehicleMake_p, string vehicleModel_p, int vehicleYear_p, double vehiclePricePerDay_p):
        vehicleLicensePlate_m(vehicleLicensePlate_p),
        vehicleMake_m(vehicleMake_p),
        vehicleModel_m(vehicleModel_p),
        vehicleYear_m(vehicleYear_p),
        pricePerDay_m(vehiclePricePerDay_p),
        dateRentedOut_m(std::chrono::system_clock::time_point::min()) // initialized null: 0000-01-01 00:00:00.000000
        {}

    virtual ~Vehicle() {}

    // property
    string& VehicleLicensePlate()
    {
        return vehicleLicensePlate_m.PlateNumber();
    }
    std::chrono::time_point<std::chrono::system_clock>& DateRentedOut() //time_point
    {
        return dateRentedOut_m;
    }

    // getters
    string getVehicleMake()
    {
        return vehicleMake_m;
    }
    string getVehicleModel()
    {
        return vehicleModel_m;
    }
    int getVehicleYear()
    {
        return vehicleYear_m;
    }
    double getPricePerDay()
    {
        return pricePerDay_m;
    }
    string getIssuingCountry()
    {
        return vehicleLicensePlate_m.IssuingCountry();
    }

    // virtual method
    virtual double calculateCost() = 0;
    virtual void printQuote() = 0;
    virtual void printInvoice() = 0;
    // function descriptions in .cpp
    int getDaysOut();
    void printVehicleInfo();
private:
    // attributes
    LicensePlate vehicleLicensePlate_m;
    string vehicleMake_m;
    string vehicleModel_m;
    int vehicleYear_m;
    double pricePerDay_m;
    std::chrono::time_point<std::chrono::system_clock> dateRentedOut_m;  //time_point
};
