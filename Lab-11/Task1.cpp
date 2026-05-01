#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;


class Student{
public:
    string id, name;
    double gpa; 
    Student(){}
    Student(string i, string n, double g): id(i), name(n), gpa(g){}
};

void writeData(string FN, Student& s){

    ofstream file(FN, ios::binary | ios::app);
    if (!file){ return;}

    file.write((char*)&s,sizeof(Student));

    file.close();

}

void readData(string FN){
    ifstream file(FN, ios::binary);
    if (!file){ return;}


    Student s;
    while (file.read((char*)&s, sizeof(Student))) {
        cout << s.id << " " << s.name << " " << s.gpa << "\n";
    } 
    
    file.close();
    
}

int main(){

    Student s1("1001", "Ali", 2.3);
    Student s2("1002", "Ahmed", 3.5);

    string fileName = "students.bin";
    writeData(fileName, s1);
    writeData(fileName, s2);

    readData(fileName);

}
