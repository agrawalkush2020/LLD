#include <iostream>
#include <string>
using namespace std;

// Step 1: Base class
class Vehicle {
public:
    virtual void start() = 0; // Pure virtual function
    virtual ~Vehicle() {}     // Virtual destructor
};

// Step 2: Derived classes
class Car : public Vehicle {
public:
    void start() override {
        cout << "Car started 🚗" << endl;
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike started 🏍️" << endl;
    }
};

class Truck : public Vehicle {
public:
    void start() override {
        cout << "Truck started 🚚" << endl;
    }
};

// Step 3: Factory class
class VehicleFactory {
public:
    static Vehicle* getVehicle(const string& type) {
        if (type == "Car") return new Car();
        else if (type == "Bike") return new Bike();
        else if (type == "Truck") return new Truck();
        else return nullptr;
    }
};

// Step 4: Use the factory
int main() {
    string choice;
    cout << "Enter vehicle type (Car / Bike / Truck): ";
    cin >> choice;

    Vehicle* v = VehicleFactory::getVehicle(choice);
    if (v != nullptr) {
        v->start();
        delete v; // Clean up memory
    } else {
        cout << "Invalid vehicle type!" << endl;
    }

    return 0;
}
