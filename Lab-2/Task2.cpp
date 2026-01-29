#include <iostream>
using namespace std;


class WaterBottle{
    private:
        string company;
        string color;
        string capacity;
        int litres;
        int millilitres;

    public:
        void setCompany(string comp){
            company = comp;
        }
        string getCompany(){
            return company;
        }
        void setColor(string clr){
            color = clr;
        }
        string getColor(){
            return color;
        }
        void setCapacity(string cap){
            capacity = cap;
        }
        string getCapacity(){
            return capacity;
        }
        void setLitres(int lit){
            litres = lit;
        }
        int getLitres(){
            return litres;
        }
        void setMillilitres(int ml){
            millilitres = ml;
        }
        int getMillilitres(){
            return millilitres;
        }
        void updateVolume(int ml){
            millilitres -= ml;
            litres = millilitres / 1000;


        }


};

int main(){

    WaterBottle bottle;
    bottle.setCompany("Aquafina");
    bottle.setColor("Blue");
    bottle.setCapacity("1000ml");
    bottle.setLitres(0.5);
    bottle.setMillilitres(500);
    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Capacity: " << bottle.getCapacity() << endl;
    cout << "Litres: " << bottle.getLitres() << " l" << endl;
    cout << "Millilitres: " << bottle.getMillilitres() << " ml" << endl;
    int drank;
    cout << "Enter amount of water drank (in ml): ";
    cin >> drank;
    bottle.updateVolume(drank);
    cout << "Updated Millilitres: " << bottle.getMillilitres() << " ml" << endl;
    cout << "Updated Litres: " << bottle.getLitres() << " l" << endl;



}