#include <iostream>
#include <string>
#include <vector>
#include "TruckType.h"
using namespace std;


ostream& operator<<(ostream& c, const vector<TruckType>& trucks)
{
    c<<"_____________________________________________________"<<endl<<endl;
    c << "----------SALES RECEIPT----------" << endl;

    for (int i=0;i<trucks.size();i++) 
    {
        c << "Truck name: " << trucks[i].getvehiclename() <<endl <<endl;
        c << "Truck model: " << trucks[i].getmodel() <<endl <<endl;
        c << "Truck color: " << trucks[i].getcolor() <<endl << endl;
        c << "Owner name: "<<trucks[i].C3.getcustomer_name()<<endl<<endl;
        c << "Owner number: " << trucks[i].C3.getcontact() << endl << endl;
        c << "Owner NIC: "<<trucks[i].C3.getCNIC()<<endl<<endl;
        c << "Car price: "<<trucks[i].getprice_sold()<<endl<<endl;
    }
    return c;
  }

istream& operator>>(istream& c, vector<TruckType>& trucks)
{
       string vname, vcolor, vfuel,cname,con,cnic;
       int cmodel, vengine,ccapacity;
       long long int cprice,cprice_sold;

      cout << "Enter truck name: ";
      getline(c >> ws, vname);

      cout << "Enter turkc model: ";
      c >> cmodel;

      cout << "Enter truck color: ";
      getline(c >> ws, vcolor);

      cout << "Enter car number of seats: ";
      c >> ccapacity;
      
      cout << "Enter truck engine size: ";
      c >> vengine;
      
      cout << "Enter truck fuel type: ";
      getline(c >> ws, vfuel);
      

      cout << "Enter truck price: ";
      c >> cprice;

      TruckType add(cprice,cmodel,vengine,vcolor,vname,vfuel,cprice_sold,cname,con,cnic,ccapacity);
      trucks.push_back(add);

      return c;
}

TruckType::TruckType()
{

}

TruckType:: TruckType(long long int price,int model,int engineSize,string color,string vehicle_name,string fuelType,long long int price_sold,string customer_name,string contact,string CNIC,int weight_capacity):VehicleType(price,model,engineSize,color, vehicle_name, fuelType, price_sold), C3( customer_name, contact, CNIC)
{
 this->weight_capacity=weight_capacity;
}

int TruckType::getweightcapacity()const
{
 return weight_capacity;
}

void TruckType:: setweightcapacity(int weight_capacity)
{
  this->weight_capacity = weight_capacity;
}

void TruckType::add_details()
{
  int num;
    cout << "How many truck do you want to add: ";
    cin >> num;

    for (int i = 0; i < num; i++) 
    {
      cin>>truck;
      cout<<"_____________________________________________________"<<endl;
      cout<<"Truck has been added to you showroom."<<endl;
      cout<<"_____________________________________________________"<<endl;
    }

}

void TruckType:: printdata(int i)const
{
     
      cout<<"_____________________________________________________"<<endl;
      cout<<i+1<<"- Truck name: "<<truck[i].getvehiclename()<<endl;
      cout<<i+1<<"- Truck model: "<<truck[i].getmodel()<<endl;
      cout<<i+1<<"- Truck color: "<<truck[i].getcolor()<<endl;
      cout<<i+1<<"- weight capacity of a Truck: "<<truck[i].getweightcapacity()<<endl;
      cout<<i+1<<"- Truck engine size: "<<truck[i].getengineSize()<<endl;
      cout<<i+1<<"- Truck fuel type: "<<truck[i].getfuelType()<<endl;
      cout<<i+1<<"- Truck price: "<<truck[i].getprice()<<endl;
      
}

