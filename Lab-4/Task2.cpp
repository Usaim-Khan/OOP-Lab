#include <iostream>
#include <string>
using namespace std;


class Customer{
    private:
        int id;
        string name;
        float balance;

    public:
        Customer(){}
        Customer(int id, string name, float balance){
            createAccount(id,name,balance);

        }

        void createAccount(int id, string name, float balance){
            this->id = id;
            this->name = name;
            this->balance= balance;
            cout << "Account created for: " << name << endl;
        }

        void updateAccount(int id, string name, float balance){
            this->id = id;
            this->name = name;
            this->balance= balance;
            cout << "Account updated" << endl;

        }
        ~Customer(){
            cout << "Destructor of Customer" << endl;
        }

};

class MenuItem{
    private:
        string* name;
        string description;
        int* price;

    public:
        MenuItem(string n, string d, int p){
            name = new string(n);
            description = d;
            price = new int(p);
        }
        ~MenuItem(){
            delete name;
            delete price;
            cout << "Destructor for MenuItem" << endl;
        }
        void display() const {
            cout << "Item: " << *name << endl;
            cout << "Description: " << description << endl;
            cout << "Price: " << *price << endl;
        }

        string getName() const {
            return *name;
        }
        void setName(string n) {
            *name = n;
        }
        string getDescription() const {
            return description;
        }
        void setDescription(string d) {
            description = d;
        }
        int getPrice() const {
            return *price;
        }
        void setPrice(int p) {
            *price = p;
        }




};

int main(){
    Customer c1(1,"Usaim",1000);
    Customer c2(2,"Ali",500);

    MenuItem m1("Ice cream", "Dessert", 200);
    MenuItem m2("Pizza", "Main course", 500);
    MenuItem m3("Coke", "Beverage", 100);
    MenuItem m4("Burger", "Fast food", 300);
    MenuItem m5("Pasta", "Italian cuisine", 400);

    MenuItem array[5] = {m1,m2,m3,m4,m5};


    cout << "Item names" << endl;

    for (int i = 0; i < 4;i++){
        cout << i+1 << "- " <<array[i].getName() << endl;

    }
    int n;
    cout << "Enter choice: ";
    cin >> n;
    cout << "You chose: ";
    array[n-1].display();

    cout << "Press 9 to see special meanu item: ";
    cin >> n;
    if (n == 9){
        array[4].display();
    }

    cout << "Displaying all items:" << endl << endl ;
    for (int i =0 ;i<5; i++){
        array[i].display();
    }

}