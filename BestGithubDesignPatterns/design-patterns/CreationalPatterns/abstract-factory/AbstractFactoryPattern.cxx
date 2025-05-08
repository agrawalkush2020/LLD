/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>

class Vehicle {
public:
    virtual void showType() = 0;
    virtual ~Vehicle() = default;
};

class Helmet {
public:
    virtual void protect() = 0;
    virtual ~Helmet() = default;
};

// Concrete Products
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

class BikeHelmet : public Helmet {
public:
    void protect() override {
        std::cout << "Bike Helmet: Safety ensured!" << std::endl;
    }
};

class CarHelmet : public Helmet {
public:
    void protect() override {
        std::cout << "Car Helmet: Safety ensured!" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual Vehicle* createVehicle() = 0;
    virtual Helmet* createHelmet() = 0;
    virtual ~AbstractFactory() = default;
};

// Concrete Factories
class BikeFactory : public AbstractFactory {
public:
    Vehicle* createVehicle() override {
        return new Bike();
    }

    Helmet* createHelmet() override {
        return new BikeHelmet();
    }
};

class CarFactory : public AbstractFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();
    }

    Helmet* createHelmet() override {
        return new CarHelmet();
    }
};

int main() {
    AbstractFactory* factory = new BikeFactory();
    Vehicle* bike = factory->createVehicle();
    Helmet* bikeHelmet = factory->createHelmet();

    bike->showType();
    bikeHelmet->protect();

    delete bike;
    delete bikeHelmet;
    delete factory;

    factory = new CarFactory();
    Vehicle* car = factory->createVehicle();
    Helmet* carHelmet = factory->createHelmet();

    car->showType();
    carHelmet->protect();

    delete car;
    delete carHelmet;
    delete factory;

    return 0;
}


// #include <iostream>
// using namespace std;

// // Product A: Vehicle
// class Vehicle {
// public:
//     virtual void info() = 0;
// };

// class Bike : public Vehicle {
// public:
//     void info() override {
//         cout << "Bike for delivery\n";
//     }
// };

// class Car : public Vehicle {
// public:
//     void info() override {
//         cout << "Car for delivery\n";
//     }
// };

// // Product B: Helmet
// class Helmet {
// public:
//     virtual void type() = 0;
// };

// class BikeHelmet : public Helmet {
// public:
//     void type() override {
//         cout << "Bike Helmet\n";
//     }
// };

// class CarHelmet : public Helmet {
// public:
//     void type() override {
//         cout << "Car Helmet (seatbelt)\n";
//     }
// };

// // Abstract Factory
// class AbstractFactory {
// public:
//     virtual Vehicle* createVehicle() = 0;
//     virtual Helmet* createHelmet() = 0;
// };

// // Concrete Factory 1
// class BikeFactory : public AbstractFactory {
// public:
//     Vehicle* createVehicle() override {
//         return new Bike();
//     }
//     Helmet* createHelmet() override {
//         return new BikeHelmet();
//     }
// };

// // Concrete Factory 2
// class CarFactory : public AbstractFactory {
// public:
//     Vehicle* createVehicle() override {
//         return new Car();
//     }
//     Helmet* createHelmet() override {
//         return new CarHelmet();
//     }
// };

// // Main
// int main() {
//     AbstractFactory* factory;

//     // Bike setup
//     factory = new BikeFactory();
//     Vehicle* bike = factory->createVehicle();
//     Helmet* bikeHelmet = factory->createHelmet();
//     bike->info();
//     bikeHelmet->type();

//     cout << endl;

//     // Car setup
//     factory = new CarFactory();
//     Vehicle* car = factory->createVehicle();
//     Helmet* carHelmet = factory->createHelmet();
//     car->info();
//     carHelmet->type();

//     return 0;
// }


// #include <iostream>

// class AbstractProductA {
// public:
//   AbstractProductA() { std::cout << "AbstractProductA" << std::endl; }
//   virtual ~AbstractProductA() {}
//   virtual void checkProduct() = 0;
// };

// class AbstractProductB {
// public:
//   AbstractProductB() { std::cout << "AbstractProductB" << std::endl; }
//   virtual  ~AbstractProductB() {}
//   virtual void checkProduct() = 0;
// };

// class ProductA1 : public AbstractProductA {
// public:
//   ProductA1() { std::cout << "ProductA1" << std::endl; }
//   ~ProductA1() {}
//   void checkProduct() { std::cout << "ProductA1 has been created" << std::endl;}

// };

// class ProductA2 : public AbstractProductA {
// public:
//   ProductA2() { std::cout << "ProductA2" << std::endl; }
//   ~ProductA2() {}
//   void checkProduct() { std::cout << "ProductA2 has been created" << std::endl; }

// };

// class ProductB1 : public AbstractProductB {
// public:
//   ProductB1() { std::cout << "ProductB1" << std::endl; }
//   ~ProductB1() {}
//   void checkProduct() { std::cout << "ProductB1 has been created" << std::endl; }

// };

// class ProductB2 : public AbstractProductB {
// public:
//   ProductB2() { std::cout << "ProductB2" << std::endl; }
//   ~ProductB2() {}
//   void checkProduct() { std::cout << "ProductB2 has been created" << std::endl; }

// };

// class AbstractFactory {
// public:
//   AbstractFactory() { std::cout << "AbstractFactory" << std::endl; }
//   virtual ~AbstractFactory() {}
//   virtual AbstractProductA* createProductA() = 0;
//   virtual AbstractProductB* createProductB() = 0;
// };

// class ConcreateFactory1 : public AbstractFactory {
// public:
//   ConcreateFactory1() { std::cout << "ConcreateFactory1" << std::endl; }
//   ~ConcreateFactory1() {}
//   AbstractProductA* createProductA() { return new ProductA1; }
//   AbstractProductB* createProductB() { return new ProductB1; }
// };

// class ConcreateFactory2 : public AbstractFactory {
// public:
//   ConcreateFactory2() { std::cout << "ConcreateFactory2" << std::endl; }
//   ~ConcreateFactory2() {}
//   AbstractProductA* createProductA() { return new ProductA2; }
//   AbstractProductB* createProductB() { return new ProductB2; }
// };

// int main(int argc, char* argv[]) {
//   AbstractFactory* cf1 = new ConcreateFactory1();
//   AbstractProductA* productA1 = cf1->createProductA();
//   productA1->checkProduct();
//   AbstractProductB* productB1 = cf1->createProductB();
//   productB1->checkProduct();

//   AbstractFactory* cf2 = new ConcreateFactory2();
//   AbstractProductA* productA2 = cf2->createProductA();
//   productA2->checkProduct();
//   AbstractProductB* productB2 = cf1->createProductB();
//   productB2->checkProduct();

// }