#include "MenuController.hpp"

using namespace std;
using namespace chrono;

// initializes file menu with main menu
void MenuController::run()
{
    cout << "Heidrich Vehicle Rentals V1.0" << endl << endl;

    bool mainMenuRunning = true;
    int menuSelection;

    while(mainMenuRunning)
    {
        printUnderlinedTitle("MAIN MENU:");
        cout << endl << "  1. Add Vehicle" << endl << "  2. List Vehicles" << endl << "  3. Search by License Plate" <<
            endl << "  4. File Management" << endl << "  0. Exit" << endl << endl;

        menuSelection = readInput<int>();

        switch(menuSelection)
        {
        case 1:
            newVehicleMenuSelection();
            break;
        case 2:
            listVehicles();
            break;
        case 3:
            searchByLicensePlate();
            break;
        case 4:
            fileManagement();
            break;
        case 0:
            mainMenuRunning = false;
            break;
        default:
            cout << menuSelection << " is not a valid option!" << endl;
            break;
        }

    }
    cout << "Thank you for choosing Heidrich Vehicle Rentals." << endl;
}

// vehicle creation sub-menu
void MenuController::newVehicleMenuSelection()
{
    int subMenuSelection;

    printUnderlinedTitle("ADD VEHICLE:");
    cout << "Please indicate vehicle type:" << endl << "  1. Car" << endl << "  2. Bus" << endl << "  3. Truck" <<
        endl <<"  4. Machinery" << endl << "  0. <-" << endl << endl;

    subMenuSelection = readInput<int>();

    switch(subMenuSelection)
    {
    case 1:
        newVehicle("Car");
        break;
    case 2:
        newVehicle("Bus");
        break;
    case 3:
        newVehicle("Truck");
        break;
    case 4:
        newVehicle("Machinery");
        break;
    case 0:
        break;
    default:
        cout << subMenuSelection << " is not a valid option!" << endl;
        newVehicleMenuSelection();
        break;
    }
}

