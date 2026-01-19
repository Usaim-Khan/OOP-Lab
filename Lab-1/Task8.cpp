#include <iostream>
using namespace std;

int addNumbers(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    int sum = addNumbers(num1, num2);
    cout << "Sum of " << num1 << " and " << num2 << " is: " << sum << endl;
    
    return 0;
}
