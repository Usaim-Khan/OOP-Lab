#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;




int main(){
    string fN = "seek.txt";
    fstream file (fN, ios::in | ios::out | ios::trunc);

    if (!file){
        return 1;
    }


    file << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    file.seekg(0);
    string orginal;
    file >> orginal;
    cout << "Original content: " << orginal << endl;

    file.clear();
    file.seekp(10);

    file << "12345";



    file.seekg(-5, ios::end);

    char line[50];

    file.getline(line, 50);
    cout << "Last 5 characters: " <<line << endl;

    file.clear();
    file.seekg(0);
    string upd;
    file >> upd;
    cout << "Updated content: " << upd;

    file.close();


}