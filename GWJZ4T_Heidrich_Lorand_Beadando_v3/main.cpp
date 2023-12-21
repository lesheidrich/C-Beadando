    #include "LicensePlate.hpp"
    #include "Car.hpp"
    #include "Bus.hpp"
    #include "Truck.hpp"
    #include "Machinery.hpp"
    #include "MenuController.hpp"

    #include <iostream>
    #include <chrono>

    #include "pugixml.hpp"


    using namespace std;
    using namespace chrono;



    int main()
    {

//
////        licensePlateNumber
////        licensePlateIssuingCountry
////        type
////        make
////        model
////        year
////        kms
////        pricePerKm
////        pricePerDay
////        insuranceCostPerPerson
////        currentPassengers
////        dateRentedOut
////        pricePerTon
////        currentTons
////        availableToRent
//
//        string licensePlateNumber;
//        string licensePlateIssuingCountry;
//        string type;
//        string make;
//        string model;
//        int year;
//        double kms;
//        double pricePerKm;
//        double pricePerDay;
//        double insuranceCostPerPerson;
//        int currentPassengers;
//        std::chrono::time_point<std::chrono::system_clock> dateRentedOut;
//        double pricePerTon;
//        double currentTons;
//        bool availableToRent;



//        ***** XML SPAGHETTI TEST ************

//
//        pugi::xml_document vehiclesXML;
//        string s = "puppyfarts";
//        s = c->getVehicleMake();
//        int n = 8;
//
//        // Create an XML document
//        // Add a root node for column head
//        pugi::xml_node fleet = vehiclesXML.append_child("fleet");
//
//        /*** CREATE ***/
//        // Add child nodes for string and int values
//        fleet.append_child("s").text().set(s.c_str());
//        fleet.append_child("n").text().set(n);
//
//        // Save the XML document to a file
//        vehiclesXML.save_file("vehiclesXML.xml");
//
//        cout << "Data saved to vehiclesXML.xml" << std::endl;
//
//
//        /*** READ ***/
//        // Load the XML document
//        pugi::xml_parse_result result = vehiclesXML.load_file("vehiclesXML.xml");
//
//        if (!result) {
//            std::cout << "Error loading XML file!" << std::endl;
//            return 1;
//        }
//
//        // Retrieve string and int values
//        std::cout << "String (s): " << fleet.child("s").text().as_string() << std::endl;
//        std::cout << "Integer (n): " << fleet.child("n").text().as_int() << std::endl;


        MenuController mc;
        mc.run();

//        LicensePlate licensePlate("ABC123", "Germany");
////        Car c(licensePlate, "ferrari", "maranello", 1998, 1.5, 3.5, 200);
//        Car* c = new Car(licensePlate, "ferrari", "maranello", 1998, 1.5, 3.5, 200);
//        XMLHandler x;
//        x.addVehicle(c);
////        x.addVehicle(&c);



//        pugi::xml_document vehiclesXML;
//        pugi::xml_node fleetNode;
//        pugi::xml_node vehicleNode;
//
//        LicensePlate licensePlate("ABC123", "Germany");
//        Car c = Car(licensePlate, "ferrari", "maranello", 1998, 1.5, 3.5, 200);
//
//
//        vehicleNode = vehiclesXML.append_child("vehicle");
//    //    string s = "puppyfarts";
//    //    int n = 8;
//    //    fleet.append_child("s").text().set(s.c_str());
//    //    fleet.append_child("n").text().set(n);
//    //    vehicleNode.append_child("LicensePlateNumber").text().set(c.VehicleLicensePlate().c_str());
//        // add vehicle info
//        vehicleNode.append_child("LicensePlateNumber").text().set("asdf");
//        vehicleNode.append_child("LicensePlateIssuingCountry").text().set(c.getIssuingCountry().c_str());
//        vehicleNode.append_child("Type").text().set("Car");
//        vehicleNode.append_child("Make").text().set(c.getVehicleMake().c_str());
//        vehicleNode.append_child("Model").text().set(c.getVehicleModel().c_str());
//        vehicleNode.append_child("Year").text().set(c.getVehicleYear());
//        vehicleNode.append_child("Kms").text().set(c.Km());
//        vehicleNode.append_child("PricePerKm").text().set(c.getPricePerKm());
//        vehicleNode.append_child("PricePerDay").text().set(c.getPricePerDay());
//    //    vehicleNode.append_child("InsuranceCostPerPerson").text().set(insuranceCostPerPerson);
//    //    vehicleNode.append_child("CurrentPassengers").text().set(currentPassengers);
//    //    vehicleNode.append_child("DateRentedOut").text().set(dateRentedOut.time_since_epoch().count());
//    //    vehicleNode.append_child("PricePerTon").text().set(pricePerTon);
//    //    vehicleNode.append_child("CurrentTons").text().set(currentTons);
//        vehicleNode.append_child("AvailableToRent").text().set("true");
//
//        vehiclesXML.save_file("vehiclesXML.xml");
//        cout << "Data saved to vehiclesXML.xml" << std::endl;
//
//
//
//        pugi::xml_parse_result result = vehiclesXML.load_file("vehiclesXML.xml");
//
//        if (!result) {
//            std::cout << "Error loading XML file!" << std::endl;
//            //throw error
//        }
//
//        cout << "ALL VEHICLES:" << endl;
//        // Iterate over vehicle nodes
//        for (; vehicleNode; vehicleNode = vehicleNode.next_sibling("vehicle"))
//        {
//            cout << "License Plate: " << vehicleNode.child_value("LicensePlateNumber") << endl;
//            cout << "Issuing Country: " << vehicleNode.child_value("LicensePlateIssuingCountry") << endl;
//            cout << "Type: " << vehicleNode.child_value("Type") << endl;
//            cout << "Make: " << vehicleNode.child_value("Make") << endl;
//            cout << "Model: " << vehicleNode.child_value("Model") << endl;
//            cout << "Year: " << vehicleNode.child_value("Year") << endl;
//            cout << "Kms: " << vehicleNode.child_value("Kms") << endl;
//            cout << "Price Per Km: " << vehicleNode.child_value("PricePerKm") << endl;
//            cout << "Price Per Day: " << vehicleNode.child_value("PricePerDay") << endl;
//            cout << "Insurance Cost Per Person: " << vehicleNode.child_value("InsuranceCostPerPerson") << endl;
//            cout << "Current Passengers: " << vehicleNode.child_value("CurrentPassengers") << endl;
//            cout << "Price Per Ton: " << vehicleNode.child_value("PricePerTon") << endl;
//            cout << "Current Tons: " << vehicleNode.child_value("CurrentTons") << endl;
//            auto dateRentedOut = vehicleNode.child("DateRentedOut").text().as_ullong();
//            cout << "Date Rented Out: " << chrono::system_clock::time_point(chrono::system_clock::duration(dateRentedOut)).time_since_epoch().count() << endl;
//            cout << "Available To Rent: " << vehicleNode.child_value("AvailableToRent") << endl;
//            cout << "----------------------------------------" << endl;
//        }

//*******************************************************************************************

//        LicensePlate licensePlate("ABC123", "Germany");
//
//        int days;
//        //                                                       price/km, price/day, km -10
//        Car* c = new Car(licensePlate, "ferrari", "maranello", 1998, 1.5, 3.5, 200);
//        //                                                       price/km, price/day, insurance, km 250
//        Bus* b = new Bus(licensePlate, "ferrari", "maranello", 1998, 2.5, 4.5, 5, 200);
//        c->DateRentedOut() = system_clock::now(); //rent out function has to do
//        days = c->getDaysOut();
//        c->KmReturned() = 210; //set to 0 when returned to inventory
//
//        b->DateRentedOut() = system_clock::now();
//        b->KmReturned() = 250;
//        b->CurrentPassengers() = 10;
//
//        double costc = c->calculateCost();
//        double costb = b->calculateCost();
//
//
//        std::cout << "Number of days rented: " << costc << " days" << std::endl;
//        std::cout << "Number of days rented: " << costb << " days" << std::endl;
//        c->printQuote();
//        c->printInvoice();
//        b->printQuote();
//        b->printInvoice();
//
//        Truck* t = new Truck(licensePlate, "Dodge", "Ram", 2006, 3.5, 5.5, 200, 6);
//        t->DateRentedOut() = system_clock::now();
//        t->KmReturned() = 270;
//        t->CurrentTons() = 20;
//
//        t->printQuote();
//        t->printInvoice();
//        //                                                                             $/day, $/t
//        Machinery* m = new Machinery(licensePlate, "Caterpillar", "320 excavator", 2001, 5, 5.5);
//        m->DateRentedOut() = system_clock::now();
//        m->CurrentTons() = 50;
//
//        m->printQuote();
//        m->printInvoice();

        return 0;
    }