void TruckType::Sale_details()
{
 int num,count=0;
 string cname,choice,cnumber,cnic;
 long long int sold_price;

 string search_name;
 int search_price;

 cout<<"Enter truck name to sale: ";
 getline(cin>>ws,search_name);

 for (int i=0;i<truck.size();i++)
  {
    if (truck[i].getvehiclename()==search_name )
     {
      count++;
      printdata(i);
     }
  }

  if (count==0)
   {
    cout<<"No truck available regarding your search. "<<endl;
   }

   if(count!=0)
   {
  cout<<endl;
  cout<<"_____________________________________________________"<<endl;

  cout<<"Which truck number do you want to remove: ";
  cin>>num;

 cout<<"_____Owner Details_____"<<endl;

 cout<<"Enter owner name: ";
 getline(cin>>ws,cname);
 C3.setcustomer_name(cname);

 cout<<"Enter owner contact number: ";
 getline(cin>>ws,cnumber);
 C3.setcontact(cnumber);

 cout<<"Enter owner CNIC number: ";
 getline(cin>>ws,cnic);
 C3.setCNIC(cnic);

 cout<<"Enter price at which truck has been sold: ";
 cin>>sold_price;
 setprice_sold(sold_price);

  truck_sold.push_back(TruckType(truck[num-1].getprice(),truck[num-1].getmodel(),truck[num-1].getengineSize(),truck[num-1].getcolor(),truck[num-1].getvehiclename(),truck[num-1].getfuelType(),getprice_sold(),cname,cnumber,cnic,truck[num-1].getweightcapacity()));

  truck.erase(truck.begin() + num-1);

  cout<<"Do you want to print the sale recipts: ";
  getline(cin>>ws,choice);

  if (choice=="yes" || choice=="y")
  {
    cout<<truck_sold;
  }

  else if (choice=="no" || choice=="n")
  {
    cout<<"Have a nice day..."<<endl;
  }
   }  
}

void TruckType::Search()
{
 string search_name;
 int search_price;

 cout<<"Enter truck name to search: ";
 getline(cin>>ws,search_name);

 for (int i=0;i<truck.size();i++)
  {
    if (truck[i].getvehiclename()==search_name)
     {
      cout<<"_____________________________________________________"<<endl;
      cout<<i+1<<"- truck name: "<<truck[i].getvehiclename()<<endl;
      cout<<i+1<<"- truck model: "<<truck[i].getmodel()<<endl;
      cout<<i+1<<"- truck color: "<<truck[i].getcolor()<<endl;
      cout<<i+1<<"- Weight Capacity of  Truck: "<<truck[i].getweightcapacity()<<endl;
      cout<<i+1<<"- truck engine size: "<<truck[i].getengineSize()<<endl;
      cout<<i+1<<"- truck fuel type: "<<truck[i].getfuelType()<<endl;
      cout<<i+1<<"- truck price: "<<truck[i].getprice()<<endl;
      cout<<"_____________________________________________________"<<endl;
     }
    else if(truck[i].getvehiclename()==search_name)
    {
      cout<<"No truck available"<<endl;
      break;
    } 
  }
}

void TruckType::Account()
{  
  string truck_account;
   int count=0,num;
   

   cout<<"1- Check truck account details."<<endl;
   cout<<"2- Total truck sold."<<endl;
   cout<<"Enter an option: ";
   cin>>num;
   cout<<"_____________________________________________________"<<endl<<endl;

  if (num==1)
  {

   cout << "Enter a truck name to check its account details: ";
    getline(cin >>ws, truck_account);
    cout<<"_____________________________________________________"<<endl<<endl;

    for (int i=0;i<truck_sold.size();i++) {
        if (truck_sold[i].getvehiclename() == truck_account) 
        {
            count++;

            cout << "Truck Name: " << truck_sold[i].getvehiclename() <<endl;
            cout<<"_____________________________________________________"<<endl;
            cout << "Price at which is sold: " << truck_sold[i].getprice_sold() <<endl;
            cout<<"_____________________________________________________"<<endl;

            if(truck_sold[i].getprice_sold()-truck_sold[i].getprice()>0)
             {
                cout<<"Your profit in this truck is of RS. "<<truck_sold[i].getprice_sold()-truck_sold[i].getprice()<<endl;
             }
            else if(truck_sold[i].getprice_sold()-truck_sold[i].getprice()<0)
            {
                 cout<<"Your loss in this truck is of RS. "<<truck_sold[i].getprice_sold()-truck_sold[i].getprice()<<endl;
            } 

            
        }
    }

    if (count==0) 
    {
        cout << "No account details found for this truck."<<endl;
    }
  }

  else if (num==2)
   {
    int num1=0;
     for(int i=0;i<truck_sold.size();i++)
     {
      num1=increment();
     }

     cout<<num1<<" trucks have been sold."<<endl;
   } 
}

