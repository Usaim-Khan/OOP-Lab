#include<iostream>
#include<string>
#include "VehicleType.h"

using namespace std;
int VehicleType:: count=0;

VehicleType::VehicleType()
{

}

VehicleType:: VehicleType(long long int price,int model,int engineSize,string color,string vehicle_name,string fuelType,long long int price_sold)
{
  this->price=price;
  this->price_sold=price_sold;
  this->model=model;
  this->engineSize=engineSize;
  this->color=color;
  this->vehicle_name=vehicle_name;
  this->fuelType=fuelType;
}

long long int VehicleType::getprice()const
{
  return price;
}

long long int VehicleType::getprice_sold()const
{
  return price_sold;
}

int VehicleType::getmodel()const
{
  return model;
}

int VehicleType::getengineSize()const
{
  return engineSize;
}

string VehicleType::getcolor()const
{
  return color;
}

string VehicleType::getvehiclename()const
{
  return vehicle_name;
}

string VehicleType::getfuelType()const
{
  return fuelType;
}

void VehicleType::setvehiclename(string vehicle_name)
{
  this->vehicle_name=vehicle_name;
}

void VehicleType::setprice(long long int price)
{
  this->price=price;
}

void VehicleType::setprice_sold(long long int price_sold)
{
  this->price_sold=price_sold;
}

void VehicleType::setmodel(int model)
{
  this->model=model;
}

void VehicleType::setengineSize(int engineSize)
{
  this->engineSize=engineSize;
}

void VehicleType::setcolor(string color)
{
  this->color=color;
}

void VehicleType::setfuelType(string fuelType)
{
  this->fuelType=fuelType;
}

int VehicleType:: increment()
{
 count++;
 return count;
}