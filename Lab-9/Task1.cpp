#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;
    string address;
    bool status; 

public:
    virtual void add_employee(Employee* e) = 0;
    virtual void display_active_employees() = 0;


    void setEmployee(int i, string n, string a, bool s) {
        id = i;
        name = n;
        address = a;
        status = s;
    }

    int getID() { return id; }
    string getName() { return name; }
    string getAddress() { return address; }
    bool getStatus() { return status; }
};


class Manager {
protected:
    string username;
    string password;

public:
    virtual bool login(string u, string p) = 0;

    void setManager(string u, string p) {
        username = u;
        password = p;
    }
};


class Inventory {
protected:
    int productID;
    string productName;
    float price;
    int quantity;

public:
    virtual float CalculateProductCost() = 0;

    void setProduct(int id, string name, float p, int q) {
        productID = id;
        productName = name;
        price = p;
        quantity = q;
    }
};


class MIS : public Employee, public Manager, public Inventory {

private:
    Employee* emp[100];
    static int count;

public:


    void add_employee(Employee* e) {
        emp[count++] = e;
    }


    void display_active_employees() {
        cout << "\nActive Employees:\n";

        for(int i = 0; i < count; i++) {
            if(emp[i]->getStatus()) {
                cout << "ID: " << emp[i]->getID() << endl;
                cout << "Name: " << emp[i]->getName() << endl;
                cout << "Address: " << emp[i]->getAddress() << endl;
                cout << "----------------------\n";
            }
        }
    }


    bool login(string u, string p) {
        if(u == username && p == password)
            return true;
        else
            return false;
    }


    float CalculateProductCost() {
        return price * quantity;
    }
};

int MIS::count = 0;

int main() {

    MIS mis;


    mis.setManager("admin", "1234");

    Employee *e1 = new MIS();
    Employee *e2 = new MIS();

    e1->setEmployee(1, "Ali", "Islamabad", true);
    e2->setEmployee(2, "Ahmed", "Lahore", false);


    mis.add_employee(e1);
    mis.add_employee(e2);


    if(mis.login("admin", "1234"))
        cout << "Login Successful\n";
    else
        cout << "Login Failed\n";


    mis.setProduct(101, "Laptop", 50000, 3);

    cout << "Total Product Cost: "
         << mis.CalculateProductCost() << endl;


    mis.display_active_employees();

    return 0;
}