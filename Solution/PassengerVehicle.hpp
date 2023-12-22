#pragma once

#include "IssuingCountries.hpp"
#include "LicensePlate.hpp"
#include "Vehicle.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

class PassengerVehicle: public Vehicle
{
public:
    // constructor
    PassengerVehicle(LicensePlate pvLicensePlate_p, string pvMake_p, string pvModel_p, int pvYear_p, double pvPricePerDay_p,
                     double pvPricePerKm_p, double pvKm_p):
        Vehicle(pvLicensePlate_p, pvMake_p, pvModel_p, pvYear_p, pvPricePerDay_p),
        pricePerKm_m(pvPricePerKm_p),
        km_m(pvKm_p),
        kmReturned_m(0)
        {}
    virtual ~PassengerVehicle() {}

    // property
    double& Km()
    {
        return km_m;
    }
    double& KmReturned()
    {
        return kmReturned_m;
    }
    // getter
    double getPricePerKm()
    {
        return pricePerKm_m;
    }

    // virtual methods not overriden to keep class abstract

    // method descriptions in .cpp
    double kmDelta();
    void printPartialInvoice(string header);
    void printPartialQuote(string header);
private:
    // attributes
    double pricePerKm_m;
    double km_m;
    double kmReturned_m;
};

