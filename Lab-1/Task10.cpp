#include <iostream>
using namespace std;

int main() {
    int arr[3][3];
    
    cout << "Enter elements of 3x3 array:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    
    cout << "\nSum of each row:" << endl;
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << (i + 1) << " sum: " << rowSum << endl;
    }
    
    return 0;
}
