#pragma once

#include "IssuingCountries.hpp"
#include "LicensePlate.hpp"
#include "Vehicle.hpp"
#include "PassengerVehicle.hpp"

class Truck: public PassengerVehicle
{
public:
    // constructor
    Truck(LicensePlate truckLicensePlate_p, string truckMake_p, string truckModel_p, int truckYear_p,
            double pricePerKm_p, double pricePerDay_p, double truckKm_p, double pricePerTon_p):
        PassengerVehicle(truckLicensePlate_p, truckMake_p, truckModel_p, truckYear_p, pricePerKm_p, pricePerDay_p, truckKm_p),
        pricePerTon_m(pricePerTon_p),
        currentTons_m(0)
        {}

    // property
    double& CurrentTons()
    {
        return currentTons_m;
    }
    // getter
    double getPricePerTon()
    {
        return pricePerTon_m;
    }

    // abstraction overrides
    double calculateCost() override;
    void printQuote() override;
    void printInvoice() override;
private:
    double pricePerTon_m;
    double currentTons_m;
};
