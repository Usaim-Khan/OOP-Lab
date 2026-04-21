#ifndef BIKETYPE_H
#define BIKETYPE_H
#include "CustomerType.h"
#include "VehicleType.h"
#include <string>
#include <vector>

using namespace std;

class BikeType : public VehicleType
{
private:
CustomerType C2;
vector<BikeType> bike;
vector<BikeType> bike_sold;
public:
BikeType();
BikeType(long long int price,int model,int engineSize,string color,string vehicle_name,string fuelType,long long int price_sold,string customer_name,string contact,string CNIC);
void printdata(int i)const;
void add_details();
void Sale_details();
void Search();
void Account();

friend ostream& operator<<(ostream& c, const vector<BikeType>& bikes);
friend istream& operator>>(istream& c, vector<BikeType>& bikes);

};
#endif