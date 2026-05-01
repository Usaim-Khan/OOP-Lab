#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;



void copyFile(string org, string cpy){

    ifstream source(org);
    ofstream destination(cpy);

    if (!source or !destination){
        return;
    }

    string line;
    while (source >> line){
        destination << line << endl;
    }

    source.close();
    destination.close();
    cout << "Data is copied";

}


int main(){


    copyFile("Data.txt", "Copy.txt");

}