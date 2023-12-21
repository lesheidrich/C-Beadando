#include "Bus.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// -> cost of rental upon returning Bus
double Bus::calculateCost()
{
    // (km returned - km rented)*price/km + (timepoint returned - timepoint rented + 1)*price/days + insurance/person*passengers
    return kmDelta() * getPricePerKm() + getDaysOut() * getPricePerDay() + getInsuranceCostPerPerson() * CurrentPassengers();
}

// invoice to console
void Bus::printInvoice()
{
    Bus::printPartialInvoice("BUS");
    cout << "  Passenger Insurance Breakdown:" << endl;
    cout << "    Total passengers: \t" << CurrentPassengers() << endl;
    cout << "    Insurance/passenger:$ " << fixed << setprecision(2) << getInsuranceCostPerPerson() << endl;
    cout << "  Passenger Total: \t$ " << fixed << setprecision(2) << CurrentPassengers() * getInsuranceCostPerPerson() << endl;
    cout << "  GRAND TOTAL: \t\t$ " << fixed << setprecision(2) << calculateCost() << endl;
    cout << "+----------------------------------+\n" << endl;
}

// quote to console
void Bus::printQuote()
{
    Bus::printPartialQuote("BUS");
    cout << "  Insurance/passenger:\t$ " << fixed << setprecision(2) << getInsuranceCostPerPerson() << endl;
    cout << "+----------------------------------+\n" << endl;
}
