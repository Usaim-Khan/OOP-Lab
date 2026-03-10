#include <iostream>

using namespace std;


class Product{
    protected:
        double price;

    private:
        string name;

    public:
        Product():name(""),price(0.0){}
        Product(string n, double p): name(n), price(p){}

        virtual double getPrice(){
            return price;
        }

};

class TV: public Product{
    private:
        double screenSize;
        int resolution;

    public:
        TV(double s, int r, double p): screenSize(s), resolution(r), Product("", p) {}
        double getPrice(){
            return 1.05*price;
        }

};

class Laptop: public Product{
    private:
        double processingPower;
        int memory;

    public:
        Laptop(double p, int m, double pr): processingPower(p), memory(m), Product("", pr) {}

        double getPrice(){
            return 1.1*price;
        }


};

class SmartPhone: public Product{
    private:
        double screenSize;
        int cameraResolution;

    public:
        SmartPhone(double s, int r, double p): screenSize(s), cameraResolution(r), Product("", p) {}

        double getPrice(){
            return (screenSize+ cameraResolution) *0.05;
        }

};

int main(){
    Product *ptr;

    TV tv(55, 4, 1000);
    Laptop laptop(3.5, 16, 1000);
    SmartPhone phone(65000, 1200, 1000);

    ptr = &tv;
    cout << "TV price: " << ptr->getPrice() << endl;

    ptr = &laptop;
    cout << "Laptop price: " << ptr->getPrice() << endl;

    ptr = &phone;
    cout << "SmartPhone price: " << ptr->getPrice() << endl;

    return 0;
}