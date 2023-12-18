#include "MenuController.hpp"

using namespace std;
using namespace chrono;

void MenuController::newCar()
{
    string make, model;
    int year;
    double pricePerKm, pricePerDay, km;

    cout << "NEW CAR:" << endl;
    cout << "Car make: ";
    cin >> make;
    cout << "Car model: ";
    cin >> model;
    cout << "Year manufactured: ";
    cin >> year;
    try
    {
        cout << "Rental price/km: $ ";
        cin >> pricePerKm;
        cout << "Rental price/day: $ ";
        cin >> pricePerDay;
        cout << "Current kms: ";
        cin >> km;

        if (cin.fail()) {
            throw invalid_argument("Invalid input for numeric value!");
        }

        LicensePlate licensePlate = newLicensePlate();
        Car* c = new Car(licensePlate, make, model, year, pricePerKm, pricePerDay, km);
        xmlHandler.addCar(c);
        delete c;
    }
    catch (invalid_argument& e)
    {
        cerr << endl << "ERROR!" << endl << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
}

void MenuController::newBus()
{
    string make, model;
    int year;
    double pricePerKm, pricePerDay, insuranceCostPerPerson, km;

    cout << "NEW BUS:" << endl;
    cout << "Car make: ";
    cin >> make;
    cout << "Car model: ";
    cin >> model;
    cout << "Year manufactured: ";
    cin >> year;
    try
    {
        cout << "Rental price/km: $ ";
        cin >> pricePerKm;
        cout << "Rental price/day: $ ";
        cin >> pricePerDay;
        cout << "Insurance cost/person: $ ";
        cin >> insuranceCostPerPerson;
        cout << "Current kms: ";
        cin >> km;

        if (cin.fail()) {
            throw invalid_argument("Invalid input for numeric value!");
        }

        LicensePlate licensePlate = newLicensePlate();
        Bus* b = new Bus(licensePlate, make, model, year, pricePerKm, pricePerDay, insuranceCostPerPerson, km);
        xmlHandler.addBus(b);
        delete b;
    }
    catch (invalid_argument& e)
    {
        cerr << endl << "ERROR!" << endl << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
}
void MenuController::newTruck()
{

}
void MenuController::newMachinery()
{

}

LicensePlate MenuController::newLicensePlate()
{
    string lpNumber, lpCountry;
    cout << "License plate number: ";
    cin >> lpNumber;
    cout << "Issuing country: ";
    cin >> lpCountry;

    return LicensePlate(lpNumber, lpCountry);
}

