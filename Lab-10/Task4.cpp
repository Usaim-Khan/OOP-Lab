#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    double balance = 10000.0; // predefined account balance
    double amount;

    cout << "Current Balance: " << balance << endl;
    cout << "Enter payment amount: ";

    try {
        // Check for non-numeric input
        if (!(cin >> amount)) {
            throw invalid_argument("Invalid input! Please enter a numeric value.");
        }

        // Negative amount check
        if (amount < 0) {
            throw runtime_error("Payment amount cannot be negative.");
        }

        // Exceeds balance check
        if (amount > balance) {
            throw out_of_range("Insufficient balance for this payment.");
        }

        // If all checks pass
        balance -= amount;
        cout << "Payment successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }

    // Multiple catch blocks
    catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown error occurred." << endl;
    }

    return 0;
}
