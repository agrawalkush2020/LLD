#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ---------------- Observer Interface ----------------
class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() {}
};

// ---------------- Subject Interface ----------------
class Subject {
public:
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notifyObservers(const string& message) = 0;
    virtual ~Subject() {}
};

// ---------------- Concrete Observer ----------------
class Subscriber : public Observer {
private:
    string name;
public:
    Subscriber(const string& name) : name(name) {}

    void update(const string& message) override {
        cout << name << " got notification: " << message << endl;
    }
};

// ---------------- Concrete Subject ----------------
class YouTubeChannel : public Subject {
private:
    vector<Observer*> subscribers;

public:
    void subscribe(Observer* o) override {
        subscribers.push_back(o);
    }

    void unsubscribe(Observer* o) override {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), o), subscribers.end());
    }

    void notifyObservers(const string& message) override {
        for (Observer* o : subscribers) {
            o->update(message);
        }
    }

    void uploadVideo(const string& title) {
        cout << "\nChannel: Uploaded video - " << title << endl;
        notifyObservers("New video uploaded: " + title);
    }
};

// ---------------- Main ----------------
int main() {
    YouTubeChannel channel;

    Subscriber kush("Kush");
    Subscriber rahul("Rahul");
    Subscriber priya("Priya");

    channel.subscribe(&kush);
    channel.subscribe(&rahul);

    channel.uploadVideo("Observer Pattern in C++");

    channel.unsubscribe(&rahul);
    channel.subscribe(&priya);

    channel.uploadVideo("Strategy Pattern Explained");

    return 0;
}
