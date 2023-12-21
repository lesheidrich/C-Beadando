#include "XMLHandler.hpp"

using namespace std;
using namespace chrono;

// constructor initializes xml with columns
XMLHandler::XMLHandler()
{
    result = vehiclesXML.load_file("vehiclesXML.xml");

    if (!result)
    {
        // If the file does not exist, create a new one with the fleet node
        fleetNode = vehiclesXML.append_child("fleet");
        vehiclesXML.save_file("vehiclesXML.xml");
    }
    else
    {
        // If the file exists, get the existing fleet node
        fleetNode = vehiclesXML.child("fleet");
    }
}

void XMLHandler::addVehicle(Vehicle* v)
{
    pugi::xml_node vehicleNode = fleetNode.append_child("vehicle");
    // add vehicle info
    string licensePlate = v->VehicleLicensePlate();
    for (char &c : licensePlate) {
        c = toupper(c);
    }
    vehicleNode.append_child("LicensePlateNumber").text().set(licensePlate.c_str());
    vehicleNode.append_child("LicensePlateIssuingCountry").text().set(v->getIssuingCountry().c_str());
    vehicleNode.append_child("Make").text().set(v->getVehicleMake().c_str());
    vehicleNode.append_child("Model").text().set(v->getVehicleModel().c_str());
    vehicleNode.append_child("Year").text().set(v->getVehicleYear());
    vehicleNode.append_child("DateRentedOut").text().set("0");
    vehicleNode.append_child("PricePerDay").text().set(v->getPricePerDay());

    if (Car* c = dynamic_cast<Car*>(v))
    {
        vehicleNode.append_child("Kms").text().set(c->Km());
        vehicleNode.append_child("PricePerKm").text().set(c->getPricePerKm());
        vehicleNode.append_child("Type").text().set("Car");
//        vehicleNode.append_child("KmReturned").text().set("0");
    }
    else if (Bus* b = dynamic_cast<Bus*>(v))
    {
        vehicleNode.append_child("Kms").text().set(b->Km());
        vehicleNode.append_child("PricePerKm").text().set(b->getPricePerKm());
        vehicleNode.append_child("InsuranceCostPerPerson").text().set(b->getInsuranceCostPerPerson());
        vehicleNode.append_child("CurrentPassengers").text().set(b->CurrentPassengers());
        vehicleNode.append_child("Type").text().set("Bus");
//        vehicleNode.append_child("KmReturned").text().set("0");
    }
    else if (Truck* t = dynamic_cast<Truck*>(v))
    {
        vehicleNode.append_child("Kms").text().set(t->Km());
        vehicleNode.append_child("PricePerKm").text().set(t->getPricePerKm());
        vehicleNode.append_child("PricePerTon").text().set(t->getPricePerTon());
        vehicleNode.append_child("CurrentTons").text().set(t->CurrentTons());
        vehicleNode.append_child("Type").text().set("Truck");
//        vehicleNode.append_child("KmReturned").text().set("0");
    }
    else if (Machinery* m = dynamic_cast<Machinery*>(v))
    {
        vehicleNode.append_child("PricePerTon").text().set(m->getPricePerTon());
        vehicleNode.append_child("CurrentTons").text().set(m->CurrentTons());
        vehicleNode.append_child("Type").text().set("Machinery");
    }

    vehicleNode.append_child("AvailableToRent").text().set("true");

    vehiclesXML.save_file("vehiclesXML.xml");
}

void XMLHandler::readAll()
{
    result = vehiclesXML.load_file("vehiclesXML.xml");
    if (!result) {
        cout << "Error loading XML file!" << endl;
        return;
    }

    pugi::xml_node fleet = vehiclesXML.child("fleet");

    for (pugi::xml_node vehicleNode = fleet.first_child() ; vehicleNode; vehicleNode = vehicleNode.next_sibling())
    {
        string type = vehicleNode.child_value("Type");
        if (type == "Car")
        {
            Car c = readCar(vehicleNode);
            c.printQuote();
        }
        else if (type == "Bus")
        {
            Bus b = readBus(vehicleNode);
            b.printQuote();
        }
        else if (type == "Truck")
        {
            Truck t = readTruck(vehicleNode);
            t.printQuote();
        }
        else if (type == "Machinery")
        {
            Machinery m = readMachinery(vehicleNode);
            m.printQuote();
        }
    }
}

