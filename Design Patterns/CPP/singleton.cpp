#include <iostream>
#include <string>
using namespace std;

class Logger {
private:
    inline static Logger* instance = nullptr;  // ✅ C++17 feature
    // iska dhyn rkhna , cpp mein inline keyword ka use krke hee static value ki value define krskte
    // hain class ke andr hee 
    Logger() {}  // Private constructor

public:
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const string& message) {
        cout << "Log: " << message << endl;
    }
};

class Application {
public:
    void run() {
        Logger* logger = Logger::getInstance();
        logger->log("Application started.");
    }
};

int main() {
    Application app;
    app.run();
    return 0;
}
