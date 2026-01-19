#include <iostream>
using namespace std;

int main() {
    int intVar;
    float floatVar;
    double doubleVar;
    char charVar;
    bool boolVar;
    
    cout << "Enter an integer: ";
    cin >> intVar;
    
    cout << "Enter a float: ";
    cin >> floatVar;
    
    cout << "Enter a double: ";
    cin >> doubleVar;
    
    cout << "Enter a character: ";
    cin >> charVar;
    
    cout << "Enter a boolean (0 or 1): ";
    cin >> boolVar;
    
    cout << "\nValues entered:" << endl;
    cout << "Integer: " << intVar << endl;
    cout << "Float: " << floatVar << endl;
    cout << "Double: " << doubleVar << endl;
    cout << "Character: " << charVar << endl;
    cout << "Boolean: " << boolVar << endl;
    
    return 0;
}
