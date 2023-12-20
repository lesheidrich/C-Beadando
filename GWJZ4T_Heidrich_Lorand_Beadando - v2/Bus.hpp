#pragma once

#include "IssuingCountries.hpp"
#include "LicensePlate.hpp"
#include "Vehicle.hpp"
#include "PassengerVehicle.hpp"

class Bus: public PassengerVehicle
{
public:
    // constructor
    Bus(LicensePlate busLicensePlate_p, string busMake_p, string busModel_p, int busYear_p,
            double pricePerKm_p, double pricePerDay_p, double insuranceCostPerPerson_p,double busKm_p):
        PassengerVehicle(busLicensePlate_p, busMake_p, busModel_p, busYear_p, pricePerDay_p, pricePerKm_p, busKm_p),
        insuranceCostPerPerson_m(insuranceCostPerPerson_p),
        currentPassengers_m(0)
        {}

    // property
    int& CurrentPassengers()
    {
        return currentPassengers_m;
    }
    // getter
    double getInsuranceCostPerPerson()
    {
        return insuranceCostPerPerson_m;
    }

    // abstraction overrides
    double calculateCost() override;
    void printQuote() override;
    void printInvoice() override;

private:
    // attributes
    double insuranceCostPerPerson_m;
    int currentPassengers_m;
};
