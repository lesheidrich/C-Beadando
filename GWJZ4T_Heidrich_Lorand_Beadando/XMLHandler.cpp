#include "XMLHandler.hpp"

using namespace std;
using namespace chrono;

// constructor initializes xml with columns
XMLHandler::XMLHandler()
{
    result = vehiclesXML.load_file("vehiclesXML.xml");

    if (!result) {
        // If the file does not exist, create a new one with the fleet node
        fleetNode = vehiclesXML.append_child("fleet");
        vehiclesXML.save_file("vehiclesXML.xml");
    } else {
        // If the file exists, get the existing fleet node
        fleetNode = vehiclesXML.child("fleet");
    }
}

void XMLHandler::addCar(Car* c)
{
    // node inside <fleet> to house vehicle instance data
    pugi::xml_node vehicleNode = fleetNode.append_child("vehicle");
    // add vehicle info
    vehicleNode.append_child("LicensePlateNumber").text().set(c->VehicleLicensePlate().c_str());
    vehicleNode.append_child("LicensePlateIssuingCountry").text().set(c->getIssuingCountry().c_str());
    vehicleNode.append_child("Type").text().set("Car");
    vehicleNode.append_child("Make").text().set(c->getVehicleMake().c_str());
    vehicleNode.append_child("Model").text().set(c->getVehicleModel().c_str());
    vehicleNode.append_child("Year").text().set(c->getVehicleYear());
    vehicleNode.append_child("Kms").text().set(c->Km());
    vehicleNode.append_child("PricePerKm").text().set(c->getPricePerKm());
    vehicleNode.append_child("PricePerDay").text().set(c->getPricePerDay());
//    vehicleNode.append_child("InsuranceCostPerPerson").text().set(insuranceCostPerPerson);
//    vehicleNode.append_child("CurrentPassengers").text().set(currentPassengers);
//    vehicleNode.append_child("DateRentedOut").text().set(dateRentedOut.time_since_epoch().count());
//    vehicleNode.append_child("PricePerTon").text().set(pricePerTon);
//    vehicleNode.append_child("CurrentTons").text().set(currentTons);
    vehicleNode.append_child("AvailableToRent").text().set("true");

    vehiclesXML.save_file("vehiclesXML.xml");
}

void XMLHandler::addBus(Bus* b)
{
    // node inside <fleet> to house vehicle instance data
    pugi::xml_node vehicleNode = fleetNode.append_child("vehicle");
    // add vehicle info
    vehicleNode.append_child("LicensePlateNumber").text().set(b->VehicleLicensePlate().c_str());
    vehicleNode.append_child("LicensePlateIssuingCountry").text().set(b->getIssuingCountry().c_str());
    vehicleNode.append_child("Type").text().set("Bus");
    vehicleNode.append_child("Make").text().set(b->getVehicleMake().c_str());
    vehicleNode.append_child("Model").text().set(b->getVehicleModel().c_str());
    vehicleNode.append_child("Year").text().set(b->getVehicleYear());
    vehicleNode.append_child("Kms").text().set(b->Km());
    vehicleNode.append_child("PricePerKm").text().set(b->getPricePerKm());
    vehicleNode.append_child("PricePerDay").text().set(b->getPricePerDay());
    vehicleNode.append_child("InsuranceCostPerPerson").text().set(b->getInsuranceCostPerPerson());
    vehicleNode.append_child("CurrentPassengers").text().set(b->CurrentPassengers());
    vehicleNode.append_child("AvailableToRent").text().set("true");

    vehiclesXML.save_file("vehiclesXML.xml");
}

void XMLHandler::addTruck(Truck* t)
{
    // node inside <fleet> to house vehicle instance data
    pugi::xml_node vehicleNode = fleetNode.append_child("vehicle");
    // add vehicle info
    vehicleNode.append_child("LicensePlateNumber").text().set(t->VehicleLicensePlate().c_str());
    vehicleNode.append_child("LicensePlateIssuingCountry").text().set(t->getIssuingCountry().c_str());
    vehicleNode.append_child("Type").text().set("Truck");
    vehicleNode.append_child("Make").text().set(t->getVehicleMake().c_str());
    vehicleNode.append_child("Model").text().set(t->getVehicleModel().c_str());
    vehicleNode.append_child("Year").text().set(t->getVehicleYear());
    vehicleNode.append_child("Kms").text().set(t->Km());
    vehicleNode.append_child("PricePerKm").text().set(t->getPricePerKm());
    vehicleNode.append_child("PricePerDay").text().set(t->getPricePerDay());
    vehicleNode.append_child("PricePerTon").text().set(t->getPricePerTon());
    vehicleNode.append_child("CurrentTons").text().set(t->CurrentTons());
    vehicleNode.append_child("AvailableToRent").text().set("true");

    vehiclesXML.save_file("vehiclesXML.xml");
}

