#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;


template <typename T>
void createFile(string fName, T data){

    ofstream file(fName, ios::app);
    if (!file){
        return;
    }

    file << data << endl;
    file.close();

}


template <typename T>
void displayFile(string fName){

    ifstream file(fName);
    if (!file){
        return;
    }

    T line;
    while (file >> line) {
        cout << line << "\n";
}

}

int main(){

    createFile("Data.txt", 1200);
    createFile("Data.txt", 1.96);
    createFile("Data.txt", 'M');
    createFile("Data.txt", "MKMK");

    
    displayFile<string>("Data.txt");


}