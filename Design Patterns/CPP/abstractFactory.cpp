#include <iostream>
using namespace std;

// Step 1: Common Interface
class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~Vehicle() {} // Virtual destructor
};

// Step 2: Concrete Classes for Car Brands
class Honda : public Vehicle {
public:
    void start() override {
        cout << "Honda Car is starting" << endl;
    }
    void stop() override {
        cout << "Honda Car is stopping" << endl;
    }
};

class Toyota : public Vehicle {
public:
    void start() override {
        cout << "Toyota Car is starting" << endl;
    }
    void stop() override {
        cout << "Toyota Car is stopping" << endl;
    }
};

class BMW : public Vehicle {
public:
    void start() override {
        cout << "BMW Car is starting" << endl;
    }
    void stop() override {
        cout << "BMW Car is stopping" << endl;
    }
};

// Step 3: Abstract Factory
class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
    virtual ~VehicleFactory() {}
};

// Step 4: Concrete Factories
class HondaFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Honda();
    }
};

class ToyotaFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Toyota();
    }
};

class BMWFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new BMW();
    }
};

// Step 5: Client Code
int main() {
    VehicleFactory* hondaFactory = new HondaFactory();
    Vehicle* honda = hondaFactory->createVehicle();
    honda->start();
    honda->stop();

    VehicleFactory* toyotaFactory = new ToyotaFactory();
    Vehicle* toyota = toyotaFactory->createVehicle();
    toyota->start();
    toyota->stop();

    // Clean up
    delete honda;
    delete hondaFactory;
    delete toyota;
    delete toyotaFactory;

    return 0;
}
