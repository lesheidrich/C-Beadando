#pragma once

#include "IssuingCountries.hpp"
#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::ostream;

/*
    IssuingCountries to be used by LicensePlate
    LicensePlate for use by Vehicles
*/
class LicensePlate
{
public:
    // constructor
    LicensePlate(string plateNumber_p, string issuingCountry_p);

    // properties
    string& PlateNumber()
    {
        return plateNumber_m;
    }
    string& IssuingCountry()
    {
        return issuingCountry_m;
    }

private:
    // attributes
    string plateNumber_m;
    string issuingCountry_m;

    // ensure param: issuingCountry_p is in list
    bool checkParamValidity(string& issuingCountry_p, const vector<string>& issuingCountryList);
};

// @Override LicensePlate->string
ostream& operator<<(ostream&, LicensePlate&);
