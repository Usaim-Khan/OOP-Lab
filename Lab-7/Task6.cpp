#include <iostream>
using namespace std;

class Animal {
public:
    virtual void move() {
        cout << "Animal moves in a general way." << endl;
    }

    virtual void makeSound() {
        cout << "Animal makes a generic sound." << endl;
    }

    virtual ~Animal() {}
};

class Bird : public Animal {
public:
    void move() override {
        cout << "Bird flies through the sky." << endl;
    }

    void makeSound() override {
        cout << "Bird chirps." << endl;
    }
};

class Panthera : public Animal {
public:
    void move() override {
        cout << "Panthera walks stealthily on the ground." << endl;
    }

    void makeSound() override {
        cout << "Panthera roars loudly." << endl;
    }
};

int main() {

    Animal* animals[2];

    animals[0] = new Bird();
    animals[1] = new Panthera();

    for(int i = 0; i < 2; i++) {
        animals[i]->move();
        animals[i]->makeSound();
        cout << endl;
    }

    for(int i = 0; i < 2; i++) {
        delete animals[i];
    }

    return 0;
}