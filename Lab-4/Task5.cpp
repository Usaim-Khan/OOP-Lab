#include <iostream>
using namespace std;


class BankAccount{
    private:
        int accNum;
        string accname;
        double balance;
        const double minBalance;


    public:
        static int TotalAccounts;

        BankAccount(): minBalance(1000) {}
        BankAccount(int num, string n, double bal):minBalance(1000){
            if (bal < minBalance){
                cout << "Initial balance is less than minimum balance. account not created." << endl;
                accNum = 0;
                accname = "";
                balance = 0;
            } else {
                accNum = num;
                accname = n;
                balance = bal;
                TotalAccounts++;
            }

        }
        


        ~BankAccount(){
            cout << "Destructor for Account" << endl;
        }

        void display() const {
            cout << "Account Number: " << accNum << endl;
            cout << "Account Name: " << accname << endl;
            cout << "Balance: " << balance << endl;
            cout << "---------------------------" << endl;
        }




};

int BankAccount::TotalAccounts = 0;

int main(){
    BankAccount accounts[3] = {
        BankAccount(101, "Alice", 1500),
        BankAccount(102, "Bob", 1000),
        BankAccount(103, "Charlie", 2000)
    };

    for (int i = 0; i < 3; i++) {
        accounts[i].display();
    }

    BankAccount acc4(104, "David", 900);
    BankAccount acc5(105, "Eve", 1200);

    acc4.display();
    acc5.display();
    cout << "Total Accounts Created: " << BankAccount::TotalAccounts << endl;

    return 0;

}

