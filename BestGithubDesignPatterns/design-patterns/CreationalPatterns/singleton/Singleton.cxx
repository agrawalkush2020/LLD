/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */


// yh perfect code hai 

#include <iostream>
#include <string>
using namespace std;

class Logger {
  private:
    Logger() {}  // Private constructor to prevent direct instantiation
    Logger(const Logger&) = delete;            // Delete copy constructor
    Logger& operator=(const Logger&) = delete; // Delete copy assignment

  public:
    static Logger& getInstance() {
        static Logger instance;  // Thread-safe and only initialized once
        return instance;
    }

    void log(const string& message) {
        cout << "Log: " << message << endl;
    }
};

class Application {
  public:
    void run() {
        Logger::getInstance().log("Application started.");
        Logger::getInstance().log("Application started.");
    }
};

int main() {
  Application app;
  app.run();
  return 0;
}



// #include <iostream>
// #include <string>

// class Singleton {
//   public:
//     Singleton(const Singleton&) = delete;
//     Singleton& operator=(const Singleton&) = delete;

//     static Singleton* instance() {
//       if (!instance_) {
//         instance_ = new Singleton();
//       }
//       return instance_;
//     }

//     void checkSingleton() { std::cout << "Singleton has been created" << std::endl; }
//   private:
//     Singleton() { std::cout << "Singleton" << std::endl; }
//     static Singleton* instance_;
// };

// Singleton* Singleton::instance_ = nullptr;

// int main(int argc, char* argv[]) {
//   Singleton *singleton = Singleton::instance();
//   singleton->checkSingleton();
// }