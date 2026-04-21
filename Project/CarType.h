#ifndef CARTYPE_H
#define CARTYPE_H
#include "CustomerType.h"
#include "VehicleType.h"
#include <string>
#include <vector>

using namespace std;


class CarType : public VehicleType
{
private:
CustomerType C1;
vector<CarType> car;
vector<CarType> car_sold;
int no_of_seats;
public:
CarType();
CarType(long long int price,int model,int engineSize,string color,string vehicle_name,string fuelType,long long int price_sold,string customer_name,string contact,string CNIC,int no_of_seats);
int getseats()const;
void setseats(int no_of_seats);
void printdata(int i)const;
void add_details();
void Sale_details();
void Search();
void Account();

friend ostream& operator<<(ostream& c, const vector<CarType>& cars);
friend istream& operator>>(istream& c, vector<CarType>& cars);

};
 #endif
