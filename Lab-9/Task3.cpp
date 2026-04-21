#include <iostream>
using namespace std;


class Weapon {
protected:
    string name;
    int damage;
    float weight;

public:

    Weapon(string n, int d, float w) {
        name = n;
        damage = d;
        weight = w;
    }


    virtual void attack() = 0;
    virtual void reload() = 0;
};



class Gun : public Weapon {
public:
    Gun(string n, int d, float w) : Weapon(n, d, w) {}

    void attack() {
        cout << name << " fires a bullet causing "
             << damage << " damage.\n";
    }

    void reload() {
        cout << name << " is reloading...\n";
    }

    void shoot() {
        cout << "Gun shooting action executed.\n";
    }
};



class Sword : public Weapon {
public:
    Sword(string n, int d, float w) : Weapon(n, d, w) {}

    void attack() {
        cout << name << " slashes the enemy causing "
             << damage << " damage.\n";
    }

    void reload() {
        cout << name << " is ready again (no reload needed).\n";
    }

    void parry() {
        cout << "Sword parry move activated.\n";
    }
};



class Bow : public Weapon {
public:
    Bow(string n, int d, float w) : Weapon(n, d, w) {}

    void attack() {
        cout << name << " shoots an arrow causing "
             << damage << " damage.\n";
    }

    void reload() {
        cout << name << " is drawing another arrow.\n";
    }
};


// Main Function
int main() {

    Gun gunObj("AK-47", 50, 4.5);
    Sword swordObj("Katana", 35, 2.0);


    gunObj.attack();
    gunObj.reload();
    gunObj.shoot();

    cout << endl;


    swordObj.attack();
    swordObj.reload();
    swordObj.parry();

    return 0;
}