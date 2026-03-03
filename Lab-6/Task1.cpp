#include <iostream>

using namespace std;

class Mammal{

    public:
    Mammal(){
        cout << "Mammal constructor called" << endl;
    }

    void mammal_func(){
        cout << "I am mammal" << endl;
    }

    ~Mammal(){
        cout << "Mammal destructor called" << endl;
    }

};

class MarineAnimals{

    public:
    MarineAnimals(){
        cout << "MarineAnimals constructor called" << endl;
    }
    void marine_func(){
        cout << "I am a marine animal" << endl;
    }

    ~MarineAnimals(){
        cout << "MarineAnimals destructor called" << endl;
    }

};


class BlueWhale: public Mammal, public MarineAnimals{

    public:
    BlueWhale(){
        cout << "BlueWhale constructor called" << endl;
    }
    void blue_whale_func(){
        cout << "I belong to both the categories: Mammals as well as Marine Animals" << endl;
    }

    ~BlueWhale(){
        cout << "BlueWhale destructor called" << endl;
    }
};


int main(){
    Mammal m;
    MarineAnimals ma;
    BlueWhale bw;

    m.mammal_func();
    ma.marine_func();
    bw.blue_whale_func();
    bw.mammal_func();
    bw.marine_func();
}