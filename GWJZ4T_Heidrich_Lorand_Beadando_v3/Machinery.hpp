#pragma once

#include "IssuingCountries.hpp"
#include "LicensePlate.hpp"
#include "Vehicle.hpp"

class Machinery : public Vehicle
{
public:
    // constructor
    Machinery(LicensePlate machineryLicensePlate_p, string machineryMake_p, string machineryModel_p, int machineryYear_p,
              double machineryPricePerDay_p, double machineryPricePerTon_p):
        Vehicle(machineryLicensePlate_p, machineryMake_p, machineryModel_p, machineryYear_p, machineryPricePerDay_p),
        pricePerTon_m(machineryPricePerTon_p),
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

    // virtual overrides
    double calculateCost() override;
    void printQuote() override;
    void printInvoice() override;

private:
    // attributes
    double pricePerTon_m;
    double currentTons_m;
};
