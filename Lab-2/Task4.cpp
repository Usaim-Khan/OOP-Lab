#include <iostream>
#include <string>
using namespace std;

class SmartPhone{
    private:
        string Company;
        string Model;
        string DisplayResolution;
        int RAM;
        int ROM;
        int Storage;

    public:
        void setCompany(string comp){
            Company = comp;
        }
        string getCompany(){
            return Company;
        }

        void setModel(string mod){
            Model = mod;
        }
        string getModel(){
            return Model;
        }

        void setDisplayResolution(string res){
            DisplayResolution = res;
        }
        string getDisplayResolution(){
            return DisplayResolution;
        }

        void setRAM(int ram){
            RAM = ram;
        }
        int getRAM(){
            return RAM;
        }

        void setROM(int rom){
            ROM = rom;
        }
        int getROM(){
            return ROM;
        }

        void setStorage(int storage){
            Storage = storage;
        }
        int getStorage(){
            return Storage;
        }

        void MakePhoneCall(){
            cout << "making a phone call" << endl;
        }
        void SendMessage(){
            cout << "Sending message" << endl;
        }
        void ConnectToWifi(){
            cout << "Connecting to wifi network: " << endl;
        }
        void BrowseInternet(){
            cout << "Browsing the internet " << endl;
        }

};


int main(){

    SmartPhone phone;
    phone.setCompany("Samsung");
    phone.setModel("Galaxy S21");
    phone.setDisplayResolution("3200x1440");
    phone.setRAM(8);
    phone.setROM(256);
    phone.setStorage(512);

    cout << "Phone Company: " << phone.getCompany() << endl;
    cout << "Phone Model: " << phone.getModel() << endl;
    cout << "Display Resolution: " << phone.getDisplayResolution() << endl;
    cout << "RAM: " << phone.getRAM() << " GB" << endl;
    cout << "ROM: " << phone.getROM() << " GB" << endl;
    cout << "Storage: " << phone.getStorage() << " GB" << endl;

    phone.MakePhoneCall();
    phone.SendMessage();
    phone.ConnectToWifi();
    phone.BrowseInternet();

    return 0;

}