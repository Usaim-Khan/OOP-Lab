#include <iostream>

using namespace std;


class Animal{
    string name;
    int age;
    public:
    Animal(){
        cout << "Animal constructor called" << endl;
    }
    Animal(string n, int a){
        name = n;
        age = a;
        cout << "Animal constructor called" << endl;
    }

    void set_name(string n){
        name = n;
    }

    void set_age(int a){
        age = a;
    }

    string get_name(){
        return name;
    }
    int get_age(){
        return age;
    }

    void eat(){
        cout << name << " is eating" << endl;
    }

    void sleep(){
        cout << name << " is sleeping" << endl;
    }
};


class Mammal: virtual public Animal{
    private:
        string furColor;

    public:
        Mammal(){

            cout << "Mammal constructor called" << endl;
        }
        Mammal(string n, int a){
            set_name(n);
            set_age(a);
            cout << "Mammal constructor called" << endl;
        }

        void set_furColor(string color){
            furColor = color;
        }
        string get_furColor(){
            return furColor;
        }

        void give_birth(){
            cout << get_name() << " gave birth" << endl;
        }



};

class Bird: virtual public Animal{
    private:
        float wingSpan;

    public:
        Bird(){
            cout << "Bird constructor called" << endl;
        }
        Bird(string n, int a){
            set_name(n);
            set_age(a);
            cout << "Bird constructor called" << endl;
        }

        void set_wingSpan(float ws){
            wingSpan = ws;
        }
        float get_wingSpan(){
            return wingSpan;
        }

        void layEggs(){
            cout << get_name() << " laid eggs" << endl;
        }

};

// Bat: Inherits from both Mammal and Bird, with an additional property
// echolocationCapability and method fly().

class Bat: public Mammal, public Bird{
    private:
        bool echolocationCapability;

    public:
        Bat(){
            cout << "Bat constructor called" << endl;
        }
        Bat(string n, int a){
            set_name(n);
            set_age(a);
            cout << "Bat constructor called" << endl;
        }

        void set_echolocationCapability(bool capability){
            echolocationCapability = capability;
        }
        bool get_echolocationCapability(){
            return echolocationCapability;
        }

        void fly(){
            cout << get_name() << " is flying" << endl;
        }

};

class Reptile{
    string name;
    int age;
    public:
    Reptile(){
        cout << "Reptile constructor called" << endl;
    }
    Reptile(string n, int a){
        name = n;
        age = a;
        cout << "Reptile constructor called" << endl;
    }

};



class Snake: public Reptile, public Animal{
    private:
        bool venomous;

    public:
        Snake(){
            cout << "Snake constructor called" << endl;
        }
        Snake(string n, int a){
            set_name(n);
            set_age(a);
            cout << "Snake constructor called" << endl;
        }

        void set_venomous(bool v){
            venomous = v;
        }
        bool get_venomous(){
            return venomous;
        }

        void shedSkin(){
            cout << get_name() << " is shedding skin" << endl;
        }

};

// Sparrow: A simple class inheriting from Bird. Penguin: Another class inheriting
// from Bird.

class Sparrow: public Bird{
    public:
        Sparrow(){
            cout << "Sparrow constructor called" << endl;
        }
        Sparrow(string n, int a){
            set_name(n);
            set_age(a);
            cout << "Sparrow constructor called" << endl;
        }

        void make_sound(){
            cout << get_name() << " makes a sound" << endl;
        }

};

class Penguin: public Bird{
    public:
        Penguin(){
            cout << "Penguin constructor called" << endl;
        }
        Penguin(string n, int a){
            set_name(n);
            set_age(a);
            cout << "Penguin constructor called" << endl;
        }

        void make_sound(){
            cout << get_name() << " makes a sound" << endl;
        }

};

int main(){

    Bat b("Bruce", 5);
    b.set_furColor("Black");
    b.set_wingSpan(1.5);
    b.set_echolocationCapability(true);

    cout << "Bat Name: " << b.get_name() << endl;
    cout << "Bat Age: " << b.get_age() << endl;
    cout << "Bat Fur Color: " << b.get_furColor() << endl;
    cout << "Bat Wing Span: " << b.get_wingSpan() << " meters" << endl;
    cout << "Bat Echolocation Capability: " << (b.get_echolocationCapability() ? "Yes" : "No") << endl;

    b.eat();
    b.sleep();
    b.fly();
    b.give_birth();

    Snake s("Slytherin", 3);
    s.set_venomous(true);

    cout << "\nSnake Name: " << s.get_name() << endl;
    cout << "Snake Age: " << s.get_age() << endl;
    cout << "Snake Venomous: " << (s.get_venomous() ? "Yes" : "No") << endl;

    s.eat();
    s.sleep();
    s.shedSkin();

}