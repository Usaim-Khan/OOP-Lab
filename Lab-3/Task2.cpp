#include <iostream>
using namespace std;


class Office{
    private:
        string location;
        int capacity;
        // string pointer for dma of strings
        string* furniture;
        int furnitureCount;

    public:
        //default cons
        Office(){

            location = "";
            capacity = 0;
            furniture = nullptr;
            furnitureCount = 0;
            cout << "Default Constructor called" << endl;
        }

        Office(string location, int capacity, string* furniture, int furnitureCount){
            cout << "Parameterized Constructor called" << endl;
            this->location = location;
            this->capacity = capacity;
            this->furnitureCount = furnitureCount;
            // Deep copy of furniture items
            this->furniture = new string[furnitureCount];
            for(int i = 0; i < furnitureCount; i++){
                this->furniture[i] = furniture[i];
            }
        }
        Office(const Office& obj){
            cout << "Kopi Constructor\n";
            this->location = obj.location;
            this->capacity = obj.capacity;
            this->furnitureCount = obj.furnitureCount;
            this->furniture = new string[furnitureCount];
            for (int i=0;i<furnitureCount;i++){
                this->furniture[i] = obj.furniture[i];
            }
        }
        void addFurniture(){
            string input;
            getline(cin >> ws, input);

            string* temp = new string[furnitureCount + 1];

            for (int i = 0; i < furnitureCount; i++) {
                temp[i] = furniture[i];
            }

            temp[furnitureCount] = input;

            delete[] furniture;
            furniture = temp;
            furnitureCount++;
        }

        void displayfurniture(){
            for (int i=0;i<furnitureCount;i++){
                cout << furniture[i] << endl;
            }
        }

        ~Office(){
            delete[] furniture;
            cout << "Destructor called" << endl;
        }

};


int main(){
    Office o1;
    string arr[2] = {"Chairs", "tables"};

    Office o2("Karachi",30,arr, 2);
    Office o3 = o2; // Copy constructor
    cout << "_______________________________" << endl;

    o3.addFurniture();
    o3.addFurniture();
    cout << "O2_______________________________" << endl;

    o2.displayfurniture();
    cout << "O3_______________________________" << endl;
    o3.displayfurniture();
 

}