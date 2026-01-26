#include <iostream>
#include <string>
using namespace std;

class BoardMarker{
    private:
        string Company;
        string Color;
        bool Refillable;
        bool InkStatus;

    public:
        string getCompany(){
            return Company;
        }
        string getColor(){
            return Color;
        }
        bool GetRefillable(){
            return Refillable;
        }
        bool GetInkStatus(){
            return InkStatus;
        }

        void setCompany(string comp){
            Company = comp;
        }
        void setColor(string clr){
            Color = clr;
        }
        void setRefillable(bool refil){
            Refillable = refil;
        }
        void setInkStatus(bool ink){
            InkStatus = ink;
        }

        void Write(){
            if (!InkStatus){
                cout << "Marker has no ink";
            } else{
                cout << "Marker is writing on board";
            }
        }
        void Refill(){
            if (Refillable){
                cout << "Marker is refilled";
            } else{
                cout << "Marker is not refillable";
            }
        }


};

int main(){

    BoardMarker marker;
    marker.setColor("Blue");
    marker.setCompany("Dollar");
    marker.setRefillable(false);
    marker.setInkStatus(true);


    cout << "Marker Company: " << marker.getCompany() << endl;
    cout << "Marker Color: " << marker.getColor() << endl;
    marker.Write();
    cout << endl;
    marker.Refill();
    cout << endl;
    return 0;


}

