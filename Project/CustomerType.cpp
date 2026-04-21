#include<iostream>
#include<string>
#include"CustomerType.h"
using namespace std;

CustomerType::CustomerType()
{

}

CustomerType::CustomerType(string customer_name,string contact,string CNIC)
{
    this->customer_name=customer_name;
    this->contact=contact;
    this->CNIC=CNIC;
}

void CustomerType:: setcustomer_name(string customer_name)
{
  this->customer_name=customer_name;
}

void CustomerType:: setcontact(string contact)
{
  this->contact=contact;
}

void CustomerType:: setCNIC(string CNIC)
{
  this->CNIC=CNIC;
}

string CustomerType:: getcustomer_name()const
{
    return customer_name;
}

string CustomerType:: getcontact()const
{
    return contact;
}

string CustomerType:: getCNIC()const
{
    return CNIC;
}