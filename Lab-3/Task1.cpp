#include <iostream>
using namespace std;


class Product{
    private:
        string name;
        string description;
        double cost;
        int barcode;
        int total_stock, items_sold;

    public:
        Product(){
            cout << "Default Constructor called" << endl;
            name = "";
            description = "";
            cost = 0.0;
            barcode = 0;
            total_stock = 0;
            items_sold = 0;
        }

        Product(string name, string description, double cost, int barcode, int total_stock, int items_sold){
            cout << "Parameterized Constructor called" << endl;
            this->name = name;
            this->description = description;
            this->cost = cost;
            this->barcode = barcode;
            this->total_stock = total_stock;
            this->items_sold = items_sold;

        }

        Product(const Product& obj){
            cout << "Copy constructor called" << endl;
            if (this != &obj){
                name = obj.name;
                description = obj.description;
                cost = obj.cost;
                barcode = obj.barcode;
                total_stock = obj.total_stock;
                items_sold = obj.items_sold;
            }
        }
        int sellItem(){
            printf("Item sold");
            total_stock--;
            items_sold++;
        }
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Description: "<<description<<endl;
            cout<<"Cost: "<<cost<<endl;
            cout<<"Barcode: "<<barcode<<endl;
            cout<<"Total Stock: "<<total_stock<<endl;
            cout<<"Items Sold: "<<items_sold<<endl;
        }

};

int main(){
    Product p1;
    Product p2("Mobile","Electronic Gadget", 61000,783621,30,0);
    Product p3 = p2;

    p2.sellItem();
    p2.sellItem();
    cout<< "\nProduct1"<<endl;
    p1.display();

    cout<< "\nProduct2"<<endl;
    p2.display();

    cout<< "\nProduct3"<<endl;
    p3.display();



}