#include <iostream>
using namespace std;

class Customer{
    private:
        string name, phoneNumber;

    public:
        Customer(string n, string num){
            name = n;
            phoneNumber = num;
        
        }
        Customer(){
            name= "";
            phoneNumber = "";
        }

        void setName(string n){
            name = n;
        }
        void setPhoneNumber(string num){
            phoneNumber = num;
        }
        string getName(){
            return name;
        }
        string getPhoneNumber(){
            return phoneNumber;
        }
        void display(){
            cout << "Name: " << name << endl;
            cout << "Phone Number: " << phoneNumber << endl;
        }



};

class BankAccount{
    private:
        int accNum;
        float balance;
        Customer* accHolder;
    public:
        BankAccount(int a, float b, Customer* ptr):accNum(a),balance(b){
            accHolder = ptr;
        }
        
        void Deposit(double m){
            balance +=m;
            cout << "Money deposited " << endl;
        }

        void withdraw(double m){
            if (balance<m){
                cout << "Balance is less than withdraw amount" << endl;
                return;
            }
            balance-=m;
            cout << "Money withdrawn " << endl;
        }
        void display(){
            cout << "Account Number: " << accNum << endl;
            cout << "Balance: " << balance << endl;
            cout << "Account Holder: " << endl;
            accHolder->display();
        }

};

int main(){


    Customer c1("John Doe", "123-456-7890");
    Customer c2("Jane Smith", "987-654-3210");
    Customer c3("Alice Johnson", "555-123-4567");

    BankAccount accounts[3] = {
        BankAccount(1001, 5000.0, &c1),
        BankAccount(1002, 3000.0, &c2),
        BankAccount(1003, 7000.0, &c3)
    };

    for (int i = 0; i < 3; i++) {
        cout << "Account " << i + 1 << ":" << endl;
        accounts[i].display();
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        cout << "Depositing 500 into Account " << i + 1 << endl;
        accounts[i].Deposit(500.0);
        cout << "Withdrawing 200 from Account " << i + 1 << endl;
        accounts[i].withdraw(200.0);
        cout << endl;
    }

    cout << "Updated Account Details:" << endl;
    for(int i =0; i<3; i++){
        cout << "Account " << i + 1 << ":" << endl;
        accounts[i].display();
        cout << endl;
    }

}