void XMLHandler::printQuote(string& licensePlate_p)
{
    string licensePlate, type;
    result = vehiclesXML.load_file("vehiclesXML.xml");

    if (!result) {
        cout << "Error loading XML file!" << endl;
        return;
    }

    pugi::xml_node fleet = vehiclesXML.child("fleet");

    for (pugi::xml_node vehicleNode = fleet.first_child() ; vehicleNode; vehicleNode = vehicleNode.next_sibling())
    {
        licensePlate = vehicleNode.child_value("LicensePlateNumber");
        type = vehicleNode.child_value("Type");

        if (licensePlate == licensePlate_p)
        {
            if (type == "Car")
            {
                Car v = readCar(vehicleNode);
                v.printQuote();
            }
            else if (type == "Bus")
            {
                Bus v = readBus(vehicleNode);
                v.printQuote();

            }
            else if (type == "Truck")
            {
                Truck v = readTruck(vehicleNode);
                v.printQuote();
            }
            else if (type == "Machinery")
            {
                Machinery v = readMachinery(vehicleNode);
                v.printQuote();
            }
        }
    }
}

void XMLHandler::printInvoice(string& licensePlate_p)
{
    string licensePlate, type;
    result = vehiclesXML.load_file("vehiclesXML.xml");

    if (!result) {
        cout << "Error loading XML file!" << endl;
        return;
    }

    pugi::xml_node fleet = vehiclesXML.child("fleet");

    for (pugi::xml_node vehicleNode = fleet.first_child() ; vehicleNode; vehicleNode = vehicleNode.next_sibling())
    {
        licensePlate = vehicleNode.child_value("LicensePlateNumber");
        type = vehicleNode.child_value("Type");

        if (licensePlate == licensePlate_p)
        {
            if (type == "Car")
            {
                Car v = readCar(vehicleNode);
                v.KmReturned() = inputReturnedKm(vehicleNode);
                v.printInvoice();
            }
            else if (type == "Bus")
            {
                Bus v = readBus(vehicleNode);
                v.KmReturned() = inputReturnedKm(vehicleNode);
                v.printInvoice();
            }
            else if (type == "Truck")
            {
                Truck v = readTruck(vehicleNode);
                v.KmReturned() = inputReturnedKm(vehicleNode);
                v.printInvoice();
            }
            else if (type == "Machinery")
            {
                Machinery v = readMachinery(vehicleNode);
                v.printInvoice();
            }
        }
    }
}

double XMLHandler::inputReturnedKm(const pugi::xml_node& vehicleNode)
{
    string input;
    double kmReturned;
    double originalKms = stod(vehicleNode.child_value("Kms"));

    while (true)
    {
        cout << "Enter returned km: ";
        cin >> input;

        stringstream ss(input);
        if (ss >> kmReturned && kmReturned > originalKms)
        {
            return kmReturned;
        }
        cout << "Must enter a numeric value greater than " << originalKms << endl;
    }
}

