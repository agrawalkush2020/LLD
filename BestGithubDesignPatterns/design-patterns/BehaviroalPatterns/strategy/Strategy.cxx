/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>

class Strategy {
public:
    virtual ~Strategy() {}
    virtual void algorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
    ~ConcreteStrategyA() {}

    void algorithmInterface() {
        std::cout << "Concrete Strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
    ~ConcreteStrategyB() {}

    void algorithmInterface() {
        std::cout << "Concrete Strategy B" << std::endl;
    }
};

class ConcreteStrategyC : public Strategy {
    ~ConcreteStrategyC() {}

    void algorithmInterface() {
        std::cout << "Concrete Strategy C" << std::endl;
    }
};

class Context {
    private:
        Strategy* strategy;
    public:
        Context(Strategy* s) : strategy(s) {}
        // Context(Strategy* s){     krta yh bhi yhi kaam hai lekin upr waala efficient hai 
        //     this->strategy = s;
        // }
        ~Context() {
            delete strategy;
        }

        void contextInterface() {
            strategy->algorithmInterface();
        }
};

int main() {
    Context* contextA = new Context(new ConcreteStrategyA());
    contextA->contextInterface();
    delete contextA;

    Context* contextB = new Context(new ConcreteStrategyB());
    contextB->contextInterface();
    delete contextB;

    Context* contextC = new Context(new ConcreteStrategyC());
    contextC->contextInterface();
    delete contextC;

    return 0;
    // Context context(new ConcreteStrategyA());
    // context.contextInterface();
}