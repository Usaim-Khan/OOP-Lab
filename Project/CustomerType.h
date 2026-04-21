#ifndef CUSTOMERTYPE_H
#define CUSTOMERTYPE_H
#include <string>
using namespace std;
class CustomerType
{
private:
string customer_name;
string contact;
string CNIC;

public:
CustomerType();
CustomerType(string customer_name,string contact,string CNIC);
void setcustomer_name(string customer_name);
void setcontact(string contact);
void setCNIC(string CNIC);
string getcustomer_name()const;
string getcontact()const;
string getCNIC()const;
};
#endif