void XMLHandler::readBy(const int& condition, const string& filter)
{
    result = vehiclesXML.load_file("vehiclesXML.xml");
    if (!result) {
        cout << "Error loading XML file!" << endl;
        return;
    }

    pugi::xml_node fleet = vehiclesXML.child("fleet");
//    string filter;
    for (pugi::xml_node vehicleNode = fleet.first_child() ; vehicleNode; vehicleNode = vehicleNode.next_sibling())
    {
        string response;
        double responseD = 0;  // i
        double filterD = 0;
        switch(condition)
        {
        case 1: // availability
            response = vehicleNode.child_value("AvailableToRent");
            break;
        case 2: // by vehicle type
            response = vehicleNode.child_value("Type");
            break;
        case 3: // greater than
            response = vehicleNode.child_value("PricePerDay");
            responseD = stod(response);  // i
            filterD = stod(filter);  // >

            if (responseD > filterD)  // i > 43
            {
                response = filter;
            }
            break;
        case 4: // less than
            response = vehicleNode.child_value("PricePerDay");
            responseD = stod(response);  // i
            filterD = stod(filter);  // >

            if (responseD < filterD) // i < 1
            {
                response = filter;
            }
            break;
        case 5:  // by licenseplate
            response = vehicleNode.child_value("LicensePlateNumber");
            break;
        default:
            cout << "readBy() error!" << endl;
            break;
        }
        if (filter == response)
        {
            cout << "License Plate: \t\t" << vehicleNode.child_value("LicensePlateNumber") << endl;
            cout << "Issuing Country: \t" << vehicleNode.child_value("LicensePlateIssuingCountry") << endl;
            cout << "Type: \t\t\t" << vehicleNode.child_value("Type") << endl;
            cout << "Make: \t\t\t" << vehicleNode.child_value("Make") << endl;
            cout << "Model: \t\t\t" << vehicleNode.child_value("Model") << endl;
            cout << "Year: \t\t\t" << vehicleNode.child_value("Year") << endl;
            cout << "Kms: \t\t\t" << vehicleNode.child_value("Kms") << endl;
            // may need to add KmReturned
            cout << "Price/Km: \t\t$ " << vehicleNode.child_value("PricePerKm") << endl;
            cout << "Price/Day: \t\t$ " << vehicleNode.child_value("PricePerDay") << endl;
            cout << "Insurance Cost/Person: \t$ " << vehicleNode.child_value("InsuranceCostPerPerson") << endl;
            cout << "Current Passengers: \t" << vehicleNode.child_value("CurrentPassengers") << endl;
            cout << "Price Per Ton: \t\t$ " << vehicleNode.child_value("PricePerTon") << endl;
            cout << "Current Tons: \t\t" << vehicleNode.child_value("CurrentTons") << endl;
            cout << "Date Rented Out: \t" << vehicleNode.child_value("DateRentedOut") << endl;
            cout << "Available To Rent: \t" << vehicleNode.child_value("AvailableToRent") << endl;
            cout << "+----------------------------------+" << endl << endl;
        }

    }
}

Car XMLHandler::readCar(pugi::xml_node vehicleNode)
{
    Car c(
        LicensePlate(vehicleNode.child_value("LicensePlateNumber"), vehicleNode.child_value("LicensePlateIssuingCountry")),
        vehicleNode.child_value("Make"),
        vehicleNode.child_value("Model"),
        stoi(vehicleNode.child_value("Year")),
        stod(vehicleNode.child_value("PricePerKm")),
        stod(vehicleNode.child_value("PricePerDay")),
        stod(vehicleNode.child_value("Kms"))
        );

    string dateStringFromXML = vehicleNode.child_value("DateRentedOut");
    tm tm = {};
    istringstream ss(dateStringFromXML);
    ss >> get_time(&tm, "%Y/%m/%d %H:%M:%S");
    chrono::system_clock::time_point dateRentedOut = chrono::system_clock::from_time_t(std::mktime(&tm));

    c.DateRentedOut() = dateRentedOut;
    return c;
}

Bus XMLHandler::readBus(pugi::xml_node vehicleNode)
{
    Bus b(
        LicensePlate(vehicleNode.child_value("LicensePlateNumber"), vehicleNode.child_value("LicensePlateIssuingCountry")),
        vehicleNode.child_value("Make"),
        vehicleNode.child_value("Model"),
        stoi(vehicleNode.child_value("Year")),
        stod(vehicleNode.child_value("PricePerKm")),
        stod(vehicleNode.child_value("PricePerDay")),
        stod(vehicleNode.child_value("InsuranceCostPerPerson")),
        stod(vehicleNode.child_value("Kms"))
        );

    string dateStringFromXML = vehicleNode.child_value("DateRentedOut");
    tm tm = {};
    istringstream ss(dateStringFromXML);
    ss >> get_time(&tm, "%Y/%m/%d %H:%M:%S");
    chrono::system_clock::time_point dateRentedOut = chrono::system_clock::from_time_t(std::mktime(&tm));

    b.DateRentedOut() = dateRentedOut;
    b.CurrentPassengers() = stoi(vehicleNode.child_value("CurrentPassengers"));
    return b;
}

