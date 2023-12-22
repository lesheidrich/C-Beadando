#include "Truck.hpp"

using namespace std;

// -> cost of rental upon returning Truck
double Truck::calculateCost()
{
    // (km returned - km rented)*price/km + (timepoint returned - timepoint rented + 1)*price/days + price/t*currentTons
    return kmDelta() * getPricePerKm() + getDaysOut() * getPricePerDay() + getPricePerTon() * CurrentTons();
}

// invoice to console
void Truck::printInvoice()
{
    Truck::printPartialInvoice("TRUCK");
    cout << "  Tons Moved Breakdown:" << endl;
    cout << "    Tons moved: \t" << fixed << setprecision(1) << CurrentTons() << " t" << endl;
    cout << "    Price/ton: \t\t$ " << fixed << setprecision(2) << getPricePerTon() << endl;
    cout << "  Tons Total: \t\t$ " << fixed << setprecision(2) << CurrentTons() * getPricePerTon() << endl;
    cout << "  GRAND TOTAL: \t\t$ " << fixed << setprecision(2) << calculateCost() << endl;
    cout << "+----------------------------------+\n" << endl;
}

// quote to console
void Truck::printQuote()
{
    Truck::printPartialQuote("TRUCK");
    cout << "  Price/ton: \t\t$ " << fixed << setprecision(2) << getPricePerTon() << endl;
    cout << "+----------------------------------+\n" << endl;
}
