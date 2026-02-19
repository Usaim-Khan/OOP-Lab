#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class ValidateString {
private:
    string str;

public:

    ValidateString(string input) {
        str = input;
    }

    // We make this function const because it does not modify any member variables.
    // A const function promises to the compiler and to other programmers that this
    // function will not change the state of the object. This allows const objects
    // to call this function and prevents accidental modifications. If we don't make
    // it const, we won't be able to call this function on const objects.
    
    bool isValid() const {

        if (str.length() == 0) {
            return false;
        }

        for (int i = 0; i < str.length(); i++) {
            if (!isalpha(str[i])) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    ValidateString obj1("Hello");     
    ValidateString obj2("World123");   
    ValidateString obj3("Test!");      
    ValidateString obj4("Programming"); 
    ValidateString obj5("Data2024");   

    cout << "String 'Hello': " << obj1.isValid() << endl;
    cout << "String 'World123': " << obj2.isValid() << endl;
    cout << "String 'Test!': " << obj3.isValid() << endl;
    cout << "String 'Programming': " << obj4.isValid() << endl;
    cout << "String 'Data2024': " << obj5.isValid() << endl;

    return 0;
}
