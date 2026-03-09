#include <iostream>

using namespace std;


class Marks{
    private:
        static int TotalStudents;
        int rollNum;
        string name;
        int marks;
    public:
    Marks():rollNum(++TotalStudents),name(""),marks(0){}
    Marks(string n, int m):rollNum(++TotalStudents),name(n),marks(m){}

    void setname(string n){
        name = n;
    }
    void setmarks(int m){
        marks = m;
    }
    int getrollNum(){
        return rollNum;
    }
    string getname(){
        return name;
    }
    int getmarks(){
        return marks;
    }

};


class Physics:public Marks{
    public:
    Physics():Marks(){}
    Physics(string n, int m, int p):Marks(n,m){}
    void display(){
        cout<<"Roll Number: "<<getrollNum()<<endl;
        cout<<"Name: "<<getname()<<endl;
        cout << "Subject: Physics" << endl;
        cout<<"Marks: "<<getmarks()<<endl;
    }

};

class Chemistry:public Marks{
    public:
    Chemistry():Marks(){}
    Chemistry(string n, int m, int c):Marks(n,m){}
    void display(){
        cout<<"Roll Number: "<<getrollNum()<<endl;
        cout<<"Name: "<<getname()<<endl;
        cout << "Subject: Chemistry" << endl;
        cout<<"Marks: "<<getmarks()<<endl;
    }

};

class Mathematics:public Marks{
    public:
    Mathematics():Marks(){}
    Mathematics(string n, int m, int ma):Marks(n,m){}
    void display(){
        cout<<"Roll Number: "<<getrollNum()<<endl;
        cout<<"Name: "<<getname()<<endl;
        cout << "Subject: Mathematics" << endl;
        cout<<"Marks: "<<getmarks()<<endl;
    }

};

int Marks::TotalStudents = 0;

int main(){
    Physics p1("Alice", 85, 90);
    Chemistry c1("Bob", 78, 82);
    Mathematics m1("Charlie", 92, 95);

    cout << "Student Details:" << endl;
    cout << "----------------" << endl;
    p1.display();
    cout << "----------------" << endl;
    c1.display();
    cout << "----------------" << endl;
    m1.display();
    cout << "----------------" << endl;

    return 0;
}