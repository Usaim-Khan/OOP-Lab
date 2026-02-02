#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class IceCreamManagement{
    int ID, flavour_code;
    string name, description;
    double price;

    public:
        IceCreamManagement(){
            cout<<"Default Constructor called"<<endl;
            srand(time(0));
            ID = 0;
            flavour_code = rand() % 1000 +1;
            name = "";
            description = "";
            price = 0;

        }

        IceCreamManagement(int ID, int flavour_code, string name, string description, double price){
            cout<<"Parameterized Constructor called"<<endl;
            this->ID = ID;
            this->flavour_code = flavour_code;
            this->name = name;
            this->description = description;
            this->price = price;

        }

        IceCreamManagement(const IceCreamManagement& obj){
            cout<<"Copy Constructor called"<<endl;
            this->ID = obj.ID;
            this->flavour_code = obj.flavour_code;
            this->name = obj.name;
            this->description = obj.description;
            this->price = obj.price;
        }

        void display(){
            cout<<"ID: "<<ID<<endl;
            cout<<"Flavour Code: "<<flavour_code<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Description: "<<description<<endl;
            cout<<"Price: "<<price<<endl;
        }

        void setPrice(double newPrice){
            price = newPrice;
        }
        void setDescription(string newDescription){
            description = newDescription;
        }

        void setflavour_code(){
            srand(time(0));
            flavour_code = rand() % 1000 +1;
        }
};

int main(){
    IceCreamManagement i1;
    IceCreamManagement i2(1, 101, "Vanilla", "Classic vanilla flavor", 250);
    IceCreamManagement i3 = i2;
    i3.setPrice(300);
    i3.setDescription("creamy vanilla flavor");
    i3.setflavour_code();
    cout<<"Ice Cream 2: "<<endl;
    i2.display();
    cout<<"Ice Cream 3: "<<endl;
    i3.display();
}