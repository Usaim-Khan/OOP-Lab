#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class BankAccount{
    int ID;
    double balance;
    int* transactions;
    int numTrans;

    public:
    BankAccount(int ID, double balance, int* transactions, int numTrans){
        cout << "Parameterized Constructor" << endl;
        this->ID = ID;
        this->balance = balance;
        this->numTrans = numTrans; 
        this->transactions = new int[numTrans];
        for (int i =0; i<numTrans;i++){
            this->transactions[i] = transactions[i];
        }
    }

    BankAccount(const BankAccount& obj){
        cout << "Copy Constructor" << endl;
        this->ID = obj.ID;
        this->balance = obj.balance;
        this->numTrans = obj.numTrans;
        this->transactions = new int[numTrans];
        for (int i =0; i<numTrans;i++){
            this->transactions[i] = obj.transactions[i];
        }

    }

    ~BankAccount(){
        delete[] transactions;
    }
    void display(){
        cout<<"ID: "<<ID<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Transactions: ";
        for (int i=0;i<numTrans;i++){
            cout<<transactions[i]<<" ";
        }
        cout<<endl;        
    }

    void makeTransaction(int amount){
        int* temp = new int[numTrans+1];
        for (int i = 0;i<numTrans;i++){
            temp[i] = transactions[i];
        }
        temp[numTrans] = amount;
        numTrans++;
        delete[] transactions;
        transactions = temp;
        balance += amount;

    }


};

int main(){
    int t[3] = {200,-600,500};
    BankAccount a1(101,5000,t,3);
    BankAccount a2 = a1;

    a2.makeTransaction(-1500);
    a2.makeTransaction(2500);

    cout << "Account 1 details: "<<endl;
    a1.display();

    cout << endl<<  "Account 2 details: "<<endl;
    a2.display();
}
