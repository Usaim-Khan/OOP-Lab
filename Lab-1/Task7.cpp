#include <iostream>
using namespace std;

void square(int num) {
    cout << "Square of " << num << " is: " << (num * num) << endl;
}

int main() {
    int input;
    cout << "Enter an integer: ";
    cin >> input;
    
    square(input);
    
    return 0;
}
