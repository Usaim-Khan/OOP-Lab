#include <iostream>
#include <iomanip>
using namespace std;

class LoanHelper {
private:
    const double INTEREST_RATE = 0.003;
    double loanAmount;
    int months;

public:
    LoanHelper(double amount, int monthCount) {
        loanAmount = amount;
        months = monthCount;
    }

    void displayMonthlyPayment() {
        double basePayment = loanAmount / months;
        
        double monthlyPayment = basePayment * (1 + INTEREST_RATE);
        
        cout << "You have to pay " << fixed << setprecision(2) << monthlyPayment 
             << " every month for " << months << " months to repay your loan" << endl;
    }

    double getInterestRate() const {
        return INTEREST_RATE;
    }

    double getLoanAmount() const {
        return loanAmount;
    }

    int getMonths() const {
        return months;
    }
};

int main() {
    LoanHelper loan(10000, 12);
    loan.displayMonthlyPayment();

    LoanHelper loan2(5000, 24);
    loan2.displayMonthlyPayment();

    return 0;
}
