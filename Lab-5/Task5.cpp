#include <iostream>
using namespace std;

class Engine{
    private:
        string type;
        int hp;

    public:
        Engine(string t, int h){
            type = t;
            hp = h;
        }
        Engine(){
            type = "";
            hp = 0;
        }
        void setType(string t){
            type = t;
        }
        void setHp(int h){
            hp = h;
        }
        string getType(){
            return type;
        }
        int getHp(){
            return hp;
        }
        void display(){
            cout << "Engine Type: " << type << endl;
            cout << "Horse Power: " << hp << endl;
        }


};
class Wheel{
    private:
        int size;

    public:
        Wheel(int s){
            size = s;
        }
        Wheel(){
            size = 0;
        }
        void setSize(int s){
            size = s;
        }
        int getSize(){
            return size;
        }
        void display(){
            cout << "Wheel Size: " << size << endl;
        }

};
class Headlight{
    private:
        string type;
    public:
        Headlight(string t){
            type = t;
        }
        Headlight(){
            type = "";
        }
        void setType(string t){
            type = t;
        }
        string getType(){
            return type;
        }
        void display(){
            cout << "Headlight Type: " << type << endl;
        }

};
class Steering{
    private:
        string type;

    public:
        Steering(string t){
            type = t;
        }
        Steering(){
            type = "";
        }
        void setType(string t){
            type = t;
        }
        string getType(){
            return type;
        }
        void display(){
            cout << "Steering Type: " << type << endl;
        }

};


class Car{
    private:
        Engine engine;
        Wheel wheels[4];
        Headlight headlights[2];
        Steering steering;
        string* GPS;

    public:
        Car(Engine e, Wheel w[4], Headlight h[2], Steering s, string* gps):engine(e),steering(s){
            for (int i = 0; i < 4; i++){
                wheels[i] = w[i];
            }
            for (int i = 0; i < 2; i++){
                headlights[i] = h[i];
            }
            GPS = gps;
        }


        void setGPS(string* ptr){
            GPS = ptr;
        }

        void display(){
            cout << "Car Details: " << endl;
            engine.display();
            for (int i = 0; i < 4; i++){
                wheels[i].display();
            }
            for (int i = 0; i < 2; i++){
                headlights[i].display();
            }
            steering.display();
            cout << "GPS: " << *GPS << endl;
        }


};

int main(){
    Engine e("V8", 500);
    Wheel w[4] = {Wheel(18), Wheel(18), Wheel(18), Wheel(18)};
    Headlight h[2] = {Headlight("LED"), Headlight("LED")};
    Steering s("Power");
    string gps = "Google Maps";

    Car car(e, w, h, s, &gps);
    car.display();


}