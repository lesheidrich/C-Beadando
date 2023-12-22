#include "IssuingCountries.hpp"

using std::string;

// static list of countries issuing licenses for the sake of the assignment
const vector<string>& IssuingCountries::getList()
{
    static const vector<string> countryList = {
        "Austria",
        "Belgium",
        "Bulgaria",
        "Croatia",
        "Cyprus",
        "Czech Republic",
        "Denmark",
        "Estonia",
        "Finland",
        "France",
        "Germany",
        "Greece",
        "Hungary",
        "Ireland",
        "Italy",
        "Latvia",
        "Lithuania",
        "Luxembourg",
        "Malta",
        "Netherlands",
        "Poland",
        "Portugal",
        "Romania",
        "Slovakia",
        "Slovenia",
        "Spain",
        "Sweden"
    };
    return countryList;
}

// -> printable string of countries
string IssuingCountries::toString() {
    const vector<string>& countryList = getList();

    string result = "\n\t";
    for (const string& country : countryList) {
        result += country + "\n\t";
    }

    return result;
}
