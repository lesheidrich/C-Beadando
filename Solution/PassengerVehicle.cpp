#include "PassengerVehicle.hpp"

using namespace std;

// -> delta: km returned with - km rented
double PassengerVehicle::kmDelta()
{
    double returnedKmInput = KmReturned();
    // vehicle returned km always set to 0 when returned
    if (returnedKmInput == 0)
    {
        throw logic_error("Km returned with not set!");
    }

    return returnedKmInput - Km();
}

// prints partial invoice
void PassengerVehicle::printPartialInvoice(string header)
{
    cout << "+----------------------------------+" << endl;
    cout << "  " << header << " INVOICE" << endl;
    cout << "      ***" << endl;
    printVehicleInfo();
    cout << "  Km Breakdown:" << endl;
    cout << "    Distance driven: \t" << fixed << setprecision(1) <<kmDelta() << " km" << endl;
    cout << "    Price/km: \t\t$ " << fixed << setprecision(2) << getPricePerKm() << endl;
    cout << "  Km Total: \t\t$ " << fixed << setprecision(2) << kmDelta() * getPricePerKm() << endl;
    cout << "  Rental Days Breakdown:" << endl;
    cout << "    Rental duration: \t" << getDaysOut() << " day(s)" << endl;
    cout << "    Price/day: \t\t$ " << fixed << setprecision(2) << getPricePerDay() << endl;
    cout << "  Daily Total: \t\t$ " << fixed << setprecision(2) << getDaysOut() * getPricePerDay() << endl;
}

// prints partial quote
void PassengerVehicle::printPartialQuote(string header)
{
    cout << "+----------------------------------+" << endl;
    cout << "  " << header << " QUOTE:" << endl;
    cout << "      ***" << endl;
    printVehicleInfo();
    cout << "  Price/km: \t\t$ " << fixed << setprecision(2) << getPricePerKm() << endl;
    cout << "  Price/day: \t\t$ " << fixed << setprecision(2) << getPricePerDay() << endl;
}
