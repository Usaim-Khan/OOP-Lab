#include <iostream>
using namespace std;


class Vehicle {
protected:
    float cost;   

public:
    Vehicle() {
        cost = 1000;   
    }


    virtual void details() = 0;
    virtual float CostNet(float tax) = 0;
};



class Car : public Vehicle {
private:
    int numDoors;

public:


    Car(int doors) {
        numDoors = doors;
    }


    void details() {
        cout << "Vehicle Type: Car" << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Base Rental Cost: " << cost << endl;
    }


    float CostNet(float tax) {
        float totalCost = cost * (1.0 + tax);
        return totalCost;
    }
};



int main() {

    Car c(4);  

    float tax = 0.10;   

    c.details();

    cout << "Total Cost with Tax: "
         << c.CostNet(tax) << endl;

    return 0;
}