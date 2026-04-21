#ifndef VEHICLETYPE_H
#define VEHICLETYPE_H
#include <string>
using namespace std;
class VehicleType
{
private:
long long int price;
int model;
string vehicle_name;
string color;
int engineSize;
string fuelType;
long long int price_sold;
static int count;

public:
VehicleType();
VehicleType(long long int price,int model,int engineSize,string color,string vehicle_name,string fuelType,long long int price_sold);
void setvehiclename(string vehicle_name);
void setprice(long long int price);
void setprice_sold(long long int price_sold);
void setmodel(int model);
void setengineSize(int engineSize);
void setcolor(string color);
void setfuelType(string fuelType);
long long int getprice()const;
long long int getprice_sold()const;
int getmodel()const;
int getengineSize()const;
string getcolor()const;
string getvehiclename()const;
string getfuelType()const;
virtual void printdata(int i)const=0;
virtual void add_details()=0;
virtual void Sale_details()=0;
virtual void Search()=0;
virtual void Account()=0;
static int increment();
};
#endif