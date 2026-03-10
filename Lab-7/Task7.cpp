#include <iostream>
using namespace std;

class Shape {
public:
    void calculateArea() {
        cout << "Calculating area of Shape" << endl;
    }
};

class Rectangle : public Shape {
public:
    void calculateArea() {
        cout << "Calculating area of Rectangle" << endl;
    }
};

int main() {

    Shape* s;
    Rectangle r;

    s = &r;

    s->calculateArea(); 

    return 0;
}