void XMLHandler::addMachinery(Machinery* m)
{
    // node inside <fleet> to house vehicle instance data
    pugi::xml_node vehicleNode = fleetNode.append_child("vehicle");
    // add vehicle info
    vehicleNode.append_child("LicensePlateNumber").text().set(m->VehicleLicensePlate().c_str());
    vehicleNode.append_child("LicensePlateIssuingCountry").text().set(m->getIssuingCountry().c_str());
    vehicleNode.append_child("Type").text().set("Machinery");
    vehicleNode.append_child("Make").text().set(m->getVehicleMake().c_str());
    vehicleNode.append_child("Model").text().set(m->getVehicleModel().c_str());
    vehicleNode.append_child("Year").text().set(m->getVehicleYear());
    vehicleNode.append_child("PricePerDay").text().set(m->getPricePerDay());
    vehicleNode.append_child("PricePerTon").text().set(m->getPricePerTon());
    vehicleNode.append_child("CurrentTons").text().set(m->CurrentTons());
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

    cout << "+----------------------------------+" << endl << endl;
    cout << "ALL VEHICLES:" << endl;
    for (pugi::xml_node vehicleNode = fleet.first_child() ; vehicleNode; vehicleNode = vehicleNode.next_sibling())
    {
        string licensePlate = vehicleNode.child_value("LicensePlateNumber");
        if (licensePlate == "asdf")
        {
            cout << "License Plate: \t\t" << vehicleNode.child_value("LicensePlateNumber") << endl;
            cout << "Issuing Country: \t" << vehicleNode.child_value("LicensePlateIssuingCountry") << endl;
            cout << "Type: \t\t\t" << vehicleNode.child_value("Type") << endl;
            cout << "Make: \t\t\t" << vehicleNode.child_value("Make") << endl;
            cout << "Model: \t\t\t" << vehicleNode.child_value("Model") << endl;
            cout << "Year: \t\t\t" << vehicleNode.child_value("Year") << endl;
            cout << "Kms: \t\t\t" << vehicleNode.child_value("Kms") << endl;
            cout << "Price/Km: \t\t$ " << vehicleNode.child_value("PricePerKm") << endl;
            cout << "Price/Day: \t\t$ " << vehicleNode.child_value("PricePerDay") << endl;
            cout << "Insurance Cost/Person: \t$ " << vehicleNode.child_value("InsuranceCostPerPerson") << endl;
            cout << "Current Passengers: \t" << vehicleNode.child_value("CurrentPassengers") << endl;
            cout << "Price Per Ton: \t$ " << vehicleNode.child_value("PricePerTon") << endl;
            cout << "Current Tons: \t" << vehicleNode.child_value("CurrentTons") << endl;
            auto dateRentedOut = vehicleNode.child("DateRentedOut").text().as_ullong();
            cout << "Date Rented Out: \t" << chrono::system_clock::time_point(chrono::system_clock::duration(dateRentedOut)).time_since_epoch().count() << endl;
            cout << "Available To Rent: \t" << vehicleNode.child_value("AvailableToRent") << endl;
            cout << "+----------------------------------+" << endl << endl;

            break;
        }

    }

}

// Vehicle xmlToVehicle()
//            cout << "License Plate: \t\t" << vehicleNode.child_value("LicensePlateNumber") << endl;
//            cout << "Issuing Country: \t" << vehicleNode.child_value("LicensePlateIssuingCountry") << endl;
//            cout << "Type: \t\t\t" << vehicleNode.child_value("Type") << endl;
//            cout << "Make: \t\t\t" << vehicleNode.child_value("Make") << endl;
//            cout << "Model: \t\t\t" << vehicleNode.child_value("Model") << endl;
//            cout << "Year: \t\t\t" << vehicleNode.child_value("Year") << endl;
//            cout << "Kms: \t\t\t" << vehicleNode.child_value("Kms") << endl;
//            cout << "Price/Km: \t\t$ " << vehicleNode.child_value("PricePerKm") << endl;
//            cout << "Price/Day: \t\t$ " << vehicleNode.child_value("PricePerDay") << endl;
//            cout << "Insurance Cost/Person: \t$ " << vehicleNode.child_value("InsuranceCostPerPerson") << endl;
//            cout << "Current Passengers: \t" << vehicleNode.child_value("CurrentPassengers") << endl;
//            cout << "Price Per Ton: \t$ " << vehicleNode.child_value("PricePerTon") << endl;
//            cout << "Current Tons: \t" << vehicleNode.child_value("CurrentTons") << endl;
//            auto dateRentedOut = vehicleNode.child("DateRentedOut").text().as_ullong();
//            cout << "Date Rented Out: \t" << chrono::system_clock::time_point(chrono::system_clock::duration(dateRentedOut)).time_since_epoch().count() << endl;
//            cout << "Available To Rent: \t" << vehicleNode.child_value("AvailableToRent") << endl;


void XMLHandler::deleteByLicensePlate(string licensePlate_p)
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
            cout << "Vehicle with license plate: " << licensePlate_p << " deleted successfully!" << endl;
            break;
        }
    }
    cout << "Error! License plate: " << licensePlate_p << " not in fleet!" << endl;
}






