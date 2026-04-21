#ifndef TRUCKTYPE_H
#define TRUCKTYPE_H
#include "CustomerType.h"
#include "VehicleType.h"
#include <string>
#include <vector>

using namespace std;

class TruckType :public VehicleType
{
private:
CustomerType C3;
vector<TruckType> truck;
vector<TruckType> truck_sold;
int weight_capacity;
public:
TruckType();
TruckType(long long int price,int model,int engineSize,string color,string vehicle_name,string fuelType,long long int price_sold,string customer_name,string contact,string CNIC,int weight_capacity);
int getweightcapacity()const;
void setweightcapacity(int weight_capacity);
void printdata(int i)const;
void add_details();
void Sale_details();
void Search();
void Account();

friend ostream& operator<<(ostream& c, const vector<TruckType>& trucks);
friend istream& operator>>(istream& c, vector<TruckType>& trucks);

};
#endif