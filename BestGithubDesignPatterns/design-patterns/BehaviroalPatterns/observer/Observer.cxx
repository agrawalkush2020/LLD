/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Subject;

class Observer {
    public:
        Observer(int id) : id_(id) {}
        virtual ~Observer() {}

        virtual int getState() const = 0;
        virtual void update(Subject* subject) = 0;
        virtual int getId() const = 0;

    protected:
        int id_;
};

class ConcreteObserver : public Observer {
    public:
        ConcreteObserver(int state, int id)
            : object_state_(state), Observer(id) {}

        ~ConcreteObserver() override {}

        int getState() const override {
            return object_state_;
        }

        int getId() const override {
            return id_;
        }

        void update(Subject* subject) override;

    private:
        int object_state_;
};

class Subject {
    public:
        virtual ~Subject() {}

        void attach(Observer* observer) {
            observers_.push_back(observer);
        }

        void detach(int id) {
            for (auto it = observers_.begin(); it != observers_.end(); ++it) {
                if ((*it)->getId() == id) {
                    observers_.erase(it);
                    break;  // prevent iterator invalidation
                }
            }
        }

        void notify() {
            for (auto observer : observers_) {
                observer->update(this);
            }
        }

        virtual int getState() const = 0;
        virtual void setState(int state) = 0;

    protected:
        vector<Observer*> observers_;
};

class ConcreteSubject : public Subject {
    public:
        ~ConcreteSubject() override {}

        int getState() const override {
            return subject_state_;
        }

        void setState(int state) override {
            subject_state_ = state;
        }

    private:
        int subject_state_ = 0;
};

void ConcreteObserver::update(Subject* subject) {
    object_state_ = subject->getState();
    cout << "Observer(id=" << id_ << ") update state to: " << object_state_ << endl;
}

int main() {
    ConcreteObserver observer1(1000, 1);
    ConcreteObserver observer2(2000, 2);

    cout << "Observer1 state: " << observer1.getState() << endl;
    cout << "Observer2 state: " << observer2.getState() << endl;

    Subject* subject = new ConcreteSubject();
    subject->attach(&observer1);
    subject->attach(&observer2);

    subject->setState(10);
    subject->notify();

    cout << "Observer1 state: " << observer1.getState() << endl;
    cout << "Observer2 state: " << observer2.getState() << endl;

    subject->detach(1); // FIXED: detach observer1 using valid id
    subject->setState(100);
    subject->notify();

    cout << "Observer1 state: " << observer1.getState() << endl;
    cout << "Observer2 state: " << observer2.getState() << endl;

    delete subject; // prevent memory leak
    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// class Subject;

// class Observer {
//     public:
//         Observer(const int id) : id_(id) {}
//         virtual ~Observer() {}

//         virtual int getState() = 0;
//         virtual void update(Subject* subject) = 0;
//         virtual int getId() = 0;
//     protected:
//         int id_;
// };

// class ConcreteObserver : public Observer {
//     public:
//         ConcreteObserver(const int state, const int id)
//         : object_state_(state), Observer(id) {}
//         ~ConcreteObserver() {}

//         int getState() {
//             return object_state_;
//         }

//         int getId() {
//             return id_;
//         }

//         void update(Subject* subject);
//     private:
//         int object_state_;
// };

// class Subject {
//     private:
//         vector<Observer*> observers_;
//     public:
//         virtual ~Subject() {}

//         void attach(Observer* observer) {
//             observers_.push_back(observer);
//         }

//         void detach(const int id) {
//             for (auto it = observers_.begin(); it != observers_.end(); ++it) {
//                 if ((*it)->getId() == id) {
//                     observers_.erase(it);
//                 }
//             }
//         }

//         void notify() {
//             for (auto observer : observers_) {
//                 observer->update(this);
//             }
//         }

//         virtual int getState() = 0;
//         virtual void setState(const int state) = 0;
// };

// class ConcreteSubject : public Subject {
// public:
//     ~ConcreteSubject() {}

//     int getState() {
//         return subject_state_;
//     }

//     void setState(const int state) {
//         subject_state_ = state;
//     }
// private:
//     int subject_state_;
// };

// void ConcreteObserver::update(Subject *subject) {
//     object_state_ = subject->getState();
//     cout << "Observer(id=" << id_ << ") update state to: " << object_state_ << endl;
// }

// int main() {
//     ConcreteObserver observer1(1000, 1);
//     ConcreteObserver observer2(2000, 2);

//     cout << "Observer1 state: " << observer1.getState() << endl;
//     cout << "Observer2 state: " << observer2.getState() << endl;

//     Subject* subject = new ConcreteSubject();
//     subject->attach(&observer1);
//     subject->attach(&observer2);

//     subject->setState(10);
//     subject->notify();

//     cout << "Observer1 state: " << observer1.getState() << endl;
//     cout << "Observer2 state: " << observer2.getState() << endl;

//     subject->detach(1);
//     subject->setState(100);
//     subject->notify();

//     cout << "Observer1 state: " << observer1.getState() << endl;
//     cout << "Observer2 state: " << observer2.getState() << endl;
// }
