#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


class Appointment{
    string name, date;
    double cost;
    string* services;
    int numServices = 0;

    public:
        Appointment(){
            name = "";
            date = "";
            cost = 0;
            services = nullptr;
            int numServices = 0;
        }

        Appointment(string name, string date, double cost, string* services, int numServices){
            this->name = name;
            this->date = date;
            this->cost = cost;
            this->numServices = numServices;
            this->services = new string[numServices];
            for (int i = 0 ; i<numServices; i++){
                this->services[i] = services[i];
            }
        }

        Appointment(const Appointment& obj){
            this->name = obj.name;
            this->date = obj.date;
            this->cost = obj.cost;
            this->numServices = obj.numServices;
            this->services = new string[numServices];
            for (int i = 0; i< numServices;i++){
                this->services[i] = obj.services[i];
            }

        }
        ~Appointment(){
            delete[] services;
        }

        void display(){
            cout << "Name: " << name << endl;
            cout << "Date: " << date << endl;
            cout << "Cost: " << cost << endl;
            cout << "Services: ";
            for (int i=0;i<numServices;i++){
                cout << services[i] << ", ";
            }
        }

        void addService(string s){
            string* temp = new string[numServices+1];
            for (int i =0; i< numServices;i++){
                temp[i] = services[i];
            }
            delete[] services;
            services = temp;
            services[numServices] = s;
            numServices++;
            cost+=500; 

        }


};

int main(){
    string ser[3] = {"Massage", "Haircut", "Shave"}; 
    Appointment a1("Usaim","16-8-2015",3000,ser,3);

    Appointment a2 = a1;
    a1.addService("Waxing");

    cout << "Appointment1: "<< endl;
    a1.display();
    cout <<endl << "Appointment2: "<< endl;
    a2.display();


}