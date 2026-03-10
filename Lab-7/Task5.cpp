#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void startEngine() {
        cout << "Vehicle engine starting..." << endl;
    }

    virtual void stopEngine() {
        cout << "Vehicle engine stopping..." << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void startEngine() override {
        cout << "Car engine starts with ignition key." << endl;
    }

    void stopEngine() override {
        cout << "Car engine stops when key is turned off." << endl;
    }
};

class Motorcycle : public Vehicle {
public:
    void startEngine() override {
        cout << "Motorcycle engine starts with electric starter." << endl;
    }

    void stopEngine() override {
        cout << "Motorcycle engine stops with kill switch." << endl;
    }
};

class HybridCar : public Vehicle {
public:
    void startEngine() override {
        cout << "HybridCar starts using electric motor and gasoline engine." << endl;
    }

    void stopEngine() override {
        cout << "HybridCar shuts down electric system and fuel engine." << endl;
    }
};

class Hoverbike : public Vehicle {
public:
    void startEngine() override {
        cout << "Hoverbike activates anti-gravity propulsion system." << endl;
    }

    void stopEngine() override {
        cout << "Hoverbike deactivates hover propulsion and lands safely." << endl;
    }
};

int main() {

    Vehicle* vehicles[4];

    vehicles[0] = new Car();
    vehicles[1] = new Motorcycle();
    vehicles[2] = new HybridCar();
    vehicles[3] = new Hoverbike();

    for(int i = 0; i < 4; i++) {
        vehicles[i]->startEngine();
        vehicles[i]->stopEngine();
        cout << endl;
    }


    for(int i = 0; i < 4; i++) {
        delete vehicles[i];
    }

    return 0;
}