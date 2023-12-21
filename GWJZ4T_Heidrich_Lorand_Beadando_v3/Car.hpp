#pragma once

#include "IssuingCountries.hpp"
#include "LicensePlate.hpp"
#include "Vehicle.hpp"
#include "PassengerVehicle.hpp"

class Car: public PassengerVehicle
{
public:
    // constructor
    Car(LicensePlate carLicensePlate_p, string carMake_p, string carModel_p, int carYear_p,
            double pricePerKm_p, double pricePerDay_p, double carKm_p):
        PassengerVehicle(carLicensePlate_p, carMake_p, carModel_p, carYear_p, pricePerKm_p, pricePerDay_p, carKm_p)
        {}

    // abstraction overrides
    double calculateCost() override;
    void printQuote() override;
    void printInvoice() override;
};
