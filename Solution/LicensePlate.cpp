#include "LicensePlate.hpp"

using namespace std;

// constructor
LicensePlate::LicensePlate(string plateNumber_p, string issuingCountry_p)
{
    IssuingCountries issuingCountries;
    // ensure country in list
    if (checkParamValidity(issuingCountry_p, issuingCountries.getList()))
    {
        issuingCountry_m = issuingCountry_p;
        plateNumber_m = plateNumber_p;
    }
    else
    {
        throw invalid_argument("Invalid Issuing Country: '" + issuingCountry_p +
                            "'\nSelection is limited to current list of Issuing Countries:" +
                            issuingCountries.toString());
    }
}

// true if issuingCountry_p in issuingCountryList
bool LicensePlate::checkParamValidity(string& issuingCountry_p, const vector<string>& issuingCountryList)
{
    return find(issuingCountryList.begin(), issuingCountryList.end(), issuingCountry_p) != issuingCountryList.end();
}

// @Override LicensePlate->string
ostream& operator<< (ostream &str, LicensePlate &lp)
{
    str << lp.PlateNumber() << endl << "  Issuing Country:\t" << lp.IssuingCountry();
    return str;
}
