#include "MenuController.hpp"

using namespace std;
using namespace chrono;

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

void MenuController::searchByLicensePlate()
{
    int subMenuSelection;
    string licensePlate, issuingCountry, input;

    printUnderlinedTitle("SEARCH BY LICENSE PLATE:");
    cout << "Enter license plate to search for: ";
    cin >> licensePlate;
    cout << "Enter issuing country: ";
    cin >> issuingCountry;

    if (xmlHandler.licensePlateExists(licensePlate, issuingCountry))
    {
        cout << endl;
        xmlHandler.readBy(5, licensePlate);

        cout << "Vehicle options:" << endl << "  1. Print Quote" << endl << "  2. Print Invoice" << endl << "  3. Rent Out" <<
            endl <<"  4. Return Vehicle" << endl << "  5. Delete Vehicle" << endl << "  0. <-" << endl << endl;

        subMenuSelection = readInput<int>();

        switch(subMenuSelection)
        {
        case 1:
            xmlHandler.printQuote(licensePlate);
            break;
        case 2:
            xmlHandler.printInvoice(licensePlate);
            cout << "Proceed to return vehicle? (y/n): ";
            cin >> input;
            if (input == "y")
            {
               xmlHandler.changeRentalStatus(licensePlate, 1);
            }
            break;
        case 3:
            xmlHandler.changeRentalStatus(licensePlate, 0);
            break;
        case 4:
            xmlHandler.changeRentalStatus(licensePlate, 1);
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
        cout << "Enter daily rental price to exceed:" << endl;
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

void MenuController::newVehicle(string v)
{
    string title, make, model;
    int year;
    double pricePerKm, pricePerDay, insuranceCostPerPerson, pricePerTon, km;

    printUnderlinedTitle("Add New " + v + ":");
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

        if (cin.fail()) {
            throw invalid_argument("Invalid input for numeric value!");
        }

        LicensePlate licensePlate = newLicensePlate();
        if (v == "Car") {
            Car* c = new Car(licensePlate, make, model, year, pricePerKm, pricePerDay, km);
            xmlHandler.addVehicle(c);
            delete c;
        } else if (v == "Bus") {
            Bus* b = new Bus(licensePlate, make, model, year, pricePerKm, pricePerDay, insuranceCostPerPerson, km);
            xmlHandler.addVehicle(b);
            delete b;
        } else if (v == "Truck") {
            Truck* t = new Truck(licensePlate, make, model, year, pricePerKm, pricePerDay, km, pricePerTon);
            xmlHandler.addVehicle(t);
            delete t;
        } else if (v == "Machinery") {
            Machinery* m = new Machinery(licensePlate, make, model, year, pricePerDay, pricePerTon);
            xmlHandler.addVehicle(m);
            delete m;
        } else {
            throw invalid_argument("Vehicle type " + v + " doesn't exist!");
        }

    }
    catch (invalid_argument& e)
    {
        cerr << endl << "ERROR!" << endl << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
}

LicensePlate MenuController::newLicensePlate()
{
    string lpNumber, lpCountry;

    while(true)
    {
        cout << "License plate number: ";
        cin >> lpNumber;
        cout << "Issuing country: ";
        cin >> lpCountry;

        if (!xmlHandler.licensePlateExists(lpNumber, lpCountry))
        {
            break;
        }
        cout << "License plate: " << lpNumber << " already exists for issuing country " << lpCountry << endl;
    }

    return LicensePlate(lpNumber, lpCountry);
}

//// primary template definition
//template <typename T>
//T MenuController::readInput()
//{
//    T retInput;
//    string input;
//    cin >> input;
//    return input;
//}
//
//// explicit specialization for int (defined inside class)
//template <>
//int MenuController::readInput<int>()
//{
//    int retInput;
//    string input;
//
//    while (true)
//    {
//        cout << "Selection: ";
//        cin >> input;
//        try
//        {
//            retInput = stoi(input);
//            return retInput;
//        }
//        catch (invalid_argument&)
//        {
//            cout << "Please enter an integer value!" << endl;
//        }
//    }
//}

// Primary template definition
template <typename T, typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, double>::value, int>::type = 0>
T MenuController::readInput() {
    T retInput;
    std::string input;

    while (true) {
        std::cout << "Selection: ";
        std::cin >> input;

        // Use stringstream for conversion
        std::stringstream ss(input);
        if (!(ss >> retInput)) {
            // Conversion failed
            throw std::invalid_argument("Invalid input for numeric value!");
        }

        return retInput;
    }
}

void MenuController::printUnderlinedTitle(string title)
{
    int leadingSpaces = title.length() / 2 - 2;
    cout << endl << "\t" << title << endl << "\t" <<string(leadingSpaces, ' ') << "***" << endl;
}

