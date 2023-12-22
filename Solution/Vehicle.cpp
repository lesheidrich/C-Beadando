#include "Vehicle.hpp"

using namespace std;
using TimeStamp = std::chrono::system_clock::time_point;
using namespace chrono;

// -> number of days rented (including days started)
int Vehicle::getDaysOut()
{
    // null check (0000-01-01 00:00:00.000000)
    if (Vehicle::DateRentedOut() == TimeStamp::min())
    {
        throw logic_error("getDaysOut Error! Vehicle not rented out yet!");
    }

    auto timeDelta = system_clock::now() - Vehicle::DateRentedOut();
    // time diff converted to days + 1
    return duration_cast<std::chrono::duration<int, ratio<86400>>>(timeDelta).count() + 1;
}

// partial print of vehicle data for other print functions
void Vehicle::printVehicleInfo()
{
    cout << "  License Plate:\t" << VehicleLicensePlate() << endl;
    cout << "  Issuing Country:\t" << getIssuingCountry() << endl;
    cout << "  Make: \t\t" << getVehicleMake() << endl;
    cout << "  Model: \t\t" << getVehicleModel() << endl;
    cout << "  Year: \t\t" << getVehicleYear() << endl;
}


