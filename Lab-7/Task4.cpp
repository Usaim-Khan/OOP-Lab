#include <iostream>
using namespace std;

class Enemy {
public:
    virtual void attack() {
        cout << "Enemy attacks!" << endl;
    }
};

class Dragon : public Enemy {
public:
    void attack() override {
        cout << "Dragon breathes fire!" << endl;
    }
};

class Goblin : public Enemy {
public:
    void attack() override {
        cout << "Goblin attacks with a dagger!" << endl;
    }
};

class Troll : public Enemy {
public:
    void attack() override {
        cout << "Troll swings a giant club!" << endl;
    }
};

int main() {

    Enemy* enemies[3];

    enemies[0] = new Dragon();
    enemies[1] = new Goblin();
    enemies[2] = new Troll();

    for(int i = 0; i < 3; i++) {
        enemies[i]->attack();
    }

    for(int i = 0; i < 3; i++) {
        delete enemies[i];
    }

    return 0;
}