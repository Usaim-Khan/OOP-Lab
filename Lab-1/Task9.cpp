#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int sum = 0;
    
    cout << "Enter 5 values:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> arr[i];
        sum += arr[i];
    }
    
    cout << "\nSum of all elements: " << sum << endl;
    
    cout << "Elements in reverse order: ";
    for (int i = 4; i >= 0; i--) {
        cout << arr[i];
        if (i > 0) cout << ", ";
    }
    cout << endl;
    
    return 0;
}