Truck XMLHandler::readTruck(pugi::xml_node vehicleNode)
{
    Truck t(
        LicensePlate(vehicleNode.child_value("LicensePlateNumber"), vehicleNode.child_value("LicensePlateIssuingCountry")),
        vehicleNode.child_value("Make"),
        vehicleNode.child_value("Model"),
        stoi(vehicleNode.child_value("Year")),
        stod(vehicleNode.child_value("PricePerKm")),
        stod(vehicleNode.child_value("PricePerDay")),
        stod(vehicleNode.child_value("Kms")),
        stod(vehicleNode.child_value("PricePerTon"))
        );

    string dateStringFromXML = vehicleNode.child_value("DateRentedOut");
    tm tm = {};
    istringstream ss(dateStringFromXML);
    ss >> get_time(&tm, "%Y/%m/%d %H:%M:%S");
    chrono::system_clock::time_point dateRentedOut = chrono::system_clock::from_time_t(std::mktime(&tm));

    t.DateRentedOut() = dateRentedOut;
    t.CurrentTons() = stoi(vehicleNode.child_value("CurrentTons"));
    return t;
}

Machinery XMLHandler::readMachinery(pugi::xml_node vehicleNode)
{
    Machinery m(
        LicensePlate(vehicleNode.child_value("LicensePlateNumber"), vehicleNode.child_value("LicensePlateIssuingCountry")),
        vehicleNode.child_value("Make"),
        vehicleNode.child_value("Model"),
        stoi(vehicleNode.child_value("Year")),
        stod(vehicleNode.child_value("PricePerDay")),
        stod(vehicleNode.child_value("PricePerTon"))
        );

    string dateStringFromXML = vehicleNode.child_value("DateRentedOut");
    tm tm = {};
    istringstream ss(dateStringFromXML);
    ss >> get_time(&tm, "%Y/%m/%d %H:%M:%S");
    chrono::system_clock::time_point dateRentedOut = chrono::system_clock::from_time_t(std::mktime(&tm));

    m.DateRentedOut() = dateRentedOut;
    m.CurrentTons() = stoi(vehicleNode.child_value("CurrentTons"));
    return m;
}

void XMLHandler::changeRentalStatus(string& licensePlate_p, const int& command)
{
    string licensePlate, dateString, type;
    stringstream ss;
    chrono::system_clock::time_point currentDate;
    time_t currentTime;
    double input;

    result = vehiclesXML.load_file("vehiclesXML.xml");
    if (!result) {
        cout << "Error loading XML file!" << endl;
        return;
    }

    pugi::xml_node fleet = vehiclesXML.child("fleet");
    for (pugi::xml_node vehicleNode = fleet.first_child() ; vehicleNode; vehicleNode = vehicleNode.next_sibling())
    {
        type = vehicleNode.child_value("Type");
        licensePlate = vehicleNode.child_value("LicensePlateNumber");
        if (licensePlate == licensePlate_p)
        {
            pugi::xml_node parent = vehicleNode.parent();
            dateString = vehicleNode.child_value("DateRentedOut");

            switch(command)
            {
            case 0: // renting out
                if (dateString != "0")
                {
                    cout << "Vehicle already rented out!" << endl;
                    return;
                }
                // Get the current time_point
                currentDate = chrono::system_clock::now();
                // Convert the time_point to a time_t
                currentTime = chrono::system_clock::to_time_t(currentDate);

                // Convert the time_t to a string in the desired format
                ss << put_time(localtime(&currentTime), "%Y/%m/%d %H:%M:%S");
                dateString = ss.str();

                // Append the child with today's date
                vehicleNode.child("DateRentedOut").text().set(dateString.c_str());
                if (type == "Bus")
                {
                    cout << "How many passengers: ";
                    cin >> input;
                    vehicleNode.child("CurrentPassengers").text().set(input);
                }
                else if (type == "Truck" || type == "Machinery")
                {
                    cout << "How many tons: ";
                    cin >> input;
                    vehicleNode.child("CurrentTons").text().set(input);
                }
//                if (type != "Machinery")
//                {
//                    vehicleNode.child("KmReturned").text().set("0");
//                }
                vehicleNode.child("AvailableToRent").text().set("false");

                cout << "Vehicle with license plate: " << licensePlate << " rented out at: " << dateString << endl;
                break;
            case 1: // returning vehicle to fleet
                if (dateString == "0")
                {
                    cout << "Vehicle already returned!" << endl;
                    return;
                }
                if (type == "Bus")
                {
                    vehicleNode.child("CurrentPassengers").text().set("0");
                }
                else if (type == "Truck" || type == "Machinery")
                {
                    vehicleNode.child("CurrentTons").text().set("0");
                }
//                if (type != "Machinery")
//                {
//                    cout << "Set new kms: ";
//                    cin >> input;
//                    vehicleNode.child("KmReturned").text().set(input);
//                }
                vehicleNode.child("DateRentedOut").text().set("0");
                vehicleNode.child("AvailableToRent").text().set("true");

                cout << "Vehicle with license plate: " << licensePlate << " returned to fleet." << endl;
                break;
            default:
                cout << "changeRentalStatus() error!" << endl;
                break;
            }

            vehiclesXML.save_file("vehiclesXML.xml");
            return;
        }
    }
//    cout << "Error! License plate: " << licensePlate_p << " not in fleet!" << endl;
}

