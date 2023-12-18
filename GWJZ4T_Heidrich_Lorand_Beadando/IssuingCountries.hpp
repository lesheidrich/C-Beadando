#pragma once

#include <vector>
#include <string>

using std::string;
using std::vector;

/*
    IssuingCountries to be used by LicensePlate
    LicensePlate for use by Vehicles
*/
class IssuingCountries
{
public:
    static const vector<string>& getList();
    static string toString();
};
