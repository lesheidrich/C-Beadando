#include "Machinery.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// -> cost of rental upon returning Machinery
double Machinery::calculateCost()
{
    // (timepoint returned - timepoint rented + 1)*price/days + price/ton*tons transported
    return getDaysOut() * getPricePerDay() + getPricePerTon() * CurrentTons();
}

// quote to console
void Machinery::printQuote()
{
    cout << "+----------------------------------+" << endl;
    cout << "  MACHINERY QUOTE:" << endl;
    cout << "      ***" << endl;
    printVehicleInfo();
    cout << "  Price/day: \t\t$ " << fixed << setprecision(2) << getPricePerDay() << endl;
    cout << "  Price/ton: \t\t$ " << fixed << setprecision(2) << getPricePerTon() << endl;
    cout << "+----------------------------------+\n" << endl;
}

// invoice to console
void Machinery::printInvoice()
{
    cout << "+----------------------------------+" << endl;
    cout << "  MACHINERY INVOICE" << endl;
    cout << "      ***" << endl;
    printVehicleInfo();
    cout << "  Rental Days Breakdown:" << endl;
    cout << "    Rental duration: \t" << getDaysOut() << " day(s)" << endl;
    cout << "    Price/day: \t\t$ " << fixed << setprecision(2) << getPricePerDay() << endl;
    cout << "  Daily Total: \t\t$ " << fixed << setprecision(2) << getDaysOut() * getPricePerDay() << endl;
    cout << "  Tons Moved Breakdown:" << endl;
    cout << "    Tons moved: \t" << fixed << setprecision(1) << CurrentTons() << " t" << endl;
    cout << "    Price/ton: \t\t$ " << fixed << setprecision(2) << getPricePerTon() << endl;
    cout << "  Tons Total: \t\t$ " << fixed << setprecision(2) << CurrentTons() * getPricePerTon() << endl;
    cout << "  GRAND TOTAL: \t\t$ " << fixed << setprecision(2) << calculateCost() << endl;
    cout << "+----------------------------------+\n" << endl;
}
