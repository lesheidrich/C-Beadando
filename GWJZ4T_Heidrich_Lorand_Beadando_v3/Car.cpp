#include "Car.hpp"
#include <iomanip>

using namespace std;
using TimeStamp = std::chrono::system_clock::time_point;

// -> cost of rental upon returning Car
double Car::calculateCost()
{
    // (km returned - km rented)*price/km + (timepoint returned - timepoint rented + 1)*price/days
    return kmDelta() * getPricePerKm() + getDaysOut() * getPricePerDay();
}

// invoice to console
void Car::printInvoice()
{
    Car::printPartialInvoice("CAR");
    cout << "  GRAND TOTAL: \t\t$ " << fixed << setprecision(2) << calculateCost() << endl;
    cout << "+----------------------------------+\n" << endl;
}

// quote to console
void Car::printQuote()
{
    Car::printPartialQuote("CAR");
    cout << "+----------------------------------+\n" << endl;
}
