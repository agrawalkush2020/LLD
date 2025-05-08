/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <string>

class Vehicle {
  public:
    virtual void showType() = 0;
    virtual ~Vehicle() = default;
};

class Bike : public Vehicle {
public:
    void showType() override {
        std::cout << "This is a Bike" << std::endl;
    }
};

class Car : public Vehicle {
public:
    void showType() override {
        std::cout << "This is a Car" << std::endl;
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
    virtual ~VehicleFactory() = default;
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Bike();
    }
};

class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();
    }
};

int main() {
    VehicleFactory* factory = new BikeFactory();
    Vehicle* bike = factory->createVehicle();
    bike->showType();

    delete bike;
    delete factory;

    factory = new CarFactory();
    Vehicle* car = factory->createVehicle();
    car->showType();

    delete car;
    delete factory;

    return 0;
}


// #include <iostream>
// using namespace std;

// // Product interface
// class Transport {
// public:
//     virtual void deliver() = 0;
// };

// // Concrete products
// class Bike : public Transport {
// public:
//     void deliver() override {
//         cout << "Delivering by Bike\n";
//     }
// };

// class Car : public Transport {
// public:
//     void deliver() override {
//         cout << "Delivering by Car\n";
//     }
// };

// // Creator class
// class TransportFactory {
// public:
//     virtual Transport* createTransport() = 0;
// };

// // Concrete factories
// class BikeFactory : public TransportFactory {
// public:
//     Transport* createTransport() override {
//         return new Bike();
//     }
// };

// class CarFactory : public TransportFactory {
// public:
//     Transport* createTransport() override {
//         return new Car();
//     }
// };

// // Main
// int main() {
//     TransportFactory* factory;

//     // Use Bike factory
//     factory = new BikeFactory();
//     Transport* bike = factory->createTransport();
//     bike->deliver();

//     // Use Car factory
//     factory = new CarFactory();
//     Transport* car = factory->createTransport();
//     car->deliver();

//     return 0;
// }



// #include <iostream>
// #include <string>

// class Product {
// public:
//   Product() { std::cout << "Product" << std::endl; }
//   virtual ~Product() {}

//   virtual void checkProduct() = 0;
// };

// class ConcreateProductA : public Product {
// public:
//   ConcreateProductA() { std::cout << "ConcreateProductA" << std::endl; }
//   ~ConcreateProductA() {}

//   void checkProduct() { std::cout << "ProductA has been created" << std::endl; }
// };

// class ConcreateProductB : public Product {
// public:
//   ConcreateProductB() { std::cout << "ConcreateProductB" << std::endl; }
//   ~ConcreateProductB() {}

//   void checkProduct() { std::cout << "ProductB has been created" << std::endl; }
// };

// class Creater {
// public:
//   Creater() { std::cout << "Creater" << std::endl; }
//   virtual ~Creater() {}

//   virtual Product* createProductA() = 0;
//   virtual Product* createProductB() = 0;
// };

// class ConcreateCreater : public Creater {
// public:
//   ConcreateCreater() { std::cout << "ConcreateCreater" << std::endl; }
//   ~ConcreateCreater() {}

//   Product* createProductA() { return new ConcreateProductA; }
//   Product* createProductB() { return new ConcreateProductB; }
// };

// int main(int argc, char* argv[]) {
//   Creater *creater = new ConcreateCreater;

//   Product *productA = creater->createProductA();
//   productA->checkProduct();

//   Product *productB = creater->createProductB();
//   productB->checkProduct();

// }