void XMLHandler::deleteByLicensePlate(string& licensePlate_p)
{
    result = vehiclesXML.load_file("vehiclesXML.xml");
    if (!result) {
        cout << "Error loading XML file!" << endl;
        return;
    }

    pugi::xml_node fleet = vehiclesXML.child("fleet");
    for (pugi::xml_node vehicleNode = fleet.first_child() ; vehicleNode; vehicleNode = vehicleNode.next_sibling())
    {
        string licensePlate = vehicleNode.child_value("LicensePlateNumber");
        if (licensePlate == licensePlate_p)
        {
            pugi::xml_node parent = vehicleNode.parent();
            parent.remove_child(vehicleNode);

            vehiclesXML.save_file("vehiclesXML.xml");

            cout << "Vehicle with license plate: " << licensePlate_p << " deleted successfully!" << endl;
            return;
        }
    }
//    cout << "Error! License plate: " << licensePlate_p << " not in fleet!" << endl;
}


bool XMLHandler::licensePlateExists(string& licensePlate, string& issuingCountry)
{
    if (!vehiclesXML)
    {
        result = vehiclesXML.load_file("vehiclesXML.xml");
        if (!result)
        {
            cout << "Error loading XML file!" << endl;
            return false;
        }
    }

    pugi::xml_node fleet = vehiclesXML.child("fleet");
    for (pugi::xml_node vehicleNode = fleet.first_child(); vehicleNode; vehicleNode = vehicleNode.next_sibling())
    {
        string currentLicensePlate = vehicleNode.child_value("LicensePlateNumber");
        string currentIssuingCountry = vehicleNode.child_value("LicensePlateIssuingCountry");

        if (currentLicensePlate == licensePlate && currentIssuingCountry == issuingCountry)
        {
            return true;
        }
    }
    return false;
}

void XMLHandler::saveToFile()
{
    // create "xml_files" if not exists
    string folderPath = "xml_files";
    // Platform-specific commands to create a directory
    #ifdef _WIN32
        string command = "mkdir " + folderPath;
    #else
        string command = "mkdir -p " + folderPath;
    #endif
        system(command.c_str());
    // full file path

    string filePath = folderPath + "/vehiclesXML.xml";

    // open file for writing
    ofstream outFile(filePath);
    if (!outFile.is_open()) {
        cout << "Error opening file for writing. Save operation aborted." << endl;
        return;
    }

    // Save XML to the file
    vehiclesXML.save(outFile);
    outFile.close();

    cout << "XML saved to: " << filePath << endl;
}

void XMLHandler::loadFromFile() {
    // check if the file exists
    ifstream file("xml_files/vehiclesXML.xml");
    if (!file.is_open()) {
        cout << "Error opening file. Operation aborted!" << endl;
        return;
    }

    // load XML
    result = vehiclesXML.load(file);
    file.close();

    if (!result) {
        cout << "Error loading XML file!" << endl;
        return;
    }
    vehiclesXML.save_file("vehiclesXML.xml");
    cout << "XML loaded successfully from xml_files/vehiclesXML.xml" << endl;
}





