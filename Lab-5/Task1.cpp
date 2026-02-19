#include <iostream>
using namespace std;

class Square{
    private:
        float length, area;
        static float allAreas;

    public:
        Square(){length = 0;}
        Square(float l):length(l){}

        float calculateArea(){
            allAreas += length*length;
            return length*length;
        }

        void setLength(float l){
            length = l;
        }
        float getLength(){
            return length;
        }
        static float getAllAreas(){
            return allAreas;
        }

};  
float Square::allAreas = 0.0;

int main(){

    Square s1(2.0), s2(3.0), s3(4.0);

    cout << "Square 1 Area: " << s1.calculateArea() << endl;
    cout << "Total Area after Square 1: " << Square::getAllAreas() << endl;

    cout << "Square 2 Area: " << s2.calculateArea() << endl;
    cout << "Total Area after Square 2: " << Square::getAllAreas() << endl;

    cout << "Square 3 Area: " << s3.calculateArea() << endl;
    cout << "Total Area after Square 3: " << Square::getAllAreas() << endl;


}