// new vehicle creation based on inputs
void MenuController::newVehicle(string v)
{
    string title, make, model;
    int year;
    double pricePerKm, pricePerDay, insuranceCostPerPerson, pricePerTon, km;

    printUnderlinedTitle("Add New " + v + ":");
    // user input vehicle data
    cout << v << " make: ";
    cin >> make;
    cout << v << " model: ";
    cin >> model;
    cout << "Year manufactured: ";
    cin >> year;
    try
    {
        if (v != "Machinery")
        {
            cout << "Current kms: ";
            cin >> km;
            cout << "Rental price/km: $ ";
            cin >> pricePerKm;
        }
        cout << "Rental price/day: $ ";
        cin >> pricePerDay;
        if  (v == "Bus")
        {
            cout << "Insurance cost/person: $ ";
            cin >> insuranceCostPerPerson;
        }
        if (v == "Truck" || v == "Machinery")
        {
            cout << "Price/ton: $ ";
            cin >> pricePerTon;
        }

        /*
            tried different approach for input type-error
            readInput<type>() works nicely, just wanted to try another way too
        */
        if (cin.fail()) {
            throw invalid_argument("Invalid input for numeric value!");
        }

        // instanciate in heap (license plate utilizes stack)
        LicensePlate licensePlate = newLicensePlate();
        if (v == "Car")
        {
            Car* c = new Car(licensePlate, make, model, year, pricePerKm, pricePerDay, km);
            xmlHandler.addVehicle(c);
            delete c;
        }
        else if (v == "Bus")
        {
            Bus* b = new Bus(licensePlate, make, model, year, pricePerKm, pricePerDay, insuranceCostPerPerson, km);
            xmlHandler.addVehicle(b);
            delete b;
        }
        else if (v == "Truck")
        {
            Truck* t = new Truck(licensePlate, make, model, year, pricePerKm, pricePerDay, km, pricePerTon);
            xmlHandler.addVehicle(t);
            delete t;
        }
        else if (v == "Machinery")
        {
            Machinery* m = new Machinery(licensePlate, make, model, year, pricePerDay, pricePerTon);
            xmlHandler.addVehicle(m);
            delete m;
        }
        else
        {
            throw invalid_argument("Vehicle type " + v + " doesn't exist!");
        }

    }
    catch (invalid_argument& e)
    {
        cerr << endl << "ERROR!" << endl << e.what() << endl;
        cin.clear();
        // handle cin.fail here so doesn't proceed with further inputs
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
}

// instanciates license plate on stack
LicensePlate MenuController::newLicensePlate()
{
    string lpNumber, lpCountry;

    while(true)
    {
        cout << "License plate number: ";
        cin >> lpNumber;
        cout << "Issuing country: ";
        cin >> lpCountry;

        // ensure license plate unique to issuing country
        if (!xmlHandler.licensePlateExists(lpNumber, lpCountry))
        {
            break;
        }
        cout << "License plate: " << lpNumber << " already exists for issuing country " << lpCountry << endl;
    }

    return LicensePlate(lpNumber, lpCountry);
}

// saving and loading xml sub-menu
void MenuController::fileManagement()
{
    int subMenuSelection;

    printUnderlinedTitle("FILE MANAGEMENT:");
    cout << "  1. Save" << endl << "  2. Load" << endl << "  0. <-" << endl << endl;

    subMenuSelection = readInput<int>();

    switch(subMenuSelection)
    {
    case 1:
        xmlHandler.saveToFile();
        break;
    case 2:
        xmlHandler.loadFromFile();
        break;
    case 0:
        break;
    default:
        cout << subMenuSelection << " is not a valid option!" << endl;
        fileManagement();
        break;
    }
}

// single vehicle operations utilizing license plate search
void MenuController::searchByLicensePlate()
{
    int subMenuSelection;
    string licensePlate, issuingCountry, input;

    printUnderlinedTitle("SEARCH BY LICENSE PLATE:");
    cout << "Enter license plate to search for: ";
    cin >> licensePlate;
    cout << "Enter issuing country: ";
    cin >> issuingCountry;

    // ensure vehicle exists by license plate
    if (xmlHandler.licensePlateExists(licensePlate, issuingCountry))
    {
        cout << endl;
        xmlHandler.readBy(5, licensePlate); // reads and prints single vehicle by license plate

        cout << "Vehicle options:" << endl << "  1. Print Quote" << endl << "  2. Print Invoice" << endl << "  3. Rent Out" <<
            endl <<"  4. Return Vehicle" << endl << "  5. Delete Vehicle" << endl << "  0. <-" << endl << endl;

        subMenuSelection = readInput<int>();

        switch(subMenuSelection)
        {
        case 1:
            xmlHandler.printQuote(licensePlate);
            break;
        case 2:
            xmlHandler.printInvoice(licensePlate);             // option to return vehicle after printing invoice
            cout << "Proceed to return vehicle? (y/n): ";
            cin >> input;
            if (input == "y")
            {
               xmlHandler.changeRentalStatus(licensePlate, 1); // return
            }
            break;
        case 3:
            xmlHandler.changeRentalStatus(licensePlate, 0);    // rent out
            break;
        case 4:
            xmlHandler.changeRentalStatus(licensePlate, 1);    // return
            break;
        case 5:
            xmlHandler.deleteByLicensePlate(licensePlate);
            break;
        case 0:
            break;
        default:
            cout << subMenuSelection << " is not a valid option!" << endl;
            searchByLicensePlate();
            break;
        }
    }
    else
    {
        cout << "Vehicle with license plate: " << licensePlate << " from issuing country " << issuingCountry << " doesn't exist!" << endl;
    }
}

// print all vehicles to console - filter=user option
void MenuController::listVehicles()
{
    int subMenuSelection;

    printUnderlinedTitle("LIST VEHICLES:");
    cout << "Set list filter:" << endl << "  1. All (quotes)" << endl << "  2. Available" << endl << "  3. Leased Out" <<
        endl <<"  4. Cars" << endl <<"  5. Buses" << endl <<"  6. Trucks" << endl <<"  7. Machinery" << endl
        << "  8. Price-Greater" << endl << "  9. Price-Smaller" << endl << "  0. <-" << endl << endl;

    subMenuSelection = readInput<int>();

    switch(subMenuSelection)
    {
    case 1:
        printUnderlinedTitle("ALL VEHICLE QUOTES:");
        xmlHandler.readAll();
        break;
    case 2:
        printUnderlinedTitle("AVAILABLE VEHICLES:");
        xmlHandler.readBy(1, "true");
        break;
    case 3:
        printUnderlinedTitle("LEASED OUT VEHICLES:");
        xmlHandler.readBy(1, "false");
        break;
    case 4:
        printUnderlinedTitle("CARS:");
        xmlHandler.readBy(2, "Car");
        break;
    case 5:
        printUnderlinedTitle("BUSES:");
        xmlHandler.readBy(2, "Bus");
        break;
    case 6:
        printUnderlinedTitle("TRUCKS:");
        xmlHandler.readBy(2, "Truck");
        break;
    case 7:
        printUnderlinedTitle("MACHINERY:");
        xmlHandler.readBy(2, "Machinery");
        break;
    case 8:
        printUnderlinedTitle("GREATER-THAN:");
        cout << "Enter daily rental price to exceed:" << endl;   // by price/day as everything else requires further input which customer may not know
        xmlHandler.readBy(3, to_string(readInput<double>()));
        break;
    case 9:
        printUnderlinedTitle("LESS-THAN:");
        cout << "Enter daily rental price ceiling:" << endl;
        xmlHandler.readBy(4, to_string(readInput<double>()));
        break;
    case 0:
        break;
    default:
        cout << subMenuSelection << " is not a valid option!" << endl;
        listVehicles();
        break;
    }
}

// underlines and outputs title
void MenuController::printUnderlinedTitle(string title)
{
    int leadingSpaces = title.length() / 2 - 2;
    cout << endl << "\t" << title << endl << "\t" <<string(leadingSpaces, ' ') << "***" << endl;
}

// template for reading numeric values
template <typename T, typename enable_if<is_same<T, int>::value || is_same<T, double>::value, int>::type = 0>
T MenuController::readInput() {
    T result;
    string input;

    while (true) {
        cout << "Selection: ";
        cin >> input;

        // stringstream conversion failure throws error
        stringstream ss(input);
        if (!(ss >> result)) {
            throw invalid_argument("Invalid input for numeric value!");
        }

        return result;
